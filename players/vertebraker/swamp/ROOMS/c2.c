#include "../define.h"
inherit ROOM;

id(str) {
   if(str == "mirror") {
      write("You gaze into the mirror...\n");
      write(BOLD+BLK);
      TP->long();
      write(NORM);
      say(TPN+" gazes into the mirror...\n");
      return 1;
   }
   return ::id(str);
}

reset(arg) {
   object co;
   if(arg) return;
   set_short("A dark cavern");
   set_long(
"     A grotesque amount of gore and blood stains the walls here, and\n"+
"you notice a red puddle on the floor.  You see a pile of what appear\n"+
"to be human entrails, and that sends you retching.  A dirty mirror\n"+
"hangs across the back of the cave.\n");
   add_exit(ROOMS+"c1","north");
   MO(CO(NPC_DIR+"changeling"),TO);
   co = clone_object("/obj/corpse");
   co->set_level(1);
   co->set_name("celia");
   co->set_short("A corpse of a human girl [half-eaten]");
   co->set_long(
      "A disgusting remnant of what once was a small\n"+
      " human being.  You can only guess that is what\n"+
      " left of Celia.\n");
   MO(co,TO);
   add_item(({"gore","blood"}),
      "Insane amounts of blood, as though it was drained\n"+
      " from a corpse...");
   add_item("puddle",
      "A thick puddle of coagulated blood, in the middle\n"+
      " of which you can see a human heart");
   add_item(({"entrails","pile"}),
      "Intestinal tracts.. stomach lining...\n"+
      " generally nasty stuff"); }

