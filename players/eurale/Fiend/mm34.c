#include "DEFS.h"
inherit "room/room";

reset(arg) {
if(!present("phantom")) {
  move_object(clone_object("players/eurale/Fiend/NPC/phantom"),TO); }
if(!present("messenger")) {
  move_object(clone_object("players/eurale/Fiend/NPC/mess34"),TO); }
  if(arg) return;
set_light(0);

short_desc = "Opera House";
long_desc =
	"  This was once a proud opera house.  The floor slopes down to\n"+
	"a large, open stage.  Gas lights ring the curved front edge of\n"+
	"of the stage.  The rows of upholstered seats have many now broken\n"+
	"and quite a few missing.  The box seats still command a superior\n"+
	"view of both the stage and seating area.\n";

items = ({
	"stage","A curved wooden stage with rotting curtains",
	"lights","Metal protected gas lights which light the stage and\n"+
		"and shield the audience",
	"seats","Individual, stuffed seats",

});

dest_dir = ({
	"players/eurale/Fiend/mm33.c","exit",
});

}

init() {
  ::init();
  TP->set_fight_area();
}
