#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = RED+"Dragonland"+NORM;
   long_desc =
   "     A high range of mountains surround the area.  The mountains\n"+
   "are in the shape of a bear.  One mountain is a steeply sloped peak,\n"+
   "bare of any vegetation.  You notice some kind of nest at the peak.\n"+
   "A narrow entrance is carved into the side of it.  North of here,\n"+
   "in between some more mountains is a large passage.\n";
   
   items = ({
         "boulder","A huge rock with an imprint of a hairy fist knocked into it",
          });

   dest_dir = ({
         "/players/brittany/xanth/earth1.c","west",
         "/players/brittany/xanth/dragonet.c","north",        
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
