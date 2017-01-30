#include <prop/item.h>
#include <describe.h>
#include <message.h>

inherit "basic/lie";
inherit "complex/container";

static string table_short() {
  return describe(this_object());
}

static string table_state(status in_output) {
  mixed h;
  h = filter_objects(query_sitting()+query_lying(),"short");
  h =
    filter(h,#'query_sitting,"at") +
    filter(h,#'query_lying,"at") +
    filter(h,#'query_sitting,"on") +
    filter(h,#'query_lying,"on");
  if (sizeof(h))
    return "occupied by " + message2string(({ M_ACTIVE_OBJECT,h }));
  else  // if (!in_output)  // use this condition if "empty" shall not
                            // show up in output but be used just in input.
    return "not occupied";
}

static string table_long() {
  object *h;
  object *sitting_at, *sitting_on, *sitting_under;
  object *lying_at, *lying_on, *lying_under;
  h = filter_objects(query_sitting()+query_lying(),"short");
  sitting_at = filter(h,#'query_sitting,"at");
  sitting_on = filter(h,#'query_sitting,"on");
  sitting_under = filter(h,#'query_sitting,"under");
  lying_at = filter(h,#'query_lying,"at");
  lying_on = filter(h,#'query_lying,"on");
  lying_under = filter(h,#'query_lying,"under");
  return
#if 0  // 1, then 0 again, Coogan, 21-Feb-02
    ((funcall(query_container_long()) ||
#else
    ((query_container_long() ||
#endif
     (capitalize(message2string(({ this_object() }))) + ".\n")) +
    capitalize(message2string((sizeof(sitting_at)?
                              ({ M_THE,sitting_at,M_VERB,"be",sitting_at }) :
                              ({ "Nobody is" })) +
                              ({ " sitting at ",M_ME_THE,"." }))) +"\n" +
    (sizeof(lying_at) ? 
     capitalize(message2string(({ M_THE,lying_at,M_VERB,"be",lying_at, 
                                  " lying at ",M_ME_THE,"." }))) +"\n" : "") +
    (sizeof(sitting_on) ? 
     capitalize(message2string(({ M_THE,sitting_on,M_VERB,"be",sitting_on, 
                                  " sitting on ",M_ME_THE,"." }))) +"\n" : "") +
    (sizeof(lying_on) ? 
     capitalize(message2string(({ M_THE,lying_on,M_VERB,"be",lying_on, 
                                  " lying on ",M_ME_THE,"." }))) +"\n" : "") +
    (sizeof(sitting_under) ? 
     capitalize(message2string(({ M_THE,sitting_under,
                                  M_VERB,"be",sitting_under, 
                                  " sitting under ",
                                  M_ME_THE,"." }))) +"\n" : "") +
    (sizeof(lying_under) ? 
     capitalize(message2string(({ M_THE,lying_under,M_VERB,"be",lying_under, 
                                  " lying under ",
                                  M_ME_THE,"." }))) + "\n" : ""));
}

void create() {
  lie::create();
  container::create();
}

void configure() {
  container::configure();
  set_property(P_NOT_PORTABLE);
  set_property(P_SURFACE);
  add_to_property(P_STATE_DESCRIPTION,#'table_state);
  set_name("table");
  set_short(#'table_short);
  set_long(#'table_long);
  set_id("table");
  set_allowed_prepositions(({ "at", "on", "under" }));
  add_synonym(({ "onto" }), "on");
  add_synonym(({ "beside" }), "at");
  add_synonym(({ "beneath" }), "under");
}

int apply_action(string action, int level, mixed args) {
  return
    lie::apply_action(action, level, args) ||
    container::apply_action(action, level, args);
}
