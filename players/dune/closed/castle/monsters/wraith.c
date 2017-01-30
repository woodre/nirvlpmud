inherit "obj/monster";
#include "definitions.h"


id(str)
{
  return str == "wraith" || str == "undead";
}


reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("wraith");
   set_race("undead");
   set_alias("wraith");
   set_short("A Wraith");
   set_long(
"     The Wraith is a culmination of super-negative power and the\n"+
"evil thoughts of the living. It was and always will be a being of\n"+
"evil. The Wraith has no form. It is a life draining spectre of\n"+
"unlife.\n");
   set_level(10);
   set_hp(random(20)+165);
   set_al(-950);
   set_wc(13);
   set_ac(8);
   set_aggressive(1);
}
