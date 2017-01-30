#include "DEFS.h"
inherit "room/room";

reset(arg) {
if(!present("woman")) {
  move_object(clone_object("players/eurale/Dis/Pan/NPC/woman"),TO); }
if(!present("man")) {
  move_object(clone_object("players/eurale/Dis/Pan/NPC/man"),TO); }
  if(arg) return;
set_light(1);

short_desc = "Brownstone House";
long_desc =
	"  You have entered one of the beautiful brownstone houses that\n"+
	"circle the park along Picadilly Circle.  These houses are\n"+
	"built up rather than out to conserve space.  There is a large\n"+
	"window looking out of this living area.  An overstuffed chair\n"+
	"and couch provide ample seating for any guests.  There is a\n"+
	"door that is closed, presumably to the upstairs.\n";

items = ({
	"window","The window looks out on Picadilly Circle and the park",
	"chair","A tapestry covered easy chair",
	"couch","A tapestry covered couch, extra long",
	"door","A 6-panel, solid wood door",
});

dest_dir = ({
	"players/eurale/Dis/Pan/pc8.c","out",
});

}

init() {
  ::init();
  add_action("open","open"); }

open(str) {
  if(!str) { write("What are you trying to open?\n"); return 1; }
  if(str == "door") {
    write("The door is locked and cannot be opened.\n"); return 1; }
return 1;
}
