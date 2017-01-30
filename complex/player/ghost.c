#include <filter.h>
#include <event.h>
#include <describe.h>
#include <message.h>

inherit "basic/create";
inherit "basic/autoload";

private static string *filters =
        ({ F_ID, F_NAME, F_SHORT, F_LONG, 
           F_MMIN, F_MMOUT, F_MIN, F_MOUT, F_STR, F_NO_ARTICLE });
#if 0  // for the emacs ...
({});
#endif

void create() {
  // listen_event("feeling", -100);
  // listen_event("shout", -100);
}

void turn_into_mist(object who) {
  if (!(who && living(who)))
    destruct(this_object());
  map(filters, "add_filter", who, FPRIO_POLYMORPH + 1000);
}

void notify_move(object from, object to) {
  if (!from) 
    turn_into_mist(to);
}

status prevent_move(object from, object to) {
  if (!clonep() || from) 
    return 1;
}

private string prepend(string to, string what) {
  return what+to;
}

mixed do_filter(string func,mixed arg) {
  string desc;
  int depth;
  switch (func) {
  case F_ID:
    arg += (map(arg, #'describe, ARTICLE_A) + 
            map(arg, #'describe, ARTICLE_THE));
    return (arg + ({ "some mist", "mist", "ghost" }) +
            map(arg, #'prepend, "ghost of "));
  case F_NAME:
    depth = caller_stack_depth();
    while (depth--)
      if (previous_object(depth)==this_object())
        return arg;
    return "some mist";
  case F_SHORT:
    return "the ghost of "+environment()->query_name();
  case F_LONG:
    arg = capitalize(environment()->short()+".\n");
    arg += capitalize(environment()->query_pronoun())+" has obviously died.\n";
    return arg;
  case F_MMOUT: 
#if 0  // Coogan, 21-Jan-99
    return "is blown away";
#else
    return ({ M_THE, M_ARG, E_AGENT, M_VERB, "are", M_ARG, E_AGENT,
              " blown away." });
#endif
  case F_MMIN:
#if 0  // Coogan, 21-Jan-99
    return "drifts around";
#else
    return ({ M_ARG, E_AGENT, M_VERB, "drift", M_ARG, E_AGENT, " around." });
#endif
  case F_MIN:
#if 0  // Coogan, 21-Jan-99
    return "drifts around";
#else
    return ({ M_ARG, E_AGENT, M_VERB, "drift", M_ARG, E_AGENT, " around." });
#endif
  case F_MOUT:
#if 0  // Coogan, 21-Jan-99
    return "blows";
#else
    return ({ M_THE, M_ARG, E_AGENT, M_VERB, "blow", M_ARG, E_AGENT, " ",
              M_ARG, E_DIR, "." });
#endif
  case F_STR: 
    return -10;
  case F_NO_ARTICLE: 
#if 0  // i don't like output like 'the some mist'.  Alfe 98-Jul-2
    return 1;
#else
    return 0;
#endif
  default: 
    return arg;
  }
}

status drop(int silently) {
  return 1;
}
