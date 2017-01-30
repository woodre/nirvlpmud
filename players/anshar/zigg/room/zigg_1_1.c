#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"
inherit "room/room";

reset(arg) {
  if (arg) return 0;

  set_light(1);
  short_desc=("Before the zigguraut");
  long_desc="    A tiered zigguraut stands here, its crumbling facade still\n"+
            "standing despite the encroaching flora that seems to cling to \n"+
            "the building, obscuring it effectively. The air of neglect that\n"+
            "permeates the structure is only offset by the flickering glow\n"+
            "which shimmers down from atop the monolithic edifice.\n";
  items=({
    "zigguraut",  "A large pyramidical structure made of light-coloured stone",
    "structure",  "A large pyramidical structure made of light-coloured stone",
    "building",  "A large pyramidical structure made of light-coloured stone",
    "edifice",  "A large pyramidical structure made of light-coloured stone",
    "facade",    "With the shadows and the vegetation, it appears almost alive",
    "flora",  "Vines and plants have encroached, covering the building",
    "vegetation",  "Vines and plants have encroached, covering the building",
    "vines",  "The vines cling to the building, you could search them",
    "plants",  "The plants cling to the building, you could search them",
    "glow", "A shimmering glow coming from somewhere on top of the zigguraut",
  });
  dest_dir=({
    FROOM+"path4", "back",
  });
}
init() {
   ::init();
     add_action ("search", "search");
     add_action ("enter_darkness", "enter");
   }

search(str) {
     if(!str || str != "vines" || str!= "plants") { 
     notify_fail("You find nothing of importance.\n");
     return 0; }
     write("You see darkness beyond the vegetation, you could enter it, perhaps.\n");
     return 1;
}

enter_darkness(str) {
     if(!str || str != "darkness") { 
     notify_fail("Enter what?\n");
     return 0; }
     write("You enter into the darkness.\n");
     this_player()->move_player("darkness#"+ZROOM+"zigg_1_4");
     return 1;
}

realm() {return "NT"; }
