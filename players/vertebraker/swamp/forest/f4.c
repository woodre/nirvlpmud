#include "../define.h"
inherit ROOM;
int x;
reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A dimly lit forest");
   add_property("NT");
   set_long(
"     As thick as thieves, the forest here has gotten dramatically\n"+
"larger and more full of verdant life and growth.  Tall sequoia trees\n"+
"block view and exit of anywhere except along the small path laid here.\n"+
"The sunlight pierces through the trees, lighting up the forest a bit\n"+
"for you to wander through.\n");
   add_item("forest","The tall green forest has overgrown the path here\n"+
      "and run up on all sides of you.\n"+
      "You think you see something next to one of the trees");
   add_item(({"life","growth","verdant life","undergrowth"}),
      "The undergrowth has grown up from the forest, preventing travel in\n"+
      "most directions except southeast and west");
   add_item("tree","You sense as though something is hiding behind the tree");
   add_item("sunlight","Bright beams pierce through onto your face and skin");
   add_item(({"trees","sequoias"}),
      "The tall sequoias stand as mammoths against this peaceful backdrop.\n"+
      "Something is strange about this spot");
   add_item(({"path","small path"}),
      "Weatherbeaten and well traveled, this path has has been\n"+
      "trampled out by many feet"); 
   add_exit(FOREST+"f3","west");
   add_exit(FOREST+"end","southeast");
}


cmd_search(str) {
   if(str == "tree" || str == "trees") {
      if(x) {
         write("You find nothing else...\n");
         return 1; }
      if(TP->query_attrib("int") < random(40)) {
         write("You search near the tree and find nothing...\n");
         return 1; }
      write("You search the tree and discover another path leading northwards.\n");
      say(TPN+" discovers a path amidst the forest.\n");
      x = 1;
      return 1; }
#ifndef __LDMUD__ /* Rumplemintz */
   ::cmd_search(str);
   return 1;
#else
  return 0;
#endif
}


north() {
   if(!x) return;
   write("You walk into the hidden path...\n");
   say(TPN+" leaves into the hidden path...\n");
   move_object(TP,FOREST+"hidden");
   command("look",TP);
   return 1; }

init() {
   ::init();
   add_action("north","north"); }
