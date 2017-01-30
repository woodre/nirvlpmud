#pragma strong_types            // Coogan, 24-Mar-99

#include <kernel.h>
#include <assert.h>             // Alfe 2002-Feb-13
#include <describe.h>
#include <grammar.h>
#include <prop/player.h>
#include <wizlevels.h>
#include <event.h>
#include <message.h>
#include <tongue.h>
#include <closures.h>
#include <gender.h>             // Chameloid, 21-Apr-96
#include <timed_flag.h>         // Chameloid, 16-May-96
#include <time_units.h>
#include <published/peerage.h>  // added published, Coogan, 10-Nov-98
#include <termcol.h>            // Coogan, 25-Feb-00, 25-Nov-2003

inherit ACCESS;
inherit "basic/tools/time";     // Chameloid, 28-Oct-97
inherit "basic/name";           // Alfe 98-Apr-24
inherit "basic/create";

#if 0  // Alfe 98-Apr-24
#define INDENT(X) break_string(X,76,2,1)
#else
#define INDENT(X) break_string(X,0,2,1)
#endif
#define WARN_IDLE_TIME (5*60)
#define TELL_COST 5
#define TELL_RABATT 2
#define SHOUT_COST 30

#define SPACE_BEEPS 240 // Chameloid, 01-May-96

// Ugh Jul-5-1995
void create() {
  set_global_listening_event("message",1);
  listen_event("message", EPRIO_CANCEL);  // Coogan, 21-Jan-02
  listen_event("message", EPRIO_HANDLE);
}

string get_name (object ob) {
  if (this_player()->query_level() >= WL_APPRENTICE)
    return capitalize(ob->query_vis_name() || ob->query_name());
  return ob->query_name();
}

static private object *real_receiving,*possible_receiving;

status query_prevent_shadow() { return 1; }

private string my_describe(mixed what,mixed article,status full,int count,
                           status possessive_s) {
  if (objectp(what) && previous_object()->query_level()>=WL_APPRENTICE &&
      query_once_interactive(what) &&
      what->query_name() !=             what->query_vis_name() &&
      what->query_name() != "absent " + what->query_vis_name())
    return describe(what,article,full,count,possessive_s)+
           " ["+what->query_vis_name()+"]";
  return describe(what,article,full,count,possessive_s);
}


private status free_tell_to(object pl) {  // Carador, Apr-96
  return (environment(pl) == environment(this_player()) ||
          pl->test_flag(318));  // tell free to players who have set this flag
}

private status generally_free(object pl) {  // Chameloid, 15-Oct-96
#if 0
#  ifdef TUBMUD
  return is_wizard(pl) || PEERAGE_IS_PEER(pl) ||
         pl->query_level() >= PL_MIN_HLP_LEVEL;
#  else
  return is_wizard(pl);
#  endif
#else
// free tells for all, Carador, Nov-96
  return 1;
#endif
}

private status free_tell(object pl) {  // Carador, Apr-96, Chameloid, 15-Oct-96
  return generally_free(pl) || pl->query_real_name() == "webster";
}

string ungarble_message(object receiver, mapping msgargs, varargs mixed *args) {
  string tongue;
  string gmsg;
  object agent;

#if 1  // if *args is given, then use it! Coogan, 18-Dec-2003
  agent  = (sizeof(args) > 2 && args[2]) || (msgargs && msgargs[E_AGENT]);
  tongue = (sizeof(args) > 1 && args[1]) || (msgargs && msgargs[E_TONGUE]);
  gmsg   = (sizeof(args) > 0 && args[0]) || (msgargs && msgargs[E_MSG,1]);
#else
  gmsg   = msgargs && msgargs[E_MSG,1]  || args[0];
  tongue = msgargs && msgargs[E_TONGUE] || args[1];
  agent  = msgargs && msgargs[E_AGENT]  || args[2];
#endif

  switch (tongue) {
  case TONGUE_COMMON:
  case TONGUE_ORCISH:
  case TONGUE_LIZTONGUE:
    return LIB_TONGUE->ungarble_message(tongue, gmsg, agent, receiver);
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 24-Mar-2011
}

private void improve_skill(object agent, string tongue, int length) {
  string skillpath;
  int sk;

  if (!tongue) {
    if (agent->query_npc()) {
      log_file("TONGUE", ctime() + ": Tongue needed: " + load_name(agent) +
                        " (" + agent->query_create_room() + "), race " +
                        (agent->query_race() || "NO RACE") + "\n");
      tongue = TONGUE_COMMON;
    } else
      raise_error("Bad arg 2 to improve_skill(), no tongue given!\n");
  }
  skillpath = LIB_TONGUE->get_skillpath_of_tongue(tongue);

  sk = agent->query_skill(skillpath);
  if (length > 100)
    length = 100;
  if (random(sk) < 3)
    agent->improve_skill(skillpath, 1, length);
  if (sk < 50)
    switch (tongue) {
    case TONGUE_ORCISH:
      if (tongue != LIB_RACE->query_default_tongue(agent->query_race()))
        call_out(#'tell_object, 0, agent, "Your throat hurts.\n");
      break;
    case TONGUE_LIZTONGUE:
      if (tongue != LIB_RACE->query_default_tongue(agent->query_race()))
        call_out(#'tell_object, 0, agent, "Your tongue feels weird.\n");
      break;
    case TONGUE_COMMON:
      break;
    }
  return;
}

status do_action(string verb, mapping args) {
  mixed temp, temp2, error, receiving, names, recipients;
  mixed h, t, tmp, errmsg, beeped, again; // Chameloid, 01-May-96
  mixed filtered;
  mapping event;
  string text, tongue, garbled_msg;
  int i;
  status echo, expanded, disguised;

  echo = this_player()->query_property(P_ECHO);
  text = args[G_TEXT] ? args[G_TEXT] : "";

  event = ([ E_TYPE: "message"; 0, // Coogan, 19-Dec-98, made it width 2
             E_MSG : text     ; 0,
             E_AGENT: this_player(); this_player()->query_name(),
#if 0  // Coogan, 21-Jan-02
             E_TONGUE: (verb != "tell" && verb[0..4] != "shout" ?
                      args[G_TONGUE] || this_player()->query_tongue() :
                      TONGUE_DEFAULT); 0
#else
             E_TONGUE: (verb == "hiss" ? "liztongue"
                        :args[G_TONGUE] || this_player()->query_tongue()); 0
#endif
          ]);
  switch (verb) {
  case "beep_player": // Chameloid, 01-May-96
    errmsg=beeped=again=({});
    if (!sizeof(h=m_indices(args[G_AMBIG_LIVINGS]))) // Chameloid, 26-Oct-96
      return 0;
#if 0 // 'all' isn't parsed anymore, Chameloid, 26-Oct-96
    else if ((tmp=args[G_AMBIG_LIVINGS,1]) && member(tmp,"all"))

      // Since players tended to abuse this feature, I disabled it.
      // Please do not implement it again, Chameloid, 15-Oct-96

      errmsg+=({"The ability of beeping all logged on people has been "
                "disabled.\n"});
#endif
    else
      for (i=sizeof(h); i-->0; ) {
        if (!tmp=args[G_AMBIG_LIVINGS][h[i]])
          errmsg += ({ "There is no one named "+h[i]+" in the mud.\n" });
        else if (pointerp(tmp))
          errmsg += ({ ("There are "+to_string(sizeof(tmp))+
                        " players beginning with '"+h[i]+"': "+
                        make_list(map_objects(tmp,"query_vis_name"))+".\n") });
        // the use of query_vis_name() seems to be ok in this case though it
        // gives some information about frogs etc.  Alfe 98-Apr-23
        else {
          if (!interactive(tmp) ||
              (!tmp->short() && tmp!=this_player() &&
               this_player()->query_level()<WL_APPRENTICE)) {
            if (!query_once_interactive(tmp))
              errmsg += ({ capitalize(tmp->query_name()),
                           " is not a player.\n" });
            else
              errmsg += ({ tmp->query_vis_name(),
                           (tmp->query_plural()? " are": " is"),
                           " petrified at the moment.\n" });
          }
          else if (tmp->query_property(P_DONT_BEEP))
            errmsg += ({ message2string(({ M_CAPITALIZE,tmp,M_VERB,"do",tmp,
                                           ("n't want to be beeped"
                                            " at the moment.\n") })) });
          else {
            if (test_timed_flag(t=this_player()->query_real_name()+"_beeped_"+
                                tmp->query_real_name()))
              again += ({ tmp });
            else
              beeped += ({ tmp });
            set_timed_flag(t, SPACE_BEEPS, TF_OVERRIDE);
            // we use a timed flag (callout) to determine whether someone
            // may be "disturbed" with an accoustic signal again
            // Chameloid, 16-May-96
          }
        }
      }
    if (sizeof(errmsg))
      map(errmsg,#'write);
    h = sizeof(beeped);
    t = sizeof(again);
    if (h||t) {
      if (!generally_free(this_player())) { // Chameloid, 15-Oct-96
        temp = h + t;
        temp = temp && (TELL_COST+(temp-1)*(TELL_COST-TELL_RABATT));
        // changed query_spell_points() to query_sp(), Coogan, 09-Jan-99
        if (this_player()->query_sp() < temp)
          return notify_fail("You are low on power.\n"), 0;
        this_player()->restore_spell_points(-temp);
      }
      send_message(({ M_TARGETS,({ this_player() })+beeped+again,
                      M_DESCRIBE_FUNCTION,#'my_describe,M_PL_THE })+
                   (h? ({ M_PL_VERB,"beep",M_OBJECT,beeped,M_ADVERBS }) :
                    ({}))+
                   (h&&t? ({ " and " }) : ({}))+
                   (t? ((h? ({}) : ({ M_ADVERBS })) +
                        ({ M_PL_VERB,"try"," to beep ",M_OBJECT,again,
                           " again" })) : ({}))+
                   ({ ".",M_TARGETS,beeped,"\a\a\a" }));
    }
    return 1;
  case "speak_tongue":
    if (this_player()->set_tongue(args[G_TONGUE]))
      write("Ok, you now speak in "+capitalize(args[G_TONGUE])+".\n");
    else
      return notify_fail("That tongue is unknown to you.\n"), 1;
    return 1;
  case "away":
    if (query_verb()=="away?" && args[G_TEXT] == "?")
      return notify_fail("Syntax: away? <player>\n");
    if (!generally_free(this_player())) { // Chameloid, 15-Oct-96
      if (this_player()->query_sp()<1)
        return notify_fail("You are low on power.\n"), 0;
      this_player()->restore_spell_points(-15);
    }
    h = ({ M_PL_THE, M_PL_VERB, "mark", M_PL_OBJECTIVE, M_ADVERBS,
           " as being absent with the following message: "+args[G_TEXT] });
    if (this_player()->query_property(P_ECHO))
      send_message(h);
    else {
      send_message(({ M_SAY }) + h);
      write("Ok.\n");
    }
    this_player()->set_property(P_AWAY,({ time()+10,args[G_TEXT] }));
    return 1;
  case "away?": // Chameloid, 28-Oct-97
    if (!generally_free(this_player())) {
      if (this_player()->query_sp() < 1)
        return notify_fail("You are low on power.\n"), 0;
      this_player()->restore_spell_points(-15);
    }
    // To cover those freshly LD - Dozy
    if(!interactive(args[G_ANY_LIVING])) {
#if 1  /* This is the desired way of reacting because a player shall not
        * have means to distinguish an invisible wizard from a linkdead
        * wizard.  In other words: output about invis wizards shall _always_
        * be the same as for linkdead wizards.  By simply returning 0 here
        * we achieve this.  Both commands are misunderstood then in an equal
        * fashion ("You mark yourself as being absent with the following
        * message: ? afle").  Alfe 2004-Oct-4
        */
      return 0;
#else
      send_message( ({ M_WRITE, args[G_ANY_LIVING]->query_vis_name(),
	" is linkdead." }) );
      return 1;
#endif
    }
    if ((h=query_idle(args[G_ANY_LIVING])) < ONE_MINUTE)
      h = ({ M_WRITE,M_THE,args[G_ANY_LIVING],
             M_VERB,"are",args[G_ANY_LIVING]," not idle and " });
    else
      h = ({ M_WRITE,M_THE,args[G_ANY_LIVING],
             M_VERB,"are",args[G_ANY_LIVING],
             (" idle for " +
              (h>ONE_DAY? describe("one day",0,0,h/ONE_DAY) :
               (h>ONE_HOUR? describe("one hour",0,0,h/ONE_HOUR) :
                describe("one minute",0,0,h/ONE_MINUTE))) + " and ") });
    h += ({ M_VERB,"have",args[G_ANY_LIVING]});
    if (!(temp=args[G_ANY_LIVING]->query_away()))
      h += ({ " not been marked as being absent." });
    else
      h += ({ (" been marked as being absent with the following message: "+
               temp) });
    send_message(h);
    return 1;

  case "tell":
    this_player()->clear_commandline();
    receiving = ({});
    error = ([ "result": "", "none": ({}), "more": ({}) ]);
    temp = m_indices(args[G_AMBIG_LIVINGS]);
    expanded = args[G_AMBIG_LIVINGS,1];
    unguarded(1,#'call_other,
              ({ this_player(),"set_last_command",
                 "tell "+implode(m_indices(args[G_AMBIG_LIVINGS]),
                                 ",") +
#if 1  // Coogan, 18-Feb-02
                 (args[G_ADVERBS] ? args[G_ADVERBS,1] + " " : "") +
#endif
                 " %s" }));
    for (i=sizeof(temp); i--; ) {
      temp2 = args[G_AMBIG_LIVINGS][temp[i]];
      if (!temp2) {
        error["none"] += ({ temp[i] });
        // if expanded == 1, we're getting told whom we are telling and
        // whom not
        expanded = 1;
      }
      else if (pointerp(temp2))
        error["more"] += ({ temp[i] });
      else {
        receiving += ({ temp2 });
        if (!expanded &&
            strlen(temp2->query_real_name() ||
                   temp2->query_name() || "") > strlen(temp[i]))
          expanded = 1;
      }
    }
    // don't tell if person not identified Ugh Jun-29-1995
    if (sizeof(temp=error["more"])) {
      for (i=0; i<sizeof(temp); i++) {
        temp2 = map_objects(args[G_AMBIG_LIVINGS][temp[i]], "query_vis_name");
        error["result"] += INDENT("There are " + sizeof (temp2) +
                                  " players beginning with '" +
                                  temp[i] + "': " + make_list(temp2) + ".\n");
      }
      write(error["result"]);
      return 1;
    }
    temp2 = get_name(this_player());
    // Ugh Jul-3-1995
    receiving = m_indices(mkmapping(receiving));
    possible_receiving = receiving[0..];
    real_receiving = ({});
    text = LIB_CNTL_SEQUENCES->quote_for_terminal_colour(text);
    garbled_msg = LIB_TONGUE->garble_message(
                                 args[G_TONGUE]||this_player()->query_tongue(),
                                 text,
                                 this_player());
    for (i=sizeof(receiving); i-->0; )
      send_event("message",
      // added next line and made it of width 2, Coogan, 19-Dec-98
                 ([ E_TYPE: "message";         "tell",
                    E_AGENT: this_player();    this_player()->query_name(),
                    E_TARGET: receiving[i..i]; 0,
                    E_RECIPIENTS: receiving;   sizeof(receiving),
                    E_MSG_TYPE: "tell";        0,
                    E_TONGUE: args[G_TONGUE] || this_player()->query_tongue();0,
                    // if there is an npc getting this message,
                    // it can't be that important
                    E_MSG: receiving[i]->query_npc() && text; 0 ]),
                 (environment(receiving[i])==environment(this_player())?
                  ({ environment(this_player()) }) :
                  ({ environment(receiving[i]),environment(this_player()) })));
    if ((filtered=args[G_AMBIG_LIVINGS,1]) &&
        (filtered=filtered["filtered_invisible_wizards"]))
      send_message(({ M_TARGETS,m_indices(filtered),
                      "(As you are invisible, you do not receive ",
                      M_OBJECT,M_PL," who ",
                      M_PL_VERB,"try"," to tell ",
                      m_indices(filtered +
                                mkmapping(m_values(args[G_AMBIG_LIVINGS]))),
                      (args[G_ADVERBS] ?
                         args[G_ADVERBS,1]+" " : ""), // Coogan, 18-Feb-02
                      M_ADD, (: ((($1->query_tongue()==$3 && $4 == 1) ||
                                  (!LIB_TONGUE->can_speak($1, $3)))
                                ? "" : " in " + $3) :),
                           ({ args[G_TONGUE]||this_player()->query_tongue(),
                              sizeof(receiving) }),
                      ": ",
                      M_ADD, #'ungarble_message,
                        ({ garbled_msg,
                           args[G_TONGUE] || this_player()->query_tongue(),
                           this_player() }),
                      ")" }));
    receiving = real_receiving;
    names = receiving[0..]; // copy because receiving might be changed later
    if (sizeof (receiving)) {
    //  int t;
      for (i=sizeof(receiving); i-->0; ) {
        if (query_once_interactive(receiving[i])) {
          string away_message;
          if (!interactive(receiving[i])) {
            // Ugh Jun-29-1995
            error["none"] += ({ to_real_name(receiving[i]->query_vis_name() ||
                                             receiving[i]->query_name()) });
            receiving[i..i] = ({});
            names[i..i] = ({});
            expanded = 1;
            continue;
          }
          else if (receiving!=this_player() &&
                   (away_message=receiving[i]->query_away()))
            error["result"] += (receiving[i]->query_vis_name()+" "+
                                (receiving[i]->query_plural()?
                                 "have":"has")+ // Chameloid, 28-Oct-97
                                " been marked as being absent for "+
                                nice_time(query_idle(receiving[i]))+
                                // Chameloid, 28-Oct-97
                                " with the following message: "+
                                away_message+"\n");
          // Ugh (24-Apr-1995)
          else if (receiving[i]->query_no_output())
            error["result"] += (receiving[i]->query_vis_name()+
                                " is reading or editing something at"
                                " the moment and is not hearing you.\n");
          else if ((t=query_idle(receiving[i])) > WARN_IDLE_TIME)
            error["result"] += (receiving[i]->query_vis_name()+
                                " hasn't done anything for "+
                                ((t/=60) > 59?
                                 describe("1 hour",0,0,t/60) +" and " : "") +
                                describe("1 minute",0,0,t%60)+" now.\n");
        }
        names[i] = ((receiving[i] == this_player())?
                    ({ "yourself",receiving[i]->query_objective()+"self" }) :
                    ({ "you",get_name(receiving[i]) }));
      }
    }
    if (sizeof(receiving)) {
      if (!free_tell(this_player())) {
#if 0
        temp = (sizeof(receiving)-
                sizeof(filter(receiving,#'present,
                                    environment(this_player()))));
#else
// Carador, to make tells to Webster free, too. Apr-96
        temp = (sizeof(receiving)-
                sizeof(filter(receiving, #'free_tell_to)));
#endif
        temp = temp && (TELL_COST+(temp-1)*(TELL_COST-TELL_RABATT));
        if (temp && this_player()->query_sp() < 1) {
          write("You are low on power.\n");
          return 1;
        }
        this_player()->restore_spell_points(-temp);
      }
      temp = receiving - ({ this_player() });
      disguised = (query_once_interactive(this_player()) &&
                   this_player()->query_name() !=
                   this_player()->query_vis_name());
      if (echo)
        temp += ({ this_player() });
      else
        message(({ (expanded?
                    ({ M_WRITE,"Told to ",M_OBJECT,receiving,"." }) :
                    ({ M_WRITE,(this_player()->short()? "Ok." :
                                "(Ok)") })) }));
#if 1  // Coogan, 14-Feb-02
      map(receiving,
          (: load_name($1) == "bin/tools/intermud_soul_d" &&
               $1->set_service("tell") :));
#endif
      send_message(({ M_DESCRIBE_FUNCTION,#'my_describe,
                      M_CNTL_SEQ,
#if 1  // Coogan, 19-Oct-01
                      M_APPLY, (: (TERMCOL_TELL":" +
                                  ($1 && to_real_name($1->query_name()))) :),
                      M_PL,
#else
                      TERMCOL_TELL,
#endif
                      M_PL_THE,
                      (args[G_ADVERBS]
                        ? " "+args[G_ADVERBS,1]+" " : " "), // Coogan, 18-Feb-02
                      M_PL_VERB, "tell",
                      M_THE,  // Alfe 2006-Mar-29
                      // ^^^ mostly to prevent "You tell absent Alfe: blah",
                      // but I also deem "tell" a command which suggests that
                      // the user already knows the recipient and is kind of
                      // aware of its presence, so the article "the" is more
                      // appropriate.  Even if I tell an orc something, after
                      // I typed the name ("orc") I am not surprised about
                      // reaching the orc in any way, so the article should
                      // be "the".
                      M_OBJECT,receiving,M_ADVERBS,
                      // added M_ADD, Coogan, 21-Jan-01
                      M_ADD, (: ((($1->query_tongue() == $3) ||
                                  (!LIB_TONGUE->can_speak($1, $3)))
                                 ? "" : " in " + $3) :),
                           ({ args[G_TONGUE]||this_player()->query_tongue() }),
                      ": ",
#if 0  // Coogan, 21-Jan-02
                      LIB_CNTL_SEQUENCES->quote_for_terminal_colour(text),
#else
                      M_ADD, #'ungarble_message,
                        ({ garbled_msg,
                           args[G_TONGUE] || this_player()->query_tongue(),
                           this_player() }),
#endif
                      M_CNTL_SEQ, TERMCOL_NORMAL,
                       }),
                   0,mkmapping(temp));
#if 1  // Coogan, 22-Jan-02
      improve_skill(this_player(),
                    args[G_TONGUE] || this_player()->query_tongue(),
                    strlen(text));
#endif
    }
    else if (sizeof(error["none"]))
      error["result"] += INDENT("There is no one named "+
                                make_list(error["none"], 0, " or ")+
                                " in the mud.\n");
    else
      error["result"] = "Nothing told.\n";
    if (strlen(error["result"]))
      message(error["result"]);  // write(break_string()) => message()
                                 // Alfe 98-Apr-24
    return 1;
    break;
  case "shout":
  case "shout_pl":
  case "shout_wiz":
  case "shout_at":
    event[E_TYPE, 1] = "shout";  // Coogan, 19-Dec-98
    event[E_MSG_TYPE] = "shout";
    if (args[G_ANY_LIVING])
      event[E_RECIPIENTS] = recipients = ({ args[G_ANY_LIVING] });
    else if (args[G_ANY_LIVINGS])
      event[E_RECIPIENTS] = recipients = m_values(args[G_ANY_LIVINGS]);
    receiving = users();
    if (verb == "shout_pl") {
      receiving = filter(receiving,
                               lambda(({ 'ob }),
                                      ({ #'<,
                                         ({ #'call_other,
                                            'ob,
                                            "query_level" }),
                                         WL_APPRENTICE })));

      event[E_TO] = "players";
    }
    else if (verb == "shout_wiz") {
      receiving -= filter(receiving,
                                lambda(({ 'ob }),
                                       ({ (#'<),
                                          ({ (#'call_other),
                                             'ob,
                                             "query_level" }),
                                          WL_APPRENTICE })));
      event[E_TO] = "wizards";
    }

    if (event[E_TO] && this_player()->query_property(P_ECHO) &&
        member(receiving,this_player()) < 0)
      receiving += ({ this_player() });
      
    // added this_player() to the receivers array in order to get prompted
    // when having echo toggled on and shouting to a group of which you're
    // not a member, Chameloid, 31-Jan-97

    event += ([ E_TARGET : receiving; sizeof(receiving) ]); //Coogan, 19-Dec-98
    event[E_MESSAGES]=([ 0: (({
                                M_CNTL_SEQ,
#if 0  // Coogan, 19-Oct-01
                                TERMCOL_SHOUT,
#else
                                M_APPLY, (: (TERMCOL_SHOUT":" +
                                   ($1 && to_real_name($1->query_name()))) :),
                                M_ARG, E_AGENT,
#endif
                                M_DESCRIBE_FUNCTION,#'my_describe,
                                M_ARG,E_AGENT,
                                M_VERB,"shout",M_ARG,E_AGENT,M_ADVERBS,
                                // added M_ADD, Coogan, 21-Jan-01
                                M_ADD, (: ($1->query_tongue() == $2[E_TONGUE] ||
                                      !LIB_TONGUE->can_speak($1, $2[E_TONGUE]))
                                          ? "" : " in " + $2[E_TONGUE] :),
                                       ({ sizeof(receiving) }),
                             })+
                             (sizeof(recipients)
                              ? ({ " at ",M_THE,M_OBJECT,M_ARG,E_RECIPIENTS })
                              : ({ })) +
                             (event[E_TO]
                              ? ({ " (to all "+event[E_TO]+")" })
                              : ({ })) +
                             ({ ": ",
#if 0  // Coogan, 21-Jan-02
                                M_ARG,E_MSG,
#else
                                M_ADD, #'ungarble_message, ({ }),
#endif
                                M_CNTL_SEQ, TERMCOL_NORMAL
                                })) ]);
                       // added space after colon, Coogan, 24-Mar-99
    if (!this_player()->query_property(P_ECHO))
      event[E_MESSAGES] += ([ this_player(): ({ (this_player()->short()?
                                                 "Ok." : "(Ok)") }) ]);
    send_event("message", event,
               m_indices(mkmapping(map(receiving, #'environment))));
    break;
  case "ask_for":
  case "ask_about":
  case "ask_to":
  case "say":
  case "whisper":
  case "hiss":     // Coogan, 22-Jan-01
    this_player()->clear_commandline();
    event[E_TYPE] = "message";
    if (verb == "hiss") {  // Coogan, 22-Jan-02
      event[E_TYPE,1] = "say";
      event[E_MSG_TYPE] = "say";
    } else {
      event[E_TYPE,1] = verb;  // Coogan, 19-Dec-98
      event[E_MSG_TYPE] = verb;
    }
    if (verb == "say" && event[E_TONGUE] == TONGUE_LIZTONGUE)  // Coogan,
      verb = "hiss";                                           // 22-Jan-02
    if (args[G_LIVING])
      event[E_TARGET] = ({ args[G_LIVING] });
    else if (args[G_ALL_LIVINGS]) {
      args[G_ALL] = filter(args[G_ALL_LIVINGS], #'living);
      if (args[G_ALL_LIVINGS,1][1])
        event[E_TARGET] = args[G_ALL_LIVINGS][0..args[G_ALL_LIVINGS,1][1]-1];
      else
        event[E_TARGET] = args[G_ALL_LIVINGS];
    }
    else if ((verb == "say" || verb == "hiss") && !event[E_TARGET])
      event[E_TARGET] = ({});
    event[E_TARGET,1] = sizeof(event[E_TARGET]); // Coogan, 19-Dec-98
    switch (verb) {

    // added a lot of M_CNTL_SEQ in the next parts, Coogan, 25-Feb-00
    case "whisper":
      // added some unfinished parts in the following code: added the
      // name of the whisperer as 'argument' to the cntl-seq.  this is
      // not proper, because it should depend on E_AGENT instead of being
      // set fixedly.  Alfe 2001-Sep-29
      event[E_MESSAGES] = ([
        0: ({ M_CNTL_SEQ,
              M_APPLY, (: (TERMCOL_WHISPER":" +
                           ($1 && to_real_name($1->query_name()))) :),
              M_ARG, E_AGENT,
              M_THE,M_ARG,E_AGENT,
              M_VERB,"whisper",M_ARG,E_AGENT,
              " something", M_SPACE, M_ADVERBS," to ",
              M_THE,M_OBJECT, M_ARG, E_TARGET, ".",
              M_CNTL_SEQ, TERMCOL_NORMAL }) ]);
      if (this_player()->query_property(P_ECHO))
        event[E_MESSAGES] += ([
          this_player(): ({ M_CNTL_SEQ,
                            M_APPLY,
                            (: (TERMCOL_WHISPER":" +
                                ($1 && to_real_name($1->query_name()))) :), 
                            M_ARG, E_AGENT,
                            M_THE,M_ARG,E_AGENT,
                            M_VERB,"whisper",M_ARG,E_AGENT,
                            M_ADVERBS," to ",
                            M_THE,M_OBJECT,M_ARG,E_TARGET,
                            ": ",
#if 0  // Coogan, 21-Jan-02
                            M_ARG,E_MSG,
#else
                            M_ADD, #'ungarble_message, ({ }),
#endif
                            M_CNTL_SEQ, TERMCOL_NORMAL }) ]);
      else
        event[E_MESSAGES] += ([ this_player():
                                ({ (this_player()->query_short()?
                                    "Ok." : "(Ok)") }) ]);
      event[E_MESSAGES] +=
        ([ event[E_TARGET] - ({ this_player() }):
           ({ M_CNTL_SEQ,
              M_APPLY, (: (TERMCOL_WHISPER":" +
                           ($1 && to_real_name($1->query_name()))) :),
              M_ARG, E_AGENT,
              M_THE, M_ARG, E_AGENT, M_VERB, "whisper", M_ARG, E_AGENT,
              M_ADVERBS, " to ", M_THE, M_OBJECT, M_ARG, E_TARGET,
              // added M_ADD, Coogan, 21-Jan-01
              M_ADD, (: (($1->query_tongue() == $2[E_TONGUE] &&
                          $2[E_TARGET,1] == 1) ||
                         (!LIB_TONGUE->can_speak($1, $2[E_TONGUE])))
                        ? "" : " in " + $2[E_TONGUE] :), ({  }),
              ": ",
#if 0  // Coogan, 21-Jan-02
              M_ARG, E_MSG,
#else
              M_ADD, #'ungarble_message, ({ }),
#endif
              M_CNTL_SEQ, TERMCOL_NORMAL }) ]);
      break;
    case "ask_to":
    case "ask_about":
    case "ask_for":
      event[E_MESSAGES] = ([ 0: ({ M_THE, M_ARG, E_AGENT, M_ADVERBS,
                                   M_VERB, "ask", M_ARG, E_AGENT, M_THE,
                                   M_OBJECT, M_ARG, E_TARGET,
                                   // added M_ADD, Coogan, 21-Jan-01
                                   M_ADD,
                                     (: $1->query_tongue() == $2[E_TONGUE] ||
                                        !LIB_TONGUE->can_speak($1,$2[E_TONGUE])
                                     ? "" : " in " + $2[E_TONGUE] :), ({ }),
                                   (verb=="ask_to"? " to " :
                                    (verb=="ask_for"? " for " : " about ")),
#if 0  // Coogan, 21-Jan-02
                                   M_ARG, E_MSG,
#else
                                   M_ADD, #'ungarble_message, ({ }),
#endif
                                   "." }) ]);
                     // added M_THE for the target, Coogan, 14-Nov-99
      if (!this_player()->query_property(P_ECHO))
        event[E_MESSAGES] += ([ this_player(): ({ (this_player()->short()?
                                                   "Ok." : "(Ok)") }) ]);
      break;
    case "say":
      event[E_MESSAGES] =
        ([ 0: (({ M_CNTL_SEQ,
#if 0  // Coogan, 19-Oct-01
                  TERMCOL_SAY, 
#else
                  M_APPLY, (: (TERMCOL_SAY":" +
                               ($1 && to_real_name($1->query_name()))) :),
                  M_ARG, E_AGENT,
#endif
                  M_THE,M_ARG,E_AGENT,
                  M_VERB,"say",M_ARG,E_AGENT,M_ADVERBS,
                  // added M_ADD, Coogan, 21-Jan-01
                  M_ADD, (: (($1->query_tongue() == $2[E_TONGUE] ||
                              !LIB_TONGUE->can_speak($1,$2[E_TONGUE]))?
                             "" : " in " + $2[E_TONGUE]) :), ({ }) })+
               (sizeof(event[E_TARGET])?
                ({ " to ",M_THE,M_OBJECT,event[E_TARGET] }) :
                ({}))+
               ({ ": ",
#if 0  // Coogan, 21-Jan-02
                  M_ARG,E_MSG,
#else
                  M_ADD, #'ungarble_message, ({ }),
#endif
                  M_CNTL_SEQ, TERMCOL_NORMAL })) ]);
      if (!this_player()->query_property(P_ECHO))
        event[E_MESSAGES] += ([ this_player(): ({ (this_player()->short()?
                                                   "Ok." : "(Ok)") }) ]);
      break;

    case "hiss":
      event[E_MESSAGES] = ([ 0: (({ M_CNTL_SEQ,
                                    M_APPLY, (: (TERMCOL_SAY":" +
                                     ($1 && to_real_name($1->query_name()))) :),
                                    M_ARG, E_AGENT,
                                    M_THE,M_ARG,E_AGENT,
                                    M_VERB,"hiss",M_ARG,E_AGENT,M_ADVERBS }) +
                                 (sizeof(event[E_TARGET])?
                                  ({ " to ",M_THE,M_OBJECT,event[E_TARGET] }) :
                                  ({}))+
                                 ({ ": ",
                                    M_ADD, #'ungarble_message, ({ }),
                                    M_CNTL_SEQ, TERMCOL_NORMAL })) ]);
      if (!this_player()->query_property(P_ECHO))
        event[E_MESSAGES] += ([ this_player(): ({ (this_player()->short()?
                                                   "Ok." : "(Ok)") }) ]);
      break;
    }
    send_event("message", event, ({environment(this_player())}));
    break;

  case "emote":
    temp = all_inventory(environment(this_player()));
    // normally only the interactives should receive emotes:
    temp = filter(temp,#'interactive);
#if 1  // Coogan, 24-Mar-99
    if (strstr(text, "'s ") != 0 &&
        strstr(text, "' ") != 0)
      text = " " + text;
#endif
    if (echo)
      temp = ([ temp: ({
#if 1  // Coogan, 27-Jan-2003
                         M_CNTL_SEQ,
                         M_APPLY, (: (TERMCOL_EMOTE":" +
                                ($1 && to_real_name($1->query_name()))) :),
                         M_ARG, E_AGENT,
#endif
                         M_THE, M_PL_DESCRIBE, M_ARG, E_MSG,
#if 1  // Coogan, 27-Jan-2003
                         M_CNTL_SEQ, TERMCOL_NORMAL,
#endif
                         }) ]);
    else
      temp = ([ temp - ({ this_player() }) : ({
#if 1  // Coogan, 27-Jan-2003
                         M_CNTL_SEQ,
                         M_APPLY, (: (TERMCOL_EMOTE":" +
                                ($1 && to_real_name($1->query_name()))) :),
                         M_ARG, E_AGENT,
#endif
                         M_THE, M_PL_DESCRIBE, text,
#if 1  // Coogan, 27-Jan-2003
                         M_CNTL_SEQ, TERMCOL_NORMAL,
#endif
                         }),
                this_player()              : ({ "Ok." }) ]);
    send_event("message",  // made it of width 2, Coogan, 19-Dec-98
               ([ E_TYPE    : "message"; "emote",
                  E_MSG     : text; 0,
                  E_MESSAGES: temp; 0,
                  E_MSG_TYPE: "emote"; 0,
                  E_AGENT   : this_player(); this_player()->query_name(),
                  E_TONGUE  : this_player()->query_tongue(); 0 ]),
               ({ environment(this_player()) }));
    break;
  case "toggle_echo":
    if (echo) {
      write("Echo now turned off.\n");
      this_player()->remove_property(P_ECHO);
    }
    else {
      write("Echo now turned on.\n");
      this_player()->set_property(P_ECHO);
    }
    break;
  case "toggle_beep": // Chameloid, 16-Oct-96
    if (this_player()->query_property(P_DONT_BEEP)) {
      write("Now, everybody can beep you again.\n");
      this_player()->remove_property(P_DONT_BEEP);
    }
    else {
      write("Now, nobody can beep you anymore.\n");
      this_player()->set_property(P_DONT_BEEP);
    }
    break;
  default:
    return 0;
  }
  return 1;
}

void receive_event(mapping e, string type, int prio) {
  object who, *persons;
  string tmp, tail, visible, skillpath;
  mixed msg;
  status echo;
  int sk, sl;

  switch (prio) {
  case EPRIO_CANCEL:
    if (e[E_TYPE,1] == "emote")
      return;
    skillpath = LIB_TONGUE->get_skillpath_of_tongue(e[E_TONGUE]);
    assert(skillpath);  // Alfe 2002-Feb-13
    sk = e[E_AGENT]->query_modified_skill(skillpath);
    if (sk < 3) {
      send_message(({ M_TARGETS, M_ARG, E_AGENT,
                      "You try to speak something in ", M_ARG, E_TONGUE,
                      " but due to lacking knowledge you fail miserably." }),e);
      if (!interactive(e[E_AGENT])) {  // Coogan, 24-Jan-02
        log_file("TONGUE",
                 ctime() + ": " + object_name(e[E_AGENT]) + " couldn't speak "+
                 e[E_TONGUE] + (environment(e[E_AGENT])
                  ? " in " + object_name(environment(e[E_AGENT]))
                  : " (no env)") + "\n");
      }
      cancel_event();
    }
    return;

  case EPRIO_HANDLE:
    if (e[E_HANDLED])
      return;
#if 0  // Coogan, 22-Jan-02
    if (e[E_TONGUE] && e[E_TONGUE] == TONGUE_LIZTONGUE)
      return;
#endif
    e[E_HANDLED] = 1;  // Alfe 95-Jun-20
    if (e[E_MSG]) {  // Alfe 01-Feb-7
      e[E_MSG] = LIB_CNTL_SEQUENCES->quote_for_terminal_colour(e[E_MSG]);
      e[E_MSG,1] = LIB_TONGUE->garble_message(e[E_TONGUE],e[E_MSG],e[E_AGENT]);
    }
    who = e[E_AGENT];
    echo = who->query_property(P_ECHO);
    if (!sizeof(e[E_TARGET]))
      e[E_TARGET] = 0;
    visible = this_player()->short();
    switch (e[E_MSG_TYPE]) {
    case "tell":
      if (member(possible_receiving,e[E_TARGET][0]) < 0)
        break;
      if (e[E_MSG] && closurep(e[E_MSG]))   // && closurep added by Carador,
        funcall(e[E_MSG],e);                // Jan-96.
      else
        real_receiving += e[E_TARGET];
      break;
    case "say":
    case "whisper":
    case "ask_for":
    case "ask_about":
    case "ask_to":
    case "emote":
      map_messages(e[E_MESSAGES],e);
#if 1  // Coogan, 22-Jan-02
      improve_skill(e[E_AGENT], e[E_TONGUE] || e[E_AGENT]->query_tongue(),
                    strlen(e[E_MSG]));
#endif
      break;
    case "shout":
      persons = e[E_RECIPIENTS];
      if (e[E_TO] != "wizards" && /* one should always be able
                                     to shout to them */
          who->query_level() < WL_APPRENTICE) {
        if (who->query_ghost()) {
          tell_object(who, "You can't do that in your present state.\n");
          return;
        }
        else if (who->query_sp() < SHOUT_COST) {
          tell_object(who,"You are low on power.\n");
          return;
        }
        who->restore_spell_points(-SHOUT_COST);
      }
      map_messages(e[E_MESSAGES],e,e[E_TARGET]);
#if 1  // Coogan, 22-Jan-02
      improve_skill(e[E_AGENT], e[E_TONGUE], strlen(e[E_MSG]));
#endif
      return;
    }
  default:
    return;
  }
}

