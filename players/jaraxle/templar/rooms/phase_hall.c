#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

#include "/players/jaraxle/define.h"
inherit "room/room";


reset(arg) {


  if(arg) return;
set_light(1);

/* Room descriptions modified by Jara */

short_desc = ""+HIW+"Sanctuary ["+NORM+GRN+"Fortress Stone"+HIW+"]"+NORM;
long_desc =
"  The Sanctuary within the Fortress Stone is a modest room. The walls\n"+
"are made of stone, and two small windows overlook the courtyard below\n"+
"and beyond to the forests. A torch lights the spiral staircase that\n"+
"leads down to the inner chambers.\n";

items = ({
    "walls","The grey stone slabs make up the circular walls of the Sanctuary",
    "windows","The small windows are unbarred and a fresh breeze drifts in",
    "torch","A torch mounted upon the stone wall",
    "staircase","A narrow stone, spiral stairwell descending from the Sanctuary",
});

dest_dir = ({
  "/players/jaraxle/templar/rooms/adv_inner.c","down",
});

}

init(){ 
  ::init();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }



realm(){ return "NT"; }


