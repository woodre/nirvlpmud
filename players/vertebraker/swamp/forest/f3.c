#include "../define.h"
inherit ROOM;

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A dimly lit forest");
   set_long(
"     Short evergreens decorate the foresting here, as they sprout out\n"+
"along the path you walk.  A long wooden rope bridge sits more to the\n"+
"west and the forest seems to deepen as you look east, becoming more\n"+
"dark and menacing.\n");
   add_item(({"squirrels","critters","rabbits"}),
      "Squirrels and rabbits wander along the path\n"+
      " and then dart back into the forest's bowels\n"+
      " when they catch a glimpse of you");
   add_item("evergreens",
      "Short, stocky little trees that are built low to the\n"+
      " ground and decorate the landscape");
   add_exit(FOREST+"f2","west");
   add_exit(FOREST+"f4","east");
   add_item("path",
      "The beaten path you walk has been traveled by many,\n"+
      " but you see no other people around");
   add_item(({"bridge","rope bridge"}),
      "A long wood and rope bridge stretches across what appears\n"+
      " to be a chasm to the west");
   add_item("chasm","A pit with a swirling mist that seems to rise in front\n"+
      " of its reaches so you cannot really tell how deep it is");
   add_item("mist","The mist swirls up from the bowels of the chasm .. .  ");
   add_item("trees","Trees are all around you- this is the forest");
   add_item("forest","The forest seems to be a living entity of its own...\n"+
      "To the east it seems to level out");
   add_listen("main","You hear the rope bridge creak as someone attempts to walk across it..."); }
