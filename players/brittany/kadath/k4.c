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
   "across them.  On the side of the steps is a sign.\n";
   
   
   items = ({
         "fireshadows","Blazing shadows of fire glowing across the walls",
         "flame","A burning vapor glows at the top of the candle",
         "landing","A platform between each flight of stairs",
         "steps","The steps are steep and narrowed",
         "sign","A metal sign nailed to a pole, maybe you could 'read' it",
         "pole","The pole is made of steel",
         "torches","The base of the torches are made out of clay, a flame\n"+        
         "is lit at the upper end",
         "clay torches","The base of the torches are made out of clay, a flame\n"+
         "is lit at the upper end",
         "base","The base is made out of clay",
         "walls","The walls are made out of brimstone",
         "wall","The wall is made out of brimstone",
          });
   
   dest_dir = ({
         "/players/brittany/kadath/k3.c","up",
         "/players/brittany/kadath/k5.c","down",
          });
}
   init(){
  ::init();
   add_action("search","search");
   add_action("read","read");
}

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}

read(str) {
    if(!str || str != "sign") {
        notify_fail("What do you want to read?\n");
        return 0; }
 
    write(
       "The Cavern of Flames is down.\n\n");
     return 1;
}
