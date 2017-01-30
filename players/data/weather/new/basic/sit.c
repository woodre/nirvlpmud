#pragma strong_types

#include <event.h>
#include <message.h>
#include <describe.h>
#include <prop/item.h>

// Ugh told me that the following three defines are temporarily and
// might change in near future. If you do so, _please_ don't forget
// to adapt ~Momu/room/Choice.c as it uses them as well and as it
// won't work anymore when the priorities should change. And,
// if there should be an include-file which defines the priorities and
// if these lines are no longer neccessary please delete them
// Carador, 22-Dec-1994

#define CHANGE_PRIO 500
#define CANCEL_PRIO 300
#define HANDLE_PRIO -100

virtual inherit "basic/synonym";
virtual inherit "basic/property";

private object *sitting;
private mapping max, preposition_map, sit_hook;
private string standard_preposition, *allowed_prepositions;
private mixed   sit_text,
                stand_text,
                already_full_text,
                already_sitting_text,
                not_sitting_text,
                prevent_leave_text,
                sit_not_allowed_text;
private status prevent_leave = 1;

void stand_up(object who);
void sit_down(object who, string where);

varargs mixed query_sitting(object who, string where);

mixed query_prevent_leave_text();
varargs mixed query_stand_text(string where);    // Carador, May-1996
mixed query_sit_text(string where);
mixed query_already_sitting_text(object where_not,object who);
mixed query_not_sitting_text(object who);
mixed query_already_full_text(string where,object who);
mixed query_sit_not_allowed_text(string where,object who);

varargs int query_max(string where);

void set_allowed_prepositions(string *allowed);
string *query_allowed_prepositions();
void set_standard_preposition(string prep);
string query_standard_preposition();
string query_preposition(object whose);

void set_prevent_leave(status can_not_leave);
status query_prevent_leave();
void receive_event(mapping e,string type,int prio);

void create() {
  string std_prep;
  std_prep = query_standard_preposition();
  sitting = ({});
  preposition_map = ([ std_prep : ({}) ]);
  max = ([ std_prep : 1 ]);
  listen_event("change_body_state?",CHANGE_PRIO);
  listen_event("change_body_state?",CANCEL_PRIO);
  listen_event("move", CANCEL_PRIO);
  listen_event("move", HANDLE_PRIO);
  set_property(P_SITTABLE);
}

void set_allowed_prepositions(string *prep) {
  int i;
  allowed_prepositions = prep[0..];
  if (sizeof(allowed_prepositions))
    set_standard_preposition (allowed_prepositions[0]);
  for (i=sizeof(allowed_prepositions); i--; ) {
    if (!max[allowed_prepositions[i]])
      max[allowed_prepositions[i]]++;
    if (!preposition_map[allowed_prepositions[i]])
      preposition_map[allowed_prepositions[i]] = ({});
  }
}

string *query_allowed_prepositions() {
  return allowed_prepositions && allowed_prepositions[0..];
}

void set_standard_preposition(string prep) {
  if (member(allowed_prepositions, prep) > -1)
    standard_preposition = prep;
}

string query_standard_preposition() {
  return (standard_preposition||"on");
}

static void remove_from_preposition(string preposition,object *ob,object who) {
  ob -= ({ who });
}

static void remove_from_preposition_map(object who) {
  walk_mapping(preposition_map, #'remove_from_preposition, who);
}

static void add_to_preposition_map(object ob, string where) {
  if (where && !preposition_map[where])
    preposition_map[where] = ({ ob });
  else
    preposition_map[where||query_standard_preposition()] += ({ ob });
}

void set_prevent_leave(status can_not_leave) {
  prevent_leave = can_not_leave;
}

status query_prevent_leave() {
  return prevent_leave;
}

varargs void set_sit_hook(closure hook, string where) {
  if (!where)
    where = query_standard_preposition();
  if (!sit_hook)
    sit_hook = ([ get_synonym(where) : hook ]);
  else
    sit_hook += ([ get_synonym(where) : hook ]);
}

void stand_up(object ob) {
  sitting = query_sitting() - ({ ob });
  remove_from_preposition_map(ob);
}

void sit_down(object ob, string where) {
  object *o;
  o = ({ ob });
  sitting = (sitting - o) + o;
  remove_from_preposition_map(ob);
  add_to_preposition_map(ob, where);
}

#define FAIL(who,mess) with_player((who),#'notify_fail,({mess,2}))
#define MESSAGE(who,mess) with_player((who),#'message,({mess}))

status apply_action(string action,int level,mixed e) {
  object who, target;
  string where;

  if (!mappingp(e))
    return 0;
  who = e[E_AGENT];
  target = e[E_TARGET];
  where = get_synonym(e[E_PREPOSITION]) ||
          query_preposition(who)        ||
          query_standard_preposition();
  switch (action) {
  case "change bodystate":
    switch (e[E_TO]) {
    case "standing":
      if (!query_sitting(who))
        return FAIL(who,query_not_sitting_text(who)), 0;
      else {
        MESSAGE(who,query_stand_text(where));   // where, Carador, May-1996
        stand_up(who);
        break;
      }
      break;
    default:
      if (e[E_TO] != "sitting")
        return 0;
      if (member(query_allowed_prepositions(), where) < 0)
        return 0;
      if (sit_hook && sit_hook[where] &&
          funcall(sit_hook[where], who))
        return FAIL(who,query_sit_not_allowed_text(where,who)), 0;
      if (sizeof(query_sitting(0, where)) < query_max(where) &&
          e[E_TO] == "sitting") {
        MESSAGE(who,query_sit_text(where));
        stand_up(who);
        sit_down(who,where);
        break;
      }
      else
        return FAIL(who,query_already_full_text(where,who)), 0;
      break;
    }
    break;
  default:
    return 0;
  }
  return 1;
}

void receive_event(mapping e, string type, int prio) {
  object who, target;
  string where;
  who = e[E_AGENT];
  target = e[E_TARGET];
  where = get_synonym(e[E_PREPOSITION])||
          query_preposition(who)||query_standard_preposition();

  switch (type) {
  case "change_body_state?":
    if (prio == CHANGE_PRIO && !target && query_sitting(who)) {
      e[E_TARGET] = this_object();
      if (!e[E_PREPOSITION])
        e[E_PREPOSITION] = where;
      break;
    }
    if (prio == CANCEL_PRIO) {
      // split up the if() block and added the next if(), Coogan, 05-May-2004
#if 0  // Coogan, 06-May-2004, this looks better
      if (get_room(this_object()) != environment() &&
          e[E_TO] == "sitting" &&
          target == this_object()) {
        FAIL(who, "But " + describe(this_object(), ARTICLE_THE) + " " +
                  (this_object()->query_plural() ? "are" : "is") +
                  " not standing in this room.\n");
        e[E_SUCCESS] = 0;
        cancel_event();
        return;
      }
#else
      if (!accessible(who, this_object()) &&
          e[E_TO] == "sitting" &&
          target == this_object()) {
        FAIL(who, "But " + describe(this_object(), ARTICLE_THE) + " " +
                  (this_object()->query_plural() ? "are" : "is") +
                  " not accessible to you right now.\n");
        e[E_SUCCESS] = 0;
        cancel_event();
        return;
      }
#endif
      if (query_sitting(who) &&
          (e[E_TO] == "sitting" ||
           (e[E_TO] != "standing" && target != this_object()))) {
        FAIL(who,query_already_sitting_text(target,who));
        e[E_SUCCESS] = 0;
        cancel_event();
        return;
      }
    }
    break;

  case "move":
    if ((e[E_FROM] != environment() && e[E_FROM] != this_object()) ||
        !query_sitting(who))
      return;
    switch (prio) {
    case CANCEL_PRIO:
      // check for 'home' added, Coogan, 19-Nov-2003
      if (!stringp(e[E_DIR]) || e[E_DIR] == "X" || e[E_DIR] == "home")
        return;
      cancel_event();
      if (query_prevent_leave())
        MESSAGE(who,query_prevent_leave_text());
      else {
        command("stand up",who);
        if (!query_sitting(who))
          send_event("move",e,({e[E_TO],e[E_FROM]}));
      }
      break;
    case HANDLE_PRIO:
      // check for 'home' added, Coogan, 19-Nov-2003
      if (!stringp(e[E_DIR]) || e[E_DIR] == "X" || e[E_DIR] == "home")
        stand_up(who);
      break;
    }
  }
}

static void clean_up_prepositions() {
  /* This cleans up the mapping of all objects that are either
     destructed or neither in the environment nor in the inventory */
  walk_mapping(preposition_map,
               lambda(({'key, 'value, 'z}), ({#'-=, 'value, 'z})), ({0}));
#if 0 // Ugh Mar-28-1996
  walk_mapping(preposition_map,
               lambda(({'key, 'value}),
                      ({#'=, 'value, ({#'filter, 'value, #'present})})));
#endif
}

object *query_preposition_map(string where) {
  return preposition_map[where] && preposition_map[where][0..];
}

string query_preposition(object who) {
  int i;
  string *preps;
  preps = query_allowed_prepositions();
  for (i=sizeof(preps); i--; )
    if (preposition_map[preps[i]] &&
        member(preposition_map[preps[i]], who) > -1)
      return preps[i];
  return 0;  // Coogan, 26-Mar-2011
}

varargs mixed query_sitting(mixed who, string where) {
  clean_up_prepositions();
#if 0 // Ugh Mar-28-1996
  sitting = filter(sitting - ({ 0 }), #'present);
#else
  sitting -= ({ 0 });
#endif
  if (who && stringp(who))
    who = present(who);
  if (who && where)
    return query_preposition(who) == where &&
            member(sitting, who) > -1;
  else if (who)
    return member(sitting, who) > -1;
  else if (where)
    return (query_preposition_map(where)||({})) & sitting;
  else {
    object *sitters;
    string *preps;
    int i;
    sitters = ({});
    preps = query_allowed_prepositions();
    for (i=sizeof(preps); i--; )
      sitters += query_preposition_map(preps[i])||({});
    return sitters & sitting;
  }
}

varargs string query_body_state(object who, string where) {
  if (query_sitting(who, where))
    return "sitting";
  return "standing";
}

varargs int query_max(string where) {
  return max[where||query_standard_preposition()];
}

void set_prevent_leave_text(mixed text) {
  prevent_leave_text = text;
}

mixed query_prevent_leave_text() {
  if (closurep(prevent_leave_text))
    return funcall(prevent_leave_text, this_object());
  return prevent_leave_text ||
    ({ ({ M_WRITE, "But you are still ", query_body_state(this_player()), " ",
          query_preposition(this_player()) ||
          (this_object()->query_property(P_SURFACE) ? "on" : "in"), " ",
          M_ME_THE, "." }) });
}

void set_max(int count, string where) {
  if (count >= sizeof(query_sitting(0, where)))
    max[where||query_standard_preposition()] = count;
}

status query_alone() {
  string name;
  name = describe(this_object(),ARTICLE_NONE);
  return !present(name+" 2");
}

void set_sit_text(mixed text) {
  sit_text = text;
}

mixed query_sit_text(string preposition) {
  if (closurep(sit_text))
    return funcall(sit_text, preposition);
  return sit_text ||
         ({ // short test, Coogan, 05-Apr-2002
           (this_player()->short() ? ({ }) : ({ M_TARGETS, M_PL })) +
           ({ M_PL_THE, M_PL_VERB, "sit", " down ",  // Alfe 1995-Aug-09
              preposition ||
               (this_object()->query_property(P_SURFACE) ? "on" : "in"), " ",
#if 1  // Coogan, 15-Jul-2002
              M_ME_THE,
#else
              (query_alone() 
               ? describe(this_object(),ARTICLE_THE) : describe(this_object())),
#endif
              "." })});
}

void set_stand_text(mixed text) {
  stand_text = text;
}

varargs mixed query_stand_text(string where) {
                                         // where added by Carador, May-1996
  if (closurep(stand_text))
    return funcall(stand_text, where);
  return stand_text ||
         ({ // short test, Coogan, 05-Apr-2002
           (this_player()->short() ? ({ }) : ({ M_TARGETS, M_PL })) +
           ({ M_PL_THE, M_PL_VERB, "stop", " ",  // Alfe 1995-Aug-09
              query_body_state(this_player()), " ",
              query_preposition(this_player()) ||
                (this_object()->query_property(P_SURFACE) ? "on" : "in"),
              " ", M_ME_THE, " and ", M_PL_VERB, "stand", " up." })});
}

void set_already_sitting_text(mixed text) {
  already_sitting_text = text;
}

mixed query_already_sitting_text(object where_not,object who) {
  if (closurep(already_sitting_text))
    return funcall(already_sitting_text, where_not, this_object(), who);
  return already_sitting_text ||
         "But you are already sitting " + query_preposition(this_player()) +
         " " + (where_not == this_object()
           ? describe(this_object(), ARTICLE_THE) : describe(this_object())) +
         ".\n";
}

void set_already_full_text(mixed text) {
  already_full_text = text;
}

mixed query_already_full_text(string preposition,object who) {
  if (closurep(already_full_text))
    return funcall(already_full_text,preposition,this_object(),who);
  return already_full_text ||
         "But " + describe(this_object(), ARTICLE_THE) + " " +
         (this_object()->query_plural() ? "are" : "is") +
         " already full.\n";
}

void set_not_sitting_text(mixed text) {
  not_sitting_text = text;
}

mixed query_not_sitting_text(object who) {
  if (closurep(not_sitting_text))
    return funcall(not_sitting_text,this_object(),who);
  return not_sitting_text ||
         "But you are not sitting " + query_standard_preposition() + " " +
         describe(this_object(), ARTICLE_THE) + ".\n";
}

void set_sit_not_allowed_text(mixed text) {
  sit_not_allowed_text = text;
}

mixed query_sit_not_allowed_text(string preposition,object who) {
  if (closurep(sit_not_allowed_text))
    return funcall(sit_not_allowed_text,this_object(), preposition, who);
  return sit_not_allowed_text ||
         "You can't sit down " + preposition + " " +
         describe(this_object(), ARTICLE_THE) + ".\n";
}

