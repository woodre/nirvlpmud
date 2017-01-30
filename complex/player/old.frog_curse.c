#include <filter.h>
#include <event.h>
#include <describe.h>
#include <wizlevels.h>
#include <kernel.h>
#include <message.h>
#include <filters.h>  // Coogan, 18-Aug-98

inherit "basic/create";

private static string *filters = ({ F_ID,
                                    F_NAME,
                                    F_SHORT,
                                    F_LONG,
                                    F_GENDER,   // Coogan, 07-Aug-2002
                                    F_MMIN,
                                    F_MMOUT,
                                    F_MIN,
                                    F_MOUT, 
                                    F_STR,
                                    F_NO_ARTICLE,
                                    F_TITLE,    // this three added by
                                    F_PRETITLE, // Coogan, 01-Feb-99
                                    F_AL_TITLE });
                                     
void create() {
  listen_event("feeling", -100);  // react on kissing
  listen_event("message", 100);
}

void receive_event(mapping e, string t, int p) {
  int i;
  switch (t) {
  case "message":
    if (e[E_AGENT] != environment())  // not for us?
      break;
    if (e[E_MSG_TYPE] == "shout" &&
        e[E_TO] != "wizards")
      e[E_MSG] = " Hriibit! Hrriiibit!";
    else if (e[E_MSG_TYPE] == "say")
      while ((i=member(e[E_MESSAGES][0], "say")) > 0)  // is after M_VERB
        e[E_MESSAGES][0][i] = "croak";
    break;
  case "feeling":
    if (e[E_FEELING] == "kiss" &&  // kissing?
        member(e[E_PERSONS], environment()) >= 0) {  // kissing us?
      // next checks by Coogan, 18-Aug-98
      // changed all call_out()s of 0 to 1 sec, Coogan, 19-Aug-98
      if (environment(e[E_AGENT]) != environment(environment())) {
        // the player tries a remote kiss and turns into a frog
        call_out(#'move_object, 1, clone_object(FROG_MARK), e[E_AGENT]);
      }
      else if (environment()->query_always_frog()) {
        call_out(#'move_object, 1, clone_object(FROG_MARK), e[E_AGENT]);
      }
      else {
        call_out(#'move_object, 1, this_object(), e[E_AGENT]);
        e[E_AGENT]->add_visit(); /* replaced this_player() by e[E_AGENT],
                                    Coogan, 18-Aug-98 */
      }
    }
    break;
  default:
    raise_error("Unexpected value\n");
  }
}

private void reshape_with_messages(object who, closure reshape,
                                   string stay_invis_message) {
  mixed darkness_prefix;
  string old_short, new_short, old_name, new_name;
  if (!environment(who) || query_light(environment(who)) <= 0)  // too dark?
    darkness_prefix = ({ M_TARGETS, who });
  else
    darkness_prefix = ({ M_ROOM, environment(who) });
  old_short = who->short();
  old_name = who->query_name();
  if (old_short)  // visible?
    send_message(darkness_prefix +
                 ({ M_THE, who, " ",
                    M_CONTINUED }));  /* start the message with
                                         the old appearance */
  funcall(reshape);
  new_short = who->short();
  new_name = who->query_name();
  if (old_short == new_short &&
      old_name == new_name)  // no change of appearance?
    if (!new_short)  // was always invis?
      message(stay_invis_message, who);
    else  // not invis: no change, but visible; no output. cancel.
      send_message(darkness_prefix + ({ M_CANCEL }));
  else  // a change of appearance took place
    if (old_short)  // was visible?
      if (new_short)  // is he now visible?
        send_message(darkness_prefix + ({ M_VERB, "turn", who, " into ",
                                          (old_name != new_name? "" : M_FULL),
                                          M_DESCRIBE, who, "." }));
      else  // became invis by change
        send_message(darkness_prefix +
                     ({ " suddenly ", M_VERB, "disappear", who, "." }));
    else  // became visible by change
      send_message(darkness_prefix +
                   ({ who, " suddenly ", M_VERB, "appear", who, "." }));
}

void turn_into_frog(object who) {
  reshape_with_messages(who,
                        lambda(0, ({ (#'map),
                                     quote(filters), "add_filter", who,
                                     FPRIO_POLYMORPH })),
                        ("You suddenly feel like a big frog but you are still"
                         " invisible.\n"));
}

void defrog(object who) {
  reshape_with_messages(who,
                        lambda(0, ({ (#'map),
                                     quote(filters), "remove_filter", who })),
                        ("You suddenly don't feel like a big frog anymore but"
                         " you are still invisible.\n"));
}

void notify_move(object from, object to) {
  if (from)
    defrog(from);
  if (to) 
    turn_into_frog(to);
}

void notify_destruct() {
  if (environment())
    defrog(environment());
}

private static string *prince = 
  ({ "royal person", "prince", "princess", "lot of princes or princesses" });

mixed do_filter(string func, mixed arg) {
  string vis_name;
  switch (func) {
  case F_ID:
    return arg + ({ "frog", "big frog" });
  case F_NAME:
    return "a big frog";
  case F_SHORT:
    return "a big frog" + 
            (this_player() && this_player()->query_level()>=WL_APPRENTICE &&
             (vis_name = environment()->query_vis_name()) ?
             " ["+environment()->query_vis_name()+"]" : "");
  case F_LONG:
    arg = (capitalize(environment()->short()) + ".\n"
           "A strange looking frog you imagine being a really nice " +
            prince[environment()->query_gender()] + ".\n"
           "Maybe you should try and kiss it ...\n");
    return arg;
  case F_GENDER:
    return 0;  // frogs are neuter. Coogan, 07-Aug-2002
  case F_MMOUT: 
    return ({ M_THE, M_ARG, E_AGENT, M_VERB, "croak", E_AGENT,
              " in surprise and ", M_VERB, "disappear", E_AGENT,
              " in a puff of legs." });
  case F_MMIN: 
    return ({ M_ARG, E_AGENT, M_VERB, "appear", E_AGENT,
              " in a puff of legs." });
  case F_MIN:
    return ({ M_ARG, E_AGENT, M_VERB, "hop", E_AGENT, " in." });
  case F_MOUT:
    return ({ M_THE, M_ARG, E_AGENT, M_VERB, "hop", E_AGENT, " ", M_ARG,
              E_DIR, "." });
  case F_STR: 
    return -8;   // 9->8, Carador, 14-Dec-97, as money weighs something
  case F_NO_ARTICLE:
  case F_TITLE:
  case F_PRETITLE:
  case F_AL_TITLE:
    return 0;
  default: 
    return arg;
  }
}

status drop(status silently) {
  return 1;
}

void self_destruct() {
  destruct(this_object());
}

void set_curse_duration(int length) {
  if (length < 0)
    return;
  while (remove_call_out("self_destruct") != -1)
    ;
  call_out("self_destruct", length);
}

mixed *query_auto_load() {
  return ({ load_name(this_object()), find_call_out("self_destruct") });
}

void init_arg(mixed *arg) {
  set_curse_duration(arg[0]);
}
