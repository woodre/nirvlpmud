inherit "obj/monster";
#include "definitions.h"


reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("nymfotrites");
   set_short("Nymfotrites, the lesser devil");
   set_alias("nymfotrites");
   set_level(11);
   set_race("devil");
   set_hp(170);
   set_wc(16);
   set_ac(10);
   set_aggressive(1);
   set_long(
"     You look upon a gaunt stick-like creature. It has three horns\n"+
"and two glaring yellow eyes upon its red-skinned head. The diabolic\n"+
"Nymfotrites stands upon two goat hooves, a stunning picture of your\n"+
"classic devil.\n");
}
