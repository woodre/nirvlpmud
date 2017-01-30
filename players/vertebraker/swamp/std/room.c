/*
* inherit swamp room for the shi'ah swamplands
* by Vert@Nirvana April '00
* UPDATES:
* 6-17 : added check if the dir is valid, toned down room msgs.
   * 7-29 : added gelatinous boot support
*/
#include "../define.h"
#define BOOTS present("boots",TP)
inherit ROOM;
reset(arg) {
   if(arg) return;
   set_short(HIG+"T"+NORM+GRN+"he "+HIG+"S"+NORM+GRN+"hi'ah "+HIG+"S"+NORM+GRN+"wamp"+HIG+"L"+NORM+GRN+"ands"+NORM);
   set_light(1);
   add_property("PK");
   if(!random(2)) add_property("NT");
   add_object(NPC_DIR+"beast");
   if(!random(3)) add_object(NPC_DIR+"beast");
   set_chance(3);
   add_msg("The swamp churns and bubbles.....");
   add_msg("A cold breeze seeps through the area.....");
   add_msg("You can hear the sounds of wildlife all around you.....");
   add_msg("Two bulbous eyes rise from the waters and quickly submerge....");
   add_msg("...ribbbit...");
   add_msg("*croak* *croak*");
   add_msg("A firefly zips by your head.");
   add_msg("- HOOT! HOOT! -");
   add_msg("wooewooooo. woooewooooo.");
}



move(str) {
   int x;
   x = random(30);
    if(this_player()->is_player())
    if((!BOOTS || !BOOTS->query_gelatin()) && STEALTH < x && !TP->query_mounted()) {
      switch(random(3)) {
         case 0: write("You slip and fall in the swamp's moisture!\n"); say(TPN+" slips in "+POS+" haste!\n"); break;
         case 1: write("You trip over a root and land sprawling on the floor!\n"); say(TPN+" trips over a root and lands sprawling on the floor!\n"); TP->hit_player(-random(10)); break;
         case 2: write("You suddenly get dizzy.....\n"); say(TPN+" stumbles around the room in a daze.....\n"); break; }
      return 1; }
   switch(random(3)) {
      case 0: write("You trod deeper into the swamp......\n"); break;
      case 1: write("Sludging through the swamp, you begin to tire.....\n"); break;
      case 2: write("You slosh through the disgusting muck......\n"); break;
   }
   ::move(str);
   return 1;
}

set_long(li) { long_desc = GRN+li+NORM; }
query_swamp() { return 1; }

okay_follow() { return 1; }
