/*  Changed to new heals format 8/21/02 - Eurale  */
/*  Cost:  -10soak @ 20/pt = 200 * 3 pills = 600  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("pill");
add_alias("pills");
add_alias("x-lax");
set_short(YEL+"x-lax pills"+NORM);
set_long(
  "Small yellow pills of x-lax that will settle your stomach and get you\n"+
  "regular again in no time if you 'swallow' them.\n");

add_cmd("swallow");
set_type("pills");
set_type_single("pill");
set_msg(
  YEL+"You swallow a small yellow x-lax pill.\n"+NORM);
set_msg2(
  " swallows a small yellow x-lax pill.\n");
/*
Changed this to new heal standards  - Jaraxle 
set_heal(0,0);
*/

 set_heal(-10+(-10/3), 0);
set_charges(3);
  set_msg_precharges("<");
  set_msg_postcharges(">");
set_stuff(-10);  /*  intox  soak  stuff  */
set_value(100);
set_msg_stuffed(
  "Your stomach is too upset to take another pill right now.\n");
set_empty_msg(
  YEL+"You swallow the last x-lax tablet and hear your stomach start to rumble.\n"+NORM);
}
