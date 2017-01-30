#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = BLU+"A garden"+NORM;
   long_desc =
   "     The path is very confusing, it makes a hairpin curve and a few\n"+
   "nasty jags and jigs.  It branches and intersects another path.  The\n"+
   "path north of here looks slightly different.\n";
   
   items = ({
         "north path","The path looks soft and cloudy",
         "path north","The looks soft and cloudy",
         "path","Vegetable patches are growing all over the path",
         "patches","Awful spinach grew about, along with turnips, radishes\n"+
         "and onions",
         "spinach","A herbaceous annual, with succulent leaves",
         "turnips","Thick, fleshy, edible roots, that you can 'pick'",
         "radishes","Crisp, pungent, edible roots that you can 'eat' raw",
         "curve","A continuous bending path",
          });

   dest_dir = ({
      "/players/brittany/xanth/gourd.c","west",  
     "/players/brittany/xanth/vgarden.c","east",
         "players/brittany/xanth/garden.c","north",
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
