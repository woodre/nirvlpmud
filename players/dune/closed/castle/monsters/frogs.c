inherit "obj/monster";
#include "definitions.h"


reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("frog");
   set_short( "A giant red-striped frog");
   set_alias("frog");
   set_level(4);
   set_race("frog");
   set_hp(60);
   set_wc(8);
   set_ac(3);
   set_aggressive(1);
   set_long(
"        This frog sits 3 feet high. Quite a large frog. It has a thick\n"+
"red stripe running from the middle of its eyes to its hind legs. A set\n"+
"of wicked claws and a sharp horn make it a formidable enemy.\n");
}
