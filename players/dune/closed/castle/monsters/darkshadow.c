inherit "obj/monster";
#include "definitions.h"


id(str)
{
  return str == "shadow" || str == "darkshadow";
}


reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("Darkshadow");
   set_race("undead");
   set_alias("shadow");
   set_short("A Darkshadow");
   set_long(
"     The Darkshadow is a haunting minion of undead.  It roams the\n"+
"the land in eternal torment.  It used to be a living being, full of\n"+
"life and hapiness.  Now, it is just a dark ghostly shell ever-yearning\n"+
"to drain the life force of the living.\n");
   set_level(9);
   set_hp(random(30)+125);
   set_al(-500);
   set_wc(12);
   set_ac(7);
   set_aggressive(1);
}
