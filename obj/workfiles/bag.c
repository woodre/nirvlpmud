#ifndef __LDMUD__ /* Rumplemintz - new code below */
#define MAX_WEIGTH	6

inherit "/obj/objtracker.c"; /* 07/04/06 Earwax */

int local_weight;

long() {
    write("A bag. ");
    if (first_inventory(this_object()))
	write("There is something in it.\n");
    else
	write("You can put things in it.\n");
}

reset(arg) {
    if (arg)
	return;
    local_weight = 0;
}

query_weight() {
    return 1;
}

add_weight(w) {
    if (local_weight + w > MAX_WEIGTH)
	return 0;
    local_weight += w;
    return 1;
}

short() {
    return "bag";
}

id(str) {
    return str == "bag";
}

query_value() {
    return 12;
}

can_put_and_get() { return 1; }

get() {
    return 1;
}

prevent_insert() {
    if (local_weight > 0) {
	write("You can't when there are things in the bag.\n");
	return 1;
    }
    return 0;
}

init() { objtracker_init_check(); }
#else
#include <persistence.h>

inherit "complex/container";

#define MAX_WEIGHT 6

private string bag_long() {
  if (first_inventory(this_object()))
    return capitalize(describe(this_object())) +
           ". There is something in it.\n";
  else
    return capitalize(describe(this_object())) +
           ". You can put things into it.\n";
}

void configure() {
  container::configure();
  remove_persistent_variable("long");
  set_persistence("obj/bag", PER_KEEP_VARS);
  set_long(#'bag_long);
  set_id(({ "bag" }));
  set_name("bag");
  set_short("bag");
  set_value(12);
  set_max_encumbrance(MAX_WEIGHT * 2500);
  set_encumbrance(2500);
}
#endif

