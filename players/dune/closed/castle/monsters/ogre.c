inherit "obj/monster";
#include "definitions.h"


reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("ogre");
   set_short( "An ogre");
   set_alias("ogre");
   set_level(7);
   set_race("ogre");
   set_hp(100);
   set_wc(11);
   set_ac(5);
   set_aggressive(1);
   set_long(
"     The ogre is a tall heavy-set humanoid. Its skin is mottled yellow\n"+
"and brown.  Several warts dot its thick skin. It has purple eyes and\n"+
"eyes orange teeth.\n");
}
