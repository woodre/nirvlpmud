#include "/players/jaraxle/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIW+"Castle Gates ["+NORM+GRN+"Fortress Stone "+HIW+"]"+NORM+"";
long_desc =
"  The gate to the castle stands tall, open to the courtyard to the\n"+
"south. The aged stone bricks of the castle are a bleached grey, and\n"+
"show signs of wear. Banners bearing the cross of the Knights Templar\n"+
"flap gently overhead, lifted occasionally by a gentle breeze passing\n"+
"through. A long hallway is visible just within the gate to the castle\n"+
"and a beautiful courtyard lies to the south.\n";

items = ({
"pillars",
"Large marble pillars of great beauty and design",
"banners",
"Heavy cloth banners of purist white, each with a large red\n"+
"cross weaved into its frabric. It is bordered in gold",
"painting",
"A magnificent mural of a glorious battle from long ago",
"ceiling",
"A well crafted stone ceiling with a carefully painted picture\n"+
"upon its surface",
});

dest_dir = ({
  "/players/jaraxle/templar/rooms/hallway1","north",
  "/players/jaraxle/templar/rooms/courtyard","south",
});

}

init(){ 
 ::init();
  this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }



