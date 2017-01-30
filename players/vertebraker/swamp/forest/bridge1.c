#include "../define.h"
inherit ROOM;

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("On a dangerous bridge");
   set_long(
"     The mist here is incredibly intense, it rises and swirls,\n"+
"practically knocking you senseless with how dense it really is.  You\n"+
"can barely see the handholds on the bridge, and you try to catch\n"+
"your footing....\n");
   add_exit(FOREST+"e4","north");
   add_exit(FOREST+"bridge2","south");
   add_item("mist","You can't really make out anything because of the\n"+
      " sheer denseness");
   add_item("handholds","You can barely make out the rope handholds"); 
   set_chance(5);
   add_msg("The rope bridge shifts around, and you catch yourself...");
   add_msg("You carefully ease your way across the bridge...");
   add_msg("You breathe heavily...");
   add_msg("You almost gaze downwards but stop yourself before\n"+
      " looking down to the abyss..."); }

init() {
   ::init();
   add_action("bye","south");
   add_action("bye","north"); }

bye() {
   if(TP->query_attrib("ste") < random(13)) {
      write("You flail wildly with your steps...\n"+
         "\n\n\n\n\nYOU FALL OFF THE BRIDGE!!!\n\n\n\n\n\n");
      say(TPN+" slips and falls!!!!!\n");
      move_object(TP,"/room/south/sforst24");

      command("look",TP);
      return 1; } 
   write("You keep walking, never looking back...\n"); }
