#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = WHT+"Birdland"+NORM;
   long_desc =
   "     You enter a small pool area.  The area is stocked with perch\n"+
   "that are lined with several small bird-nests.  On one side\n"+
   "of the pool, there are some high boulders stacked on top of\n"+
   "each other.  There is a waterfall running through it.\n",
   
   items = ({
         "boulder","A huge rock with an imprint of a hairy fist knocked into it",
          });

   dest_dir = ({
         "/players/brittany/xanth/fire.c","north",        
         "/players/brittany/xanth/air.c","south",
         "/players/brittany/xanth/water.c","east",
         "/players/brittany/xanth/earth.c","west",
              });
}

init() {
   ::init();
   add_action("search","search");
  }

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
