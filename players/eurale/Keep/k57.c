#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

if(!present("crystalmir centaur")) {
move_object(clone_object("players/eurale/Keep/NPC/crystal"),TO); }
if(!present("abanasinian centaur")) {
move_object(clone_object("players/eurale/Keep/NPC/abanas"),TO); }
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  You stand in an open field of swaying grasses.  To the east\n"+
	"are some high rocks and to the south is the wooded area from\n"+
	"which you came.  The area is covered with small indentations\n"+
	"and some of the grass is flattened.\n";

items = ({
	"grasses","Knee deep grasses of deep green",
	"indentations","They look like the hoof prints of a horse",
});

dest_dir = ({
	"players/eurale/Keep/k58.c","south",
});

}
