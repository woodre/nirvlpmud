#include "../define.h"
inherit SWAMP
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_long(
      "     An apparent dead end in the swamp, the cypress trees are tangled\n"
      +"in ugly heaps on the sides of you.  A small babbling brook of murky\n"
      +"green water carries on to the northwest through a small crevice in\n"
      +"the 'wall of vegetation'.  You can head back out to the south.\n");
   add_exit(ROOMS+"s36","south");
   add_item("trees","The cypress trees are tangled, preventing movement\nin any direction but west");
   add_item("cypress trees","The cypress trees are tangled, preventing movement\nin any direction but west");
   add_item("brook","The brook goes through a small crevice");
   add_item("crevice","Hmm.. you wonder if you could fit through there?\nIt's worth a try to \"squeeze\" on through.\n");
   add_touch("brook","You feel the cold water.");
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
      TP->move_player("through the crevice#"+ROOMS+"s15");
      return 1; }
}
