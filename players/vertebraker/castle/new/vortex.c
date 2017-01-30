#include "../../define.h"
#define PATH "/players/vertebraker/castle/new/"
inherit ROOM;

reset(x) {
   if(x) return;
   set_light(1);
   set_short("A clearing in the woods");
   set_long(
      "    A tall signpost stands here, with several signs sticking\n"+
      "from its broad form.  The trees have been cleared out a bit\n"+
      "here, and several dusty paths leave in different directions.\n"+
      "It is quiet and serene in this part of the forest.\n");
   add_listen("main","You hear nothing but your own breathing");
   add_item("signs","Try looking at the signpost");
   add_item("trees",
      "The tall trees are still omnipresent in this part of the forest,\n"+
      "carefully watching your every move, but they have been spread apart\n"+
      "more");
   add_item("paths",
      "Several different dusty paths spread in several directions, each marked\n"+
      "with a sign on the signpost");
   add_object(PATH+"signpost");
   
   add_exit("/players/vertebraker/swamp/forest/e1","west");
   add_exit(PATH+"bvortex","east");
   add_exit(PATH+"n0","north");
   add_exit("PUT_FRALAPA_ENTRANCE_HERE","south");
   add_exit("PUT_DWARVEN_TUNNELS_ENTRANCE_HERE","southwest");
   
}

init() {
   ::init();
   add_action("block_it","south");
   add_action("block_it_part_deux","southwest"); }

block_it() {
   write("A thick log has rolled over this part of the path.  Despite\n"+
      "your best attempts to move it, it seems as though Sin'tara is\n"+
      "unacccesible at this time.\n");
   return 1; }

block_it_part_deux() {
   write("You start to head southwest, but a large wooden sign stops you\n"+
      "dead in your tracks.\n\n"+
      BOLD+"    TUNNELS CLOSED BY ORDER OF MASTER SMITH VURGAK...\n\n"+NORM);
   return 1; }

