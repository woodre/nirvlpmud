#include <prop/item.h>
#include <describe.h>
#include <message.h>

inherit "basic/sit";
inherit "complex/container";

static string chair_short() {
  return describe(this_object());
}

static string chair_state(status in_output) {
#if 0  // Alfe 98-May-26
  return (sizeof(query_sitting()) ? "occupied" : "empty");
#else
  mixed h;
  if (sizeof(h=filter_objects(query_sitting(),"short")))
    return "occupied by " + message2string(({ M_ACTIVE_OBJECT,h }));
  else  // if (!in_output)  // use this condition if "empty" shall not
                            // show up in output but be used just in input.
    return "empty";
#endif
}

static string chair_long() {
#if 0  // Alfe 98-May-26
  object *s, *p;
  status am_I_sitting;
  s = query_sitting();
  p = ({ this_player() });
  if (sizeof(s & p))
    am_I_sitting = 1;
  // Coogan, 21-Apr-98, better long description
  return (query_container_long()
          ? query_container_long() + "It"
          : (capitalize(describe(this_object(), ARTICLE_THE) || "it"))) + 
         " is " + 
         (sizeof(s)
          ? "occupied by " + make_list((am_I_sitting
                                        ? ({ "yourself" }) + describe_list(s-p)
                                        : describe_list(s)), "nobody visible")
          : "empty") + ".\n";
#else
  mixed h;
  string cl;
  h = filter_objects(query_sitting(),"short");
  return 
#if 0  // Coogan, 10-Nov-2002
         (funcall(query_container_long()) ||  // funcall, Coogan, 09-Apr-02
           (capitalize(message2string(({ this_object() }))) + ".\n"))
#else
         ((cl = funcall(query_container_long())) ? cl : "")
#endif
          +
          capitalize(message2string((cl ? ({ M_ME_PRONOUN })
                                        : ({ M_THE,this_object() })) +
                                    ({ M_VERB,"are",this_object() }) +
                                    (sizeof(h) ? ({ " occupied by ",
                                        M_ACTIVE_OBJECT,M_THE,h,"." }) :
                                     ({ " empty." })))) + "\n";
#endif
}

void create() {
  sit::create();
  container::create();
}

void configure() {
  container::configure();
  set_property(P_NOT_PORTABLE);
  set_property(P_SURFACE);
  add_to_property(P_STATE_DESCRIPTION,#'chair_state);
  set_name("chair");
  set_short(#'chair_short);
  set_long(#'chair_long);
  set_id("chair");
  set_allowed_prepositions(({ "on" }));
  add_synonym(({ "onto", "in", "into" }), "on");
}

int apply_action(string action, int level, mixed args) {
  return
    sit::apply_action(action, level, args) ||
    container::apply_action(action, level, args);
}
