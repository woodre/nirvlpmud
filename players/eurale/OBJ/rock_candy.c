/*  Changed to new heals format 7/28/02 - Eurale  */
#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("candy");
add_alias("rock candy");
add_alias("cluster");
set_short(
  HIR+"cluster "+HIG+"of "+HIC+"rock "+HIY+"candy"+NORM);
set_long(
  "A cluster of rock candy held together by a small string.\n");

set_type("chews");
set_type_single("chew");
set_msg(HIY+"You chew up a "+HIC+"piece of "+HIR+"rock candy.\n"+NORM);
set_msg2(" chews up some rock candy.\n");
add_cmd("chew");
set_heal(35,35);
set_charges(5);
  set_msg_precharges("<");
  set_msg_postcharges(">");
set_stuff(14);
set_value(300);
set_msg_stuffed(
  "The candy is just too sweet to have any more now.\n");
set_empty_msg(
  HIC+"You finish off the rock candy and throw away the string.\n"+NORM);
}
