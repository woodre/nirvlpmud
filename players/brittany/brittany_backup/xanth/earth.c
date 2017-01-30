#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = RED+"Earth Region"+NORM;
   long_desc =
   "     The ground quakes beneath your feet.  An unscalable mountain range\n"+
   "is visible to the northeast, and a huge volcano spewing lava can be seen\n"+
   "at the northern end of the region, on the border between Earth and Fire.\n"+
   "Rock plants and other sturdy growths are produced in the soils, which\n"+
   "range from barren to wildly fertile.\n";
   
   items = ({
         "boulder","A huge rock with an imprint of a hairy fist knocked into it",
         "trees","Odd shaped trees, some red and some blue",
          });

   dest_dir = ({
         "/players/brittany/xanth/fen.c","east",        
         "/players/brittany/xanth/earth1","north",
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
