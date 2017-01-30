#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = MAG+"Kadath"+NORM;
   long_desc =
     "     This rocky crag overlooks a large cavern below.  Some steps\n"+       
     "have been dug into the cavern wall leading down.  Off in the\n"+
     "distance, the slopes of a large hill can be clearly seen with\n"+
     "snow in the higher elevations.  The huge gates can still be seen\n"+
     "off to the south.\n";

    items = ({
          "steps","The steps are steep and narrow",
         "slopes","The slopes inclined up a large hill",
          "crag","A steep rugged rock",
          "rocky crag","A steep rugged rock",
          "hill","A large hill with snow in the higher elevations",
          "large hill","A large hill with snow in the higher elevations",
         "snow","The snow has a yellowish tint",
          "cavern","A large cave with steps dug into its wall",
          "cavern wall","A large cave with steps dug into its wall",
          "wall","The wall of the cavern with steps dug into it",
         "huge gates","Some huge golden gates are south of here",
         "gates","Some huge golden gates are south of here",
           });
   
   dest_dir = ({
         "/players/brittany/kadath/k1.c","south",
         "/players/brittany/kadath/k3.c","down",
          });
}

init() {
   add_action("south","south");
   add_action("down","down");
   add_action("search","search");
}
south(str) {
   this_player()->move_player("south#/players/brittany/kadath/k1.c");
   return 1;
}
down(str) {
   this_player()->move_player("down#/players/brittany/kadath/k3.c");
   return 1;
}

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
