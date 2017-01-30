#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
	if(!present("tablet", this_object())){
		move_object(clone_object("players/boltar/templar/items/tablet"), this_object());
		}
  if(arg) return;
set_light(1);

short_desc = "main entry hall "+HIW+"["+NORM+GRN+"Fortress Stone"+HIW+"]"+NORM+"";
long_desc =
"   This is the main entry hall of the Templar Castle. It is in\n"+
"the shape of an octagon, with large pillars rising up in each\n"+
"of the corners. Colorful banners line the walls. A beautiful\n"+
"painting can be found on the ceiling. To the north is a long\n"+
"hallway. The doorway to the church is to the west. To the east\n"+
"lies the Inner chamber of the Knights, where wanna-be knights\n"+
"go to join the guild. To the south is the castle's courtyard.\n";

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
  "/players/maledicta/templar/rooms/hallway1","north",
  "/players/maledicta/templar/rooms/courtyard","south",
  "/players/maledicta/templar/rooms/church","west",
  "/players/maledicta/templar/rooms/nrecruit","east",
});

}

init(){ 
 ::init();
  this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }



