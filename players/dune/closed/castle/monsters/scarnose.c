inherit "obj/monster";
#include "definitions.h"


reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("Scarnose");
   set_alias("scarnose");
   set_short("Scarnose the orc");
   set_level(6);
   set_race("orc");
   set_hp(90);
   set_wc(10);
   set_ac(5);
   set_long(
"     This orc wears all-black clothing and has bluish skin.\n"+
"It is somewhat stronger than other orcs you have seen.\n"+
"A long scar runs from between its eyes to the end\n"+
"of its snout.\n");
   set_chat_chance(10);
   load_chat("Scarnose says: These tunnels are mine! Move out.\n");
}
