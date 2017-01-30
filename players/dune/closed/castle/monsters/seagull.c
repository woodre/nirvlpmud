inherit "obj/monster";
#include "definitions.h"


reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("seagull");
   set_short("A seagull");
   set_alias("seagull");
   set_level(4);
   set_race("seagull");
   set_hp(60);
   set_wc(8);
   set_ac(3);
   set_long(
"     The gray and white sea-faring bird is a common denizen near ocean\n"+
"shores. Its yellow beak can cut into small shells with ease.\n");
}
