#define HUNTER "/players/vertebraker/swamp/x1/npc"

#include "../define.h"
inherit ROOM;

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A village pathway");
   set_long(
"     A stretch of path leads along through this simple field.  You can\n"+
"see a small hut southeast, and you catch a glimpse of a small pool to\n"+
"the east, but heavy brush prevents you from getting to it.  The dark\n"+
"and foreboding forest lies back to the northwest.\n");
   add_item(({"path","stretch"}),"The stone-lined path stretches to the southeast and\n"+
      "back to the northwest");
   add_item(({"glimpse","pool","small pool"}),"A small pool is nestled into the brush to the east");
   add_item(({"forest","dark forest"}),"The dark and foreboding forest is northwest...");
   add_item(({"hut","small hut"}),"A small ramshackle hut made of simple hickory\n"+
      "and blood, sweat, and tears");
   add_item("field","Grass rises up on all sides of you, but it isn't very tall");
   add_object(NPC_DIR+"villager");
   add_exit(VILLAGE+"path2","northwest");
   add_exit(VILLAGE+"path4","southeast");
   set_chance(5);
   add_msg("A fly buzzes in front of your face.");
   add_msg("You hear laughing coming from the pool.");
   add_msg("Tufts of smoke rise from the small hut.");
   if(!find_living("gator hunter")) add_object(HUNTER);
   add_smell("main","You smell the smoke from the small hut."); }

init() {
   ::init();
   add_action("east","east"); }

east() {
   write("You try to force your way through the brush but fail.\n");
   say(TPN+" fails to force "+POS+" way through the brush.\n");
   return 1; }
