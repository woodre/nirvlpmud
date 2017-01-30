#include "../define.h"
inherit ROOM;
reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A dimly lit forest");
   set_long(
"     The forest here has thinned out a bit.  You can see the remnants\n"+
"of a small village just to the south.  Grassy fields extend in front\n"+
"of you and a small statue and wooden sign are right in the middle of\n"+
"the clearing.\n");
   add_item(({"sign","wooden sign"}),"Try reading this");
   add_item(({"fields","grassy fields"}),
      "Beautiful grassy fields that extend for a while\n"+
      " and are the setting for the small village");
   add_item(({"remnants","village","small village"}),
      "The small village looms to the south, and you can make\n"+
      " out several small huts");
   add_item("statue","A beautiful marble statue of a stoic-looking human\n"+
      " standing on top of a detailed hill");
   add_item("clearing","This small clearing houses a small statue and\n"+
      " a wooden sign");
   add_exit(FOREST+"f4","northwest");
   set_chance(5);
   add_msg("You hear villagers south...");
   add_msg("Shouts can be heard from the village.");
   add_msg("A bunny hops by.");
   add_msg("It is very serene and calm here.");
   add_listen("main","You can hear shouting and calling from the village.");
   add_listen("shouting","You can make out what appears to be, \"seal-eh-uh\"?\nHmm.");
   add_exit(VILLAGE+"path1","south"); }

init() {
   ::init();
   add_action("read","read"); }

read(str) {
   if(str == "sign" || str == "the sign" || str == "wooden sign") {
      write("You read the wooden sign....\n");
      write("\n\n\t\t\tWelcome\n"+
         "\t\tto the village of Pratho\n\nVisitors welcome.\n");
      say(TPN+" reads the wooden sign.\n");
      return 1; }
}
