#include <filter.h>
#include <event.h>
#include <message.h>
#include <limits.h>
#include <gender.h>

inherit "basic/curse";

private static string *filters = ({ F_ID,
                                    F_ID_CLOSURE,
                                    F_GENDER,
                                    F_NAME,
                                    F_SHORT,
                                    F_LONG, 
                                    F_NO_ARTICLE });

void receive_depetrify_event(mapping e) {
  if (e[E_AGENT] == environment())
    destruct(this_object());
}

void apply_curse(object who) {
  if (!living(who))
    self_destruct();
  else
    reshape_with_messages(who,lambda(0,({ (#'map),
                                          quote(filters),"add_filter",who,
                                          FPRIO_PETRIFICATION })),
                          ("You suddenly turn into stone but you are still"
                           " invisible.\n"));
}

void remove_curse(object who) {
  reshape_with_messages(who,lambda(0,({ (#'map),
                                        quote(filters),"remove_filter",who })),
                        ("You suddenly turn alive again but you are still"
                         " invisible.\n"));
}

mixed do_filter(string func,mixed arg) {
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
  case F_GENDER:
    return GND_NEUTER;  // statues are neuter
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
  default: 
    return arg;
  }
}

private status linkdead_mark;

void set_linkdead_mark() {
  listen_event("depetrify",-500,#'receive_depetrify_event);
  set_curse_duration(-1);  // don't self destruct
  linkdead_mark = 1;
}

void set_curse_duration(int length) {
  if (linkdead_mark)
    raise_error("linkdead marked petrification can't be durated\n");
  else
    curse::set_curse_duration(length);
}

mixed *query_auto_load() {
  return !linkdead_mark && curse::query_auto_load();
}
