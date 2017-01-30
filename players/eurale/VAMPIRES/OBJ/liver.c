/* 3(14 soak/stuff) = 42 total tox
   3(45 + random(10)) = 150 avg heal
   42/150 = .28 = 12 coins/pt healed
   12(135) = 1620 + 2/3(12(10)) = 1700 coins for this heal
        calculated using the new heal format 6/4/03 - Eurale  */

/* Approved by Pain, 6/5/03 */
#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("liver");
add_alias("raw liver");
add_alias("slab");
set_short(HIR+"slab of raw liver"+NORM);
set_long(
  "A large piece of juicy, raw liver that appears to be human.  Anyone feeling\n"+
  "adventuresome could probably 'eat' it for energy.\n");

add_cmd("eat");
add_cmd("bite");
set_type("bites");
set_type_single("bite");
set_msg(
  HIR+"You bite off and eat a piece of juicy, raw liver.\n");
set_heal(45+random(10),45+random(10));
set_charges(3);
  set_msg_precharges(HIR+"^"+NORM);
  set_msg_postcharges(HIR+"^"+NORM);
set_stuff(7);
set_soak(7);
set_value(400);
set_msg_stuffed(
  HIR+"You nearly vomit as you try to eat another piece of raw liver.\n"+NORM);
set_empty_msg(
  HIR+"You chew up and swallow the last piece of raw liver.\n"+NORM);
}
