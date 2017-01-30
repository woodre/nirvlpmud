#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = RED+"Forbidden Region"+NORM;
   long_desc =
   "     Inside the border of the Region of Air, dust storms roil and tumble.\n"+
   "There is no vegetation, just sand in dunes and valleys, and stone cliffs.\n"+
   "Sand is driven against the cliffs by blowing winds.  The region is\n"+
   "surrounded by a cyclone fence.\n";
   
   items = ({
         "boulder","A huge rock with an imprint of a hairy fist knocked into it",
          });

   dest_dir = ({
         "/players/brittany/xanth/fire.c","north",        
      "/players/brittany/xanth/dragonland.c","east",
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
