inherit "obj/monster";
#include "definitions.h"


reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("catoblepas");
   set_short( "A catoblepas");
   set_alias("catoblepas");
   set_level(8);
   set_race("catoblepas");
   set_hp(120);
   set_wc(12);
   set_ac(7);
   set_long(
"     Before you stands a mighty catoblepas, feared for its death gaze.\n"+
"These creatures can be peaceful at times, unless provoked.\n"+
"The catoblepas stands 7 feet high. Its mighty jaws could possibly be\n"+
"quite dangerous. As you stand and look at it, it seems to be a cross\n"+
"between a hippo and a tiger.\n");
   set_chat_chance(10);
   load_chat("Catoblepas chews on grass, completely ignoring your presence.\n");
   load_chat("Catoblepas squats, and deposits a large pile of manure.\n");
}
