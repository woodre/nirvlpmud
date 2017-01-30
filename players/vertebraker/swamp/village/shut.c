#include "../define.h"
inherit ROOM;
int potion;

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Denis's Hut");
   set_long(
      "     You stand in a small grass hut with a brush rug on the floor and\n"+
      "several glimmering glass bottles above your head on a wooden ledge.\n"+
      "A squawking bird rests in a small cage, and a simple straw bed is on\n"+
      "the other side of the room.\n");
   add_item("bottles","Small clear glass bottles rest on a shelf above your head");
   add_item(({"ledge","shelf"}),"A wooden ledge holds an array of glass bottles");
   add_item("bird","A small green parrot is perched in his cage");
   add_item("cage","A steel cage holds a small squawking parrot");
   add_listen("main","You hear the squawking of the parrot");
   set_chance(4);
   add_msg("Squawking comes from the cage...");
   add_object(NPC_DIR+"shaman"); 
   add_exit(VILLAGE+"path5","south"); }



