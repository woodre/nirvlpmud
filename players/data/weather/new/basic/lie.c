inherit "basic/sit";

#include <event.h>
#include <message.h>
#include <describe.h>
#include <prop/item.h>

#define CHANGE_PRIO 500
#define CANCEL_PRIO 300
#define HANDLE_PRIO -100

private object *lying;
private mapping lie_hook;
private mixed   lie_text, 
                already_lying_text,
                already_standing_text,
                not_lying_text,
                sit_up_text,
                cant_stand_up_text,
                lie_not_allowed_text;

varargs void lie_down(object who, string where);

varargs mixed query_lying(object who, string where);

mixed query_prevent_leave_text();
mixed query_stand_text(string where);
mixed query_lie_text(string where);
mixed query_sit_up_text(string where);
mixed query_already_lying_text(object where_not, object who);
mixed query_already_standing_text(object who);
mixed query_not_lying_text(object where, object who);
mixed query_lie_not_allowed_text(string where, object who);

int query_max(string where);

void create() {
  sit::create();
  lying = ({ });
}

void stand_up(object ob) {
  lying = query_lying() - ({ ob });
  sit::stand_up(ob);
}

varargs void lie_down(object ob, string where) {
  object *o;
  o = ({ ob });
  lying = (query_lying() - o) + o;
  remove_from_preposition_map(ob);
  add_to_preposition_map(ob, where);
}

varargs void set_lie_hook(closure hook, string where) {
  if (!where)
    where = query_standard_preposition();
  if (!lie_hook)
    lie_hook = ([get_synonym(where) : hook]);
  else
    lie_hook += ([get_synonym(where) : hook]);
}

#define FAIL(who,mess) with_player((who),#'notify_fail,({mess,2}))
#define MESSAGE(who,mess) with_player((who),#'message,({mess}))

status apply_action(string action, int level, mixed arg) {
  object who, target;
  string where;
  if (!mappingp(arg))
    return sit::apply_action(action,level,arg);
  who = arg[E_AGENT];
  target = arg[E_TARGET];
  where = get_synonym(arg[E_PREPOSITION])|| 
          query_preposition(who)||
          query_standard_preposition();
  switch (action) {
  case "change bodystate":
    switch (arg[E_TO]) {
    case "standing":
      if (!query_lying(who))
        return FAIL(who,query_already_standing_text(who)), 
               sit::apply_action(action,level,arg);
      else {
        MESSAGE(who,query_stand_text());
        stand_up(who);
        break;
      }
      break;
    case "sitting":
      if (query_lying(who))
        if (!query_lying(who,where))
          return FAIL(who,query_already_lying_text(target,who)), 0;
      if (arg[E_FROM] == "lying") {
        if (!query_lying(who,where))
          return FAIL(who,query_not_lying_text(target,who)), 
                 sit::apply_action(action,level,arg);
        else {
          MESSAGE(who,query_sit_up_text(where));
          stand_up(who);
          sit_down(who,where);
          break;
        }
      }
      // following three lines added by Carador, Sep-1996
      if (sizeof(query_sitting(0,where)) +
          sizeof(query_lying(0,where)) >= query_max(where))
        return FAIL(who,query_already_full_text(where, who)), 0;
      return sit::apply_action(action,level,arg);
    case "lying":
      if (where && member(query_allowed_prepositions(), where) < 0)
        return 0;
      if (query_sitting(who) && !query_sitting(who,where))
        return FAIL(who,query_already_sitting_text(target,who)), 0;
      if (query_lying(who))
        return FAIL(who,query_already_lying_text(target,who)), 0;
      if (lie_hook && lie_hook[where] && 
          funcall(lie_hook[where], who))
        return FAIL(who,query_lie_not_allowed_text(where,who)), 0;
      if (!query_sitting(who,where))
        if (sizeof(query_sitting(0,where)) + 
            sizeof(query_lying(0,where)) >= query_max(where))
          return FAIL(who,query_already_full_text(where, who)), 0;
      MESSAGE(who,query_lie_text(where));
      stand_up(who);
      lie_down(who,where);
      break;
    }
    break;
  default:
    return sit::apply_action(action,level,arg);
  }
  return 1;
}

void receive_event(mapping e, string type, int prio) {
  object who, target;
  string where;

  who = e[E_AGENT];
  target = e[E_TARGET];
  where = get_synonym(e[E_PREPOSITION])||
          query_preposition(who)||
          query_standard_preposition();
  switch (type) {
  case "change_body_state?":
    switch (e[E_TO]) {
    case "standing":
      return sit::receive_event(e,type,prio);
    default:
      if (prio == CHANGE_PRIO)
        if (!target && (query_lying(who))) {
          e[E_TARGET] = this_object();
          if (!e[E_PREPOSITION])
            e[E_PREPOSITION] = where;
          break;
        }
        else
          return sit::receive_event(e,type,prio);
      if (prio == CANCEL_PRIO) {
        if (e[E_TO] != "standing" && query_lying(who) && 
            (target != this_object() || e[E_TO] == "lying")) {
          FAIL(who,query_already_lying_text(target,who));
          e[E_SUCCESS] = 0;
          cancel_event();
          return;
        }
        if (e[E_TO] == "lying" && query_sitting(who))
          if (target != this_object()) {
            FAIL(who,query_already_sitting_text(target,who));
            e[E_SUCCESS] = 0;
            cancel_event();
            return;
          }
          else break;
        return sit::receive_event(e,type,prio);
      }
    }
    break;
  case "move":
    if ((e[E_FROM] != environment() && e[E_FROM] != this_object()) ||
        !query_lying(who)) 
      return sit::receive_event(e,type,prio);
    switch (prio) {
    case CANCEL_PRIO:
      if (e[E_DIR] == "X")
        return;
      cancel_event();
      if (query_prevent_leave())
        MESSAGE(who,query_prevent_leave_text());
      else {
        command("stand up",who); 
        if (!query_lying(who))
          send_event("move",e,e[E_RECEIVERS]);
      }
      break;
    case HANDLE_PRIO: 
      if (e[E_DIR] == "X")  // added this if(), Coogan, 14-Feb-2002
        stand_up(who);
      sit::receive_event(e,type,prio);
      break;
    }
  default:
    sit::receive_event(e, type, prio);
  }
}

varargs mixed query_lying(mixed who, string where) {
  clean_up_prepositions();
#if 0 // Ugh Mar-28-1996
  lying = filter(lying - ({0}), #'present);
#else
  lying -= ({0});
#endif
  if (who && stringp(who))
    who = present(who);
  if (who && where) 
    return query_preposition(who) == where &&
            member(lying, who) > -1;
  else if (who)
    return member(lying, who) > -1;
  else if (where)
    return (query_preposition_map(where)||({})) & lying;
  else {
    object *lier;
    string *preps;
    int i;
    lier = ({});
    preps = query_allowed_prepositions();
    for (i = sizeof(preps); i--; )
      lier += query_preposition_map(preps[i])||({});
    return lier & lying;
  }
}

varargs string query_body_state(object who, string where) {
  if (query_lying(who, where))
    return "lying";
  else return sit::query_body_state(who, where);
}

varargs void set_max(int count, string where) {
  if (count >= sizeof (query_lying(0, where)) + 
              sizeof(query_sitting(0, where))) 
    sit::set_max(count, where);
}

void set_lie_text(mixed text) {
  lie_text = text;
}

mixed query_lie_text(string preposition) {
  if (closurep(lie_text))
    return funcall(lie_text, preposition, this_object());
  return lie_text ||
         ({ // short test, Coogan, 05-Apr-2002
           (this_player()->short() ? ({ }) : ({ M_TARGETS, M_PL })) +
           ({ M_PL_THE, M_PL_VERB, "lie", " down", M_SPACE, M_ADVERBS, " ",
              preposition || query_standard_preposition(), " ",
              M_ME_THE, "." })});
}

void set_already_lying_text(mixed text) {
  already_lying_text = text;
}

mixed query_already_lying_text(object where_not, object who) {
  if (closurep(already_lying_text)) 
    return funcall(already_lying_text, where_not, this_object(), who);
  return already_lying_text || 
         "But you are already lying " + 
         (query_preposition(this_player()) || query_standard_preposition()) +
         " " + (where_not == this_object()
           ? describe(this_object(),ARTICLE_THE) : describe(this_object())) +
         "!\n";
}

void set_already_standing_text(mixed text) {
  already_standing_text = text;
}

mixed query_already_standing_text(object who) {
  if (closurep(already_standing_text))
    return funcall(already_standing_text, this_object(), who);
  return already_standing_text || 
         "You are not lying or sitting anywhere!\n";
}

void set_not_lying_text(mixed text) {
  not_lying_text = text;
}

mixed query_not_lying_text(object where, object who) {
  if (closurep(not_lying_text)) 
    return funcall(not_lying_text, where, this_object(), who);
  return not_lying_text || 
         "But you are not lying " + query_standard_preposition() + " " +
         describe((where || this_object()), ARTICLE_THE) + "!\n";
}

void set_sit_up_text(mixed text) {
  sit_up_text = text;
}

mixed query_sit_up_text(string preposition) {
  if (closurep(sit_up_text)) 
    return funcall(sit_up_text, this_object(), preposition);
  return sit_up_text ||
         ({ // short test, Coogan, 05-Apr-2002
           (this_player()->short() ? ({ }) : ({ M_TARGETS, M_PL })) +
           ({ M_PL_THE, M_PL_VERB, "sit", " up", M_SPACE, M_ADVERBS, " ",
              preposition || query_standard_preposition(), " ",
              M_OBJECT, M_ME_THE, "." })});
}

void set_lie_not_allowed_text(mixed text) {
  lie_not_allowed_text = text;
}

mixed query_lie_not_allowed_text(string preposition, object who) {
  if (closurep(lie_not_allowed_text))
    return funcall(lie_not_allowed_text, this_object(), preposition, who);
  return lie_not_allowed_text ||
         "You can't lie down " +
         // added next ( ), Coogan, 17-Jan-2001
         (preposition || query_standard_preposition()) + " " +
         describe(this_object(), ARTICLE_THE) + ".\n";
}

