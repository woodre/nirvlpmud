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
   "     Clay torches are mounted on each wall to light up the landing\n"+
   "on the steps.  The walls are made of brimstone and fireshadows blaze\n"+
   "across them.  An opening cut into the wall leads back up into the\n"+
   "light.  The steps twist and turn out of sight.\n";

   
   items = ({
         "fireshadows","Blazing shadows of fire glowing across the walls",
          "landing","A platform between each flight of stairs",  
         "flame","A burning vapor glows at the top of the candle",
         "steps","The steps are steep and narrowed",
          "opening","The opening leads back 'up' to the crag",
         "torches","The base of the torches are made out of clay, a flame\n"+
         "is lit at the upper end",
         "clay torches","The base of the torches are made out of clay, a flame\n"+
         "is lit at the upper end",
         "base","The base is made out of clay",
         "walls","The walls are made out of brimstone",
         "wall","The wall is made out of brimstone",
          });
   
   dest_dir = ({
         "/players/brittany/kadath/k2.c","up",
         "/players/brittany/kadath/k4.c","down",
          });
}
  init(){ 
  ::init();
   add_action("search","search");
}
 
search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
