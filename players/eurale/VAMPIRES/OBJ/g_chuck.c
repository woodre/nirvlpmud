/*  Updated to new heal format 7/28/02 - Eurale  */
#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("chuck");
add_alias("ground chuck");
add_alias("pattie");
set_short(HIR+"ground chuck patties"+NORM);
set_long(
  "Beautiful, fresh ground chuck patties already made into the perfect size\n"+
  "to 'eat' in a single bite.\n");

set_type("patties");
set_type_single("pattie");
set_msg(
  HIR+"You chew up and swallow a juicy, ground chuck pattie.\n"+NORM);
add_cmd("eat");
set_heal(45,45);
set_charges(3);
  set_msg_precharges(HIR+"^"+NORM);
  set_msg_postcharges(HIR+"^"+NORM);
set_stuff(14);
set_value(400);
set_msg_stuffed(
  HIR+"You nearly vomit as you try to eat another ground chuck pattie.\n"+NORM);
set_empty_msg(
  HIR+"You eat the last ground chuck pattie and throw away the wrapper.\n"+NORM);
}
