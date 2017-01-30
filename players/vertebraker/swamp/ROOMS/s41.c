#include "../define.h"
inherit SWAMP
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_long(
"    Amazingly, you didn't spot this before, but a massive crag rises\n"+
"directly in front of you, approximately thirty feet off the ground. \n"+
"There are definite stepping stones on the side of the cliff if you\n"+
"wish to attempt to ascend its heights, however.  Darkness enshrouds\n"+
"the apex of the cliff, but a small flame can be seen at the top.\n");
   add_exit(ROOMS+"s40","northwest");
   add_item("crag","You can see the crag rising before you.  You could \"climb\" it if you have the physical strength necessary");
   add_item("cliff","You can see the crag rising before you.  You could \"climb\" it if you have the physical strength necessary");
   add_item("stones","Stepping stones one has carved out for grappling the cliff");
   add_item("darkness","Blotchy darkness enshrouds the apex");
   add_item("apex","Blotchy darkness enshrouds the apex");
   add_item("flame","A single flickering flame");
}
init() {
   ::init();
   add_action("cmd_climb","climb");
}
cmd_climb(str) {
   int x;
   if(!str && str != "crag" && str != "cliff" && str != "stones") return 0;
   if(STRENGTH < 20) {
      x = random(3);
      if(!x) {
         write("You can't seem to grab the first rock!");
         say(TPN+" flails on the first rock!");
         return 1; }
      write("You scale the first rock....\n");
      say(TPN+" scales the first rock easily.\n");
      if(x == 1) {
         write("You fall from the next rock!\n");
         say(TPN+" reaches the second rock and falls off!\n");
         return 1; }
      write("You wheeze as you get to the third rock.\n");
      say(TPN+" coughs and wheezes as "+TP->query_subjective()+" gets to the third rock.\n");
      write("You fall from the third rock!\n");
      TP->heal_self(-random(20));
      say(TPN+" falls from the third rock into the swamp!\n");
      return 1; }
   write("With your massive strength and agility, you bound up the cliff.\n");
   say(TPN+" bounds up the cliff!\n");
   move_object(TP,ROOMS+"d1");
   return 1; }
