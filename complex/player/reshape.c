#pragma strong_types

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

string   modify_shout_message(string msg)  { return msg;  }
string modify_say_in_messages(string verb) { return verb; }
void         react_on_feeling(mapping e)   {}

void receive_event(mapping e, string t, int p) {
  int i;
  switch (t) {
  case "message":
    if (e[E_AGENT] != environment())  // not for us?
      break;
    if      (e[E_MSG_TYPE] == "shout" && e[E_TO] != "wizards")
      e[E_MSG] = modify_shout_message(e[E_MSG]);
    else if (e[E_MSG_TYPE] == "say")
      while ((i=member(e[E_MESSAGES][0], "say")) > 0)  // is after M_VERB
        e[E_MESSAGES][0][i] =
          modify_say_in_messages(e[E_MESSAGES][0][i]);
    break;
  case "feeling":
    react_on_feeling(e);
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

string query_stay_invisible_msg(status on_apply) {
  return "You feel reshaped, though you stay invisible.\n";
}

void   apply_reshape(object who) {
  reshape_with_messages(who,
                        lambda(0, ({ (#'map),
                                     quote(filters), "add_filter", who,
                                     FPRIO_POLYMORPH })),
                        query_stay_invisible_msg(1));
}

void unapply_reshape(object who) {
  reshape_with_messages(who,
                        lambda(0, ({ (#'map),
                                     quote(filters), "remove_filter", who })),
                        query_stay_invisible_msg(0));
}

void notify_move(object from, object to) {
  if (from)
    unapply_reshape(from);
  if (to)
    apply_reshape(to);
}

void notify_destruct() {
  if (environment())
    unapply_reshape(environment());
}

string  query_shape_short( string  original_short)  { return original_short;  }
string  query_shape_name(  string  original_name)   { return original_name;   }
string *query_shape_id(    string *original_id)     { return original_id;     }
string  query_shape_long(  string  original_long)   { return original_long;   }
int     query_shape_gender(int     original_gender) { return original_gender; }
mixed   query_shape_mmout( mixed   original_mmout)  { return original_mmout;  }
mixed   query_shape_mmin(  mixed   original_mmin)   { return original_mmin;   }
mixed   query_shape_mout(  mixed   original_mout)   { return original_mout;   }
mixed   query_shape_min(   mixed   original_min)    { return original_min;    }

mixed do_shape_filter(string func, mixed arg) {
  return arg;
}

mixed do_filter(string func, mixed arg) {
  string vis_name;
  switch (func) {
  case F_ID:
    return query_shape_id(arg);
  case F_NAME:
    return query_shape_name(arg);
  case F_SHORT:
    return query_shape_short(arg) +
            (this_player() && this_player()->query_level()>=WL_APPRENTICE &&
             (vis_name = environment()->query_vis_name()) ?
             " ["+environment()->query_vis_name()+"]" : "");
  case F_LONG:
    return capitalize(environment()->short()) + ".\n" + query_shape_long(arg);
  case F_GENDER:
    return query_shape_gender(arg);
  case F_MMOUT: 
    return query_shape_mmout(arg);
  case F_MMIN: 
    return query_shape_mmin( arg);
  case F_MOUT:
    return query_shape_mout( arg);
  case F_MIN:
    return query_shape_min(  arg);
  default: 
    return do_shape_filter(func, arg);
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
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
