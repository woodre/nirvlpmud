#include "/players/laera/closed/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_id("water crystal");
  set_alias("crystal");
  set_short(HIC+"Water Crystal"+OFF);
set_long(
"A precious crystal found only on water elemental monsters such as \n" +
"the fastiticalon.  Powerful magic users were once able to create \n" +
"spells from a water crystal.  It is now used to make cheap baubles \n" +
"and jewelry.\n");


  set_value(800 + random(400));
  set_weight(3);
}

