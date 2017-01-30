#include "../define.h"
inherit ROOM;

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A thatched hut");
   set_long(
"     You are in a cozy little hut, with a small stone fireplace in the\n"+
"middle of the room.  A black cauldron bubbles over a few black coals\n"+
"on the other side of the room, and a small straw bed lies unmade in\n"+
"one corner of the room next to a small candleholder.  A strange little\n"+
"man stands there, looking you over.\n");
   add_item("fireplace","A well maintained stone fireplace that lies\n"+
      " currently dormant");
   add_item("coals","You gaze at the coals and see sparks . .  ");
   add_item(({"straw bed","bed"}),"A small unmade straw bed");
   add_item(({"candleholder","candles","candle"}),
      "A small candleholder with seven candles, lit brightly");
   add_item("cauldron","A dark black cauldron that seems to be cooking something.\n"+
      " You could open it up and see what's inside");
   add_object(NPC_DIR+"juribel");
   add_exit(VILLAGE+"path4","north"); }

init() {
   ::init();
   add_action("open","open"); }

open(str) {
   if(str == "pot" || str == "cauldron") {
      write("You open up the cauldron and peer inside...\n\n"+
         "  Blech!  Boiled squirrel!\n"+
         "You immediately slam the lid shut.\n");
      say(TPN+" opens up the cauldron and peers inside.\n"+
         TPN+" slams down the cauldron lid in a hurry!\n");
      return 1; }
}

new_long() {
   long_desc =       "   You are in a cozy little hut, with a small stone\n"+
   "fireplace in the middle of the room.  A black cauldron\n"+
   "bubbles over a few black coals on the other side\n"+
   "of the room, and a small straw bed lies unmade\n"+
   "in one corner of the room next to a small candleholder.\n";
}
