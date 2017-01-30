#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = RED+"Dragon cave"+NORM;
   long_desc =
   "     The cave entrance is narrow, but it leads to a large cavern\n"+
   "within.  The passage gradually widens into some sort of chamber.\n"+
   "Some of the floor is taken up by a black pool of water.  In the\n"+
   "corner of the chamber is another narrow passage.\n";
   
   items = ({
         "boulder","A huge rock with an imprint of a hairy fist knocked into it",
          });

   dest_dir = ({
         "/players/brittany/xanth/dragonland.c","out",        
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
