inherit "obj/monster";
#include "definitions.h"


reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("hawk");
   set_short( "A hawk");
   set_alias("hawk");
   set_level(4);
   set_race("hawk");
   set_hp(60);
   set_wc(8);
   set_ac(4);
   set_long(
"     The common brown feathered hawk flies the plain skies\n"+
"in search of prey. Its sharp talons could give a nasty scratch.\n");
}
