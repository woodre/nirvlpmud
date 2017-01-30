#include "../define.h"
inherit SWAMP
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_long(
      "     The marsh continues, wrapping to the southwest and northwards,\n"
      +"but you are trapped on all other sides by gigantic root-like plants\n"
      +"that spring from the ground.  The waters have become still here, and\n"
      +"much of the surrounding area lies undisturbed.\n");
   add_item("marsh","Lush green forested swampland that extends for miles");
   add_item("plants","Large, verdant plants that spring from the grounds\nand spiral like twisted roots\nOne in particular stands out");
   add_item("plant","This large plant spirals up to the sky about sixteen feet above\nyour head.  You could try climbing it");
   add_item("waters","Still and undisturbed waters that ripple as you move");
   add_item("area","It hasn't seen much use");
   add_exit(ROOMS+"s43","north");
   add_exit(ROOMS+"s44","southwest");
}
init() {
   ::init();
   add_action("cmd_climb","climb"); }
cmd_climb(str) {
   if(!str) {
      FAIL("Climb what?\n"); return 0; }
   write("You begin climbing up the plant....\n\n");
   say(TPN+" begins climbing the plant.....\n\n");
   if(STEALTH < random(30)) {
      write("You fall from the plant with a resounding *thunk*!\n");
      say(TPN+" falls from the plant with a resounding *thunk*!\n");
      TP->heal_self(-(10+random(20)));
      return 1; }
   write("You make it all the way up the plant!\n");
   say(TPN+" makes it all the way up the plant!\n");
   move_object(TP,ROOMS+"sky_view");
  command("look",TP);
   return 1; }
