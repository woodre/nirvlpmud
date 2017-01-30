inherit "obj/monster";
#include "definitions.h"


reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("snake");
   set_short( "A huge blue-skinned snake");
   set_alias("snake");
   set_level(3);
   set_race("snake");
   set_hp(45);
   set_wc(7);
   set_ac(4);
   set_aggressive(1);
   set_long(
"     You see a 1-foot thick, 7-foot long snake. Its eyes are cruelly\n"+
"gazing at you. Its blue skin looks muscular, yet weak.\n");
}
