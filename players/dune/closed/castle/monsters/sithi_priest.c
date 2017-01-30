inherit "obj/monster";
#include "definitions.h"



id(str)
{
  return str == "sithi" || str == "priest";
}


reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("sithi priest");
   set_race("sithi");
   set_alias("sithi");
   set_short("A Sithi Priest");
   set_long(
"     The Sithi Priest wears long sharp-colored robes and covers\n"+
"its head with a large hood. The priest has eyes as black as coals.\n"+
"Perhaps this Sithi used to be good at heart, but now it is pure evil.\n");
   set_level(8);
   set_hp(random(20)+125);
   set_al(-500);
   set_wc(13);
   set_ac(7);
   if(random(5) == 2) set_aggressive(1);
}
