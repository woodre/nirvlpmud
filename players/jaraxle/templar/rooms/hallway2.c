#include "/players/jaraxle/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

object guards;

reset(arg) {
if(!present("high_guard", this_object())){
  move_object(clone_object("/players/jaraxle/templar/mobs/high_templar.c"), this_object());
  }
  if(arg) return;
set_light(1);

short_desc = HIW+"A hallway ["+NORM+GRN+"Fortress Stone"+HIW+"]"+NORM+"";
long_desc =
"  The hallway here opens up into a spacious room. Four marble pillars\n"+
"stand in each corner, lending support to the ceiling overhead. A few\n"+
"banners hang from poles high above, and torches cast enough light to\n"+
"see the exits visible from the room. There is a passage leading west\n"+
"and the hall itself continues to the north and south.\n";
move_object(clone_object("/players/jaraxle/templar/mobs/high_templar.c"), this_object());
items = ({
"pillars",
"Massive pillars of marble, laced with blue veins and well polished",
"passage",
"A dimly lit passage leading into the western wing of the castle",
});

dest_dir = ({
  "/players/jaraxle/templar/rooms/adv_inner","north",
  "/players/jaraxle/templar/rooms/nrecruit","east",
  "/players/jaraxle/templar/rooms/hallway1","south",
  "/players/jaraxle/templar/rooms/quest","west",
});

}


init(){ 
  ::init();
   this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }
