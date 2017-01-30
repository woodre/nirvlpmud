#include "../define.h"
inherit SWAMP

reset(arg) {
   if(arg) return;
   ::reset();
   set_long(
"     A dark, black cavern stands in front of you menacingly, as the \n"+
"swamp's foliage and jungle-like atmosphere swallows any other \n"+
"possible retreat than west.  You notice strange amounts of blood\n"+
"draped all around the trees in the immediate area, and you wonder\n"+
"what lurks inside.\n");
   add_item(({"cavern","cave"}),
      "The dark, menacing cavern seems to taunt you...\n"+
      " Wondering if you will \"enter\" its mouth...");
   add_item(({"blood","bloodstains",}),
      "The gratuitous amounts of blood tip you off that something\n"+
      " dark and evil lies within the cave....");
   add_item(({"foliage","trees"}),
      "The dark green foliage is in deep contrast to the\n"+
      " light red bloodstains all over the leaves");
   add_item("leaves",
      "The leaves are soaked with blood");
   add_exit(ROOMS+"s36","west"); 
   add_msg("You sense as though the cavern is beckoning you to enter....");
   add_msg("You get a bad feeling about the cavern..."); }

init() {
   ::init();
   add_action("enter","enter"); }

enter() {
   write("You enter the depths of the cavern....\n");
   say(TPN+" descends into the cavern....\n");
   MO(TP,ROOMS+"c1");
   return 1; }
