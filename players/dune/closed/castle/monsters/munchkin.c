inherit "obj/monster";
#include "definitions.h"


reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("munchkin");
   set_short("A cave munchkin");
   set_alias("munchkin");
   set_level(3);
   set_race("cave munchkin");
   set_hp(45);
   set_wc(7);
   set_ac(4);
   set_aggressive(1);
   set_long(
"     This is a 1' tall human-like being. The cave munchkin has white\n"+
"skin and dark black eyes. The most noticeable thing about the munchkin\n"+
"though, is a huge set of fangs protruding from its mouth.\n");
}
