#if __START_TIME__ > "980420070223"
#include "new_petrification"
#else




#include <filter.h>
#include <event.h>
#include <describe.h>
#include <wizlevels.h>
#include <kernel.h>
#include <message.h>
#include <limits.h>

inherit "basic/create";
inherit ACCESS;

private static string *filters = ({ F_ID,
                                    F_ID_CLOSURE,
                                    F_NAME,
                                    F_SHORT,
                                    F_LONG, 
                                    F_HIDE_INV,
                                    F_NO_ARTICLE });

private void reshape_with_messages(object who,closure reshape,
                                   string stay_invis_message) {
  mixed darkness_prefix;
  string old_short,new_short,old_name,new_name;
  if (environment(who) && query_light(environment(who)) <= 0)  // too dark?
    darkness_prefix = ({ M_TARGETS,who });
  else
    darkness_prefix = ({});
  old_short = who->short();
  old_name = who->query_name();
  if (old_short)  // visible?
    send_message(darkness_prefix +
                 ({ M_THE,who," ",M_CONTINUED }));  // start the message with
                                                    // the old appearance
  funcall(reshape);
  new_short = who->short();
  new_name = who->query_name();
  if (old_short == new_short &&
      old_name == new_name)  // no change of appearance?
    if (!new_short)  // was always invis?
      message(stay_invis_message,who);
    else  // not invis: no change, but visible; no output. cancel.
      send_message(darkness_prefix + ({ M_CANCEL }));
  else  // a change of appearance took place
    if (old_short)  // was visible?
      if (new_short)  // is he now visible?
        send_message(darkness_prefix + ({ M_VERB,"turn",who," into ",
                                          (old_name != new_name? "" : M_FULL),
                                          M_DESCRIBE,who,"." }));
      else  // became invis by change
        send_message(darkness_prefix +
                     ({ " suddenly ",M_VERB,"disappear",who,"." }));
    else  // became visible by change
      send_message(darkness_prefix +
                   ({ who," suddenly ",M_VERB,"appear",who,"." }));
}

void petrify(object who) {
  reshape_with_messages(who,lambda(0,({ (#'map),
                                        quote(filters),"add_filter",who,
                                        FPRIO_PETRIFICATION })),
                        ("You suddenly turn into stone but you are still"
                         " invisible.\n"));
}

void depetrify(object who) {
  reshape_with_messages(who,lambda(0,({ (#'map),
                                        quote(filters),"remove_filter",who })),
                        ("You suddenly turn alive again but"
                         " you are still invisible.\n"));
}

void notify_move(object from,object to) {
  if (from)
    depetrify(from);
  if (to)
    petrify(to);
}

status drop(status silently) {
  return 1; // shall not be dropped
}

mixed get_state() {
  return -1;  // not persistent!
}

#if 1 // activated again, Chameloid, 20-Apr-98
status prevent_move(object from,object to) {
  if (!clonep() || !query_once_interactive(to)) // changed second condition,
                                                // Chameloid, 20-Aug-98
    return 1;
}
#endif

void notify_destruct() {
  if (environment())
    depetrify(environment());
}

mixed filter(string func,mixed arg) {
  string vis_name;
  switch (func) {
  case F_ID:
    return arg + ({ "statue","stone statue" });
  case F_ID_CLOSURE:
    // return a closure (one argument) which returns true if the closure
    // arg returns true for its argument or for its argument without a
    // leading "stone statue of " or "statue of ".
    return lambda(({ 'x }),
                  ({ (#'funcall),
                     arg,
                     ({ (#'regreplace),'x,"^(stone |)statue of ","",1 }) }));
  case F_NAME:
#if 0  // 1: "Alfe's stone statue", 0: "statue"
    return (environment()->call_with_limited_filters(#'describe,
                                                     INT_MIN,
                                                     FPRIO_PETRIFICATION-1,
                                                     environment(),0,0,0,1) +
            " stone statue");
#else
    return "statue";
#endif
  case F_SHORT:
#if 1
    return ("a stone statue of " +
            environment()->call_with_limited_filters(#'call_other,
                                                     INT_MIN,
                                                     FPRIO_PETRIFICATION-1,
                                                     environment(),
                                                     "query_name"));
#else
    return "a stone statue";
#endif
  case F_LONG:
    return ("A stone statue of " +
            environment()->call_with_limited_filters(#'call_other,
                                                     INT_MIN,
                                                     FPRIO_PETRIFICATION-1,
                                                     environment(),"short") +
            ".\n"
            "You wonder when it will come alive again.\n");
  case F_NO_ARTICLE:
    return 0;
  case F_HIDE_INV:
    // fall through
  default: 
    return arg;
  }
}




#endif
