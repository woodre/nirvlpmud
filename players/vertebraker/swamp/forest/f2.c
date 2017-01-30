#include "../define.h"
inherit ROOM;

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A dimly lit forest");
   set_long(
"     A deep chasm lies to the west, and the forest continues to the\n"+
"east.  Rays of sunlight break through the cone branches on the trees \n"+
"around you, and you begin to wonder what time it actually is.  It\n"+
"appears to be quite peaceful here.\n");
   add_item(({"abyss","chasm"}),"A deep chasm lies to the west, and within its depths\n"+
      " you know not what lies");
   add_item("forest","The green, lush forest around you continues to\n"+
      " the west, and you may travel that direction");
   add_item(({"rays","sunlight"}),"Rays of sunlight strike you in the face\n"+
      " giving you a nice, warm feeling");
   add_item("trees","The forest has many trees, this is true");
   add_item("mist","A damp mist swirls up from the abyss, dampening\n"+
      " your pores");
   add_exit(FOREST+"f1","west");
   add_exit(FOREST+"f3","east");
   set_chance(5);
   add_msg("The mist swirls around you...");
   add_msg("A beam of sunlight dances into your retina, temporarily\n"+
      " blinding you!");
   add_msg("A breeze whistles through the trees...");
   add_msg("You sense as though you are not alone...\n"+
      " That feeling fades.. you _are_ alone.."); }
