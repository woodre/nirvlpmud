/*  when worn, the player moves silently - Eurale  */

#include <ansi.h>
inherit "/obj/armor.c";

reset(arg) {
  ::reset(arg); /* this and if arg check - verte */
  if(arg) return;
set_name("elven boots");
set_short(BOLD+"Elven boots"+NORM);
set_long(
  "These black boots are made from some unknown material.  Their weight\n"+
  "and feel indicate they have some kind of magical powers.\n");
set_ac(1);
set_params("magical",1,0,0);
set_type("boots");
set_weight(1);
set_value(1545);
set_arm_light(0);
}

id(str){ return (::id(str) || (worn ? (str == "silent_move_object") : (str == "boots"))); }
