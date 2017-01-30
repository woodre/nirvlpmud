#include "../define.h"
inherit SWAMP
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_long(
"     An apparent dead end in the swamp, the cypress trees are tangled\n"+
"in ugly heaps on the sides of you.  A small babbling brook of murky\n"+
"green water carries on to the southeast through a small crevice in the\n"+
"'wall of vegetation'.  You can head back out to the west.\n");
   add_exit(ROOMS+"s13","west");
   add_item("trees","The cypress trees are tangled, preventing movement\nin any direction but west");
   add_item("cypress trees","The cypress trees are tangled, preventing movement\nin any direction but west");
   add_item("brook","The brook goes through a small crevice");
   add_item("crevice","Hmm.. you wonder if you could fit through there?\nIt's worth a try to \"squeeze\" on through");
   add_touch("brook","You feel the cold water");
   add_item("wall","A seeming wall of vegetation, perhaps?\nDuh");
}
init() {
   ::init();
   add_action("cmd_squeeze","squeeze");
}
cmd_squeeze(str) {
   if(!str) return 0;
   if(str == "through" || str == "crevice" || str == "on through") {
      if(STEALTH < random(10)) {
         write("You try to fit through, but fail.\n");
         return 1; }
      write("You squeeze perfectly through the small opening.\n");
      TP->move_player("through the crevice#"+ROOMS+"s34");
      return 1; }
}
