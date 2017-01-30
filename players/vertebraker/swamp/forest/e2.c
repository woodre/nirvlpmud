#include "../define.h"
inherit ROOM;

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A dimly lit forest");
   set_long(
"     The dark forest deepens here, and a small babbling creek floats\n"+
"lazily under a thick tree trunk.  A particularly large tree stands off\n"+
"to the side, and to both east and west, the forest continues to \n"+
"seemingly no end.\n");
   add_item("forest","The forest is very thick here");
   add_item("creek",
      "The small babbling creek bubbles up against the\n"+
      " side of the trunk, crossing beneath");
   add_item(({"tree","large tree"}),"The huge tree has something strange carved\n"+
      " into its bark");
   add_item("bark","Upon closer inspection, you see something\n"+
      " carved into the bark that you can read");
   add_item(({"trunk","tree trunk"}),
      "The large tree trunk blocks part of the stream, acting\n"+
      " as a natural dam, but the water passes beneath");
   add_item("water","The water is calm and crystal clear");
   add_touch("water","Cool to the touch...\n"+
      "You wonder if it is the same to drink?\n");
   add_exit(FOREST+"e1","east");
   add_exit(FOREST+"e3","west"); }

init() {
   ::init();
   add_action("drink","drink");
   add_action("read","read"); }

drink(str) {
   if(!str) return;
   if(str == "water" || str == "creek" || str == "the water") {
      write("You splash some water into your mouth...\n"+
         "It feels cool and refreshing.\n");
      sayy(TPN+" splashes some water into "+POS+" mouth.\n");
      return 1; }
}

read(str) {
   if(!str) return;
   if(str == "carving" || str == "tree" || str == "bark") {
      write("You read the strange carving...\n");
      say(TPN+" investigates the strange carving.\n");
      write("\n\n  RG + CS\n\n");
      write("Hmm.. What could this mean?\n");
      return 1; } }
