/*  Changed to new heals format 8/15/02 - Eurale  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("bread");
add_alias("loaf");
add_alias("fresh bread");
set_short("loaf of fresh bread");
set_long(
  "A freshly baked loaf of bread.\n");

add_cmd("eat");
set_type("bites");
set_type_single("bite");
set_msg(
  "You take a bite of the freshly baked bread.\n");
set_msg2(
  " takes a bite of the freshly baked bread.\n");
set_heal(25,25);
set_charges(5);
  set_msg_precharges("<");
  set_msg_postcharges(">");
set_stuff(14);  /*  intox  soak  stuff  */
set_value(150);
set_msg_stuffed(
  "You are too full for another bite at the moment.\n");
set_empty_msg(
  "You eat the last of the freshly baked bread.\n");
}
