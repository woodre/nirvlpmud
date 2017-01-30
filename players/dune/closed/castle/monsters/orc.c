inherit "obj/monster";
#include "definitions.h"


reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("orc");
   set_short("An orc");
   set_alias("orc");
   set_level(4);
   set_race("orc");
   set_hp(60);
   set_wc(8);
   set_ac(4);
   set_aggressive(1);
   set_long(
"     The brownish green skinned orc stands about six and\n"+
"a half feet tall. It has black bristly hair, a large green snout,\n"+
"and pinkish brown ears.\n");
}
