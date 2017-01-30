#include "../define.h"
inherit ROOM;
int x;
reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A hidden grove");
   set_long(
"     Several tall trees stand in a huge semicircle around a large\n"+
"bunch of leaves that seems oddly out of place. You can see the forest\n"+
"back to the south, and you barely make out glimpses of a small village.\n");
   add_item(({"tall trees","trees"}),
      "The tall trees seem to have been placed in a huge\n"+
      " semicircle, though you can't imagine what would\n"+
      " have caused that");
   add_item(({"leaves","bunch of leaves","bunch"}),
      "Something seems to be under here.. dormant and could\n"+
      " be \"uncovered\"");
   add_item("forest","The tall trees of the forest stand all around you,\n"+
      " and especially south");
   add_item(({"glimpses","village"}),
      "You see the small reaches of a village extending just south\n"+
      " of the forest");
   add_exit(FOREST+"f4","south");
   set_chance(5);
   add_msg("The wind whistles through the trees....");
   add_msg("The wind blows around a few leaves, and it seems to uncover\n"+
      " something shiny....\n"+
      "Then it is recovered, almost magically...");
   add_msg("You notice no signs of life... how strange...");
   add_msg("A gust of wind takes you by surprise!"); 
   add_touch("leaves","You touch the leaves, trying to move them,\n"+
      " and they push themselves back into order");
   add_listen("main","You hear the wind..."); }

init() {
   ::init();
   add_action("uncover","uncover"); }

uncover(str) {
   if(!str) return;
   if(str == "leaves" || str == "bunch" || str == "the leaves" || str == "object") {
      if(x) {
         write("There is nothing else under the leaves....\n");
         return 1; }
      write("You uncover the object beneath the leaves...\n");
      say(TPN+" shifts the leaves around...\n");
      MO(CO(OBJ_DIR+"rusty_platemail"),TO);
      x = 1; 
      return 1; }
}
