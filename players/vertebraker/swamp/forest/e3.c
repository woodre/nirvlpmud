#include "../define.h"
inherit ROOM;

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A dimly lit forest");
   set_long(
"     A massive abyss stretches from the cliff you are standing upon to\n"+
"the other edge of the forest.  Crisp foilage and puffy evergreen trees\n"+
"decorate the remaining landscape here, and you see needles covering the\n"+
"forest floor.\n");
   add_item("forest","The dark forest stops to the southwest,\n"+
      " where the abyss separates the forest");
   add_item("abyss","The massive abyss stretches from this end of the cliff\n"+
      " to the other cliff on the opposite edge of Nirvana");
   add_item("bushes","Beautiful green bushes hedge the side of the forest");
   add_item(({"evergreen trees","trees"}),
      "Short, spiny evergreen trees decorate the landscape around\n"+
      " you");
   add_item("needles","Pine needles cover the forest floor");
   add_item("cliff","The cliff you are on ends near the huge abyss");
   set_chance(5);
   add_msg("You sense a certain calmness with your surroundings.");
   add_msg("A bunny hops by, then dives into the bushes.");
   add_msg("A faint strand of mist floats into the room\n"+
      " and then exits.....");
   add_exit(FOREST+"e2","east");
   add_exit(FOREST+"e4","southwest"); }
