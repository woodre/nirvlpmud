#include "DEFS.h"
inherit "room/room";
int p2;

reset(arg) {
p2 = 1;

if(!present("wolf")) {
  move_object(clone_object("players/eurale/Dis/rooms/NPC/wolf"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Comfortable lair";
long_desc =
	"  You have entered a very comfortable lair.  There is a well-\n"+
	"padded bed on the floor, a hanging oil lamp for light and even \n"+
	"a small spit for roasting dinner at one's leisure.\n";
items = ({
	"bed","A thick layer of pine boughs and a warm, down-filled \n"+
		"comforter for cover",
	"lamp","A large, shaded oil lamp to light the area",
	"spit","A rock-surrounded spit, large enough for roasting a pig",
});

dest_dir = ({
	"players/eurale/Dis/rooms/pp7.c","out",
});

}

init() {
  ::init();
  add_action("Search","search");
}

Search(str) {
if(!str) { write("What would you search?\n"); return 1; }
if(str == "spit") {
  if(p2 == 1) {
    write("You search through the spit ashes and find a puzzle piece.\n");
    move_object(clone_object("players/eurale/Dis/misc/puz2.c"),TP);
    p2 = 0;
    return 1; }
  if(!present("wolf") && (p2 == 0)) {
    write("You search through the ashes and find nothing.\n");
    return 1; }
 return 1; }
return 1;
}
