#include <prop/item.h>
#include <describe.h>

inherit "basic/lie";
inherit "complex/container";

static string bed_short() {
  return describe(this_object());
}

static string *bed_state() {
  return ({ (sizeof(query_sitting()) + sizeof(query_lying())?
             "occupied" : "empty") });
}

static string bed_long() {
  object *s, *p;
  status me_too;
  s = query_sitting() + query_lying();
  p = ({ this_player() });
  if (sizeof(s & p))
    me_too = 1;
  return (query_container_long()
          ? query_container_long() + "It"
          : (capitalize(describe(this_object(), ARTICLE_THE) || "it"))) +
         " is " +
         (sizeof(s)
          ? "occupied by " + make_list((me_too
                                        ? ({ "yourself" }) + describe_list(s-p)
                                        : describe_list(s)), "nobody visible")
          : "empty") + ".\n";
}

void create() {
  lie::create();
  container::create();
}

void configure() {
  container::configure();
  set_property(P_NOT_PORTABLE);
  set_property(P_SURFACE);
  set_property(P_STATE_DESCRIPTION, #'bed_state);
  set_name("bed");
  set_short(#'bed_short);
  set_long(#'bed_long);
  set_id(({"bed"}));
  set_allowed_prepositions(({ "on" }));
  add_synonym(({ "onto", "in", "into" }), "on");
}

int apply_action(string action, int level, mixed args) {
  return
    lie::apply_action(action, level, args) ||
    container::apply_action(action, level, args);
}
