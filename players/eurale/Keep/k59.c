#include "/players/eurale/defs.h"
inherit "room/room";
int ONE;

reset(arg) {
  if(arg) return;
if(!present("centaur")) {
move_object(clone_object("players/eurale/Keep/NPC/endscape"),TO); }
set_light(1);
ONE = 0;

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  You stand in an open field of swaying grasses.  To the east\n"+
	"are some high rocks and to the north is the wooded area from\n"+
	"which you came.  The area is covered with small indentations\n"+
  "and some of the grass is flattened.  The sheer face of the western\n"+
  "rock wall runs straight up for at least 300 feet with a sizeable\n"+
  "crevass running jaggedly upward at least half way.\n";

items = ({
	"grasses","Knee deep grasses of deep green",
	"indentations","They look like the hoof prints of a horse",
	"crevass","A wide, jagged crack in the stone wall running\n"+
		  "from the floor upward.  If one were small enough,\n"+
		  "they might be able to wedge their way in",
});

dest_dir = ({
	"players/eurale/Keep/k58.c","north",
});

}

set_ONE(i) { ONE = i; }
query_ONE() { return ONE; }

init() {
  ::init();
  add_action("wedge","wedge");
}

wedge(str) {
if(!str) { write("Wedge where?\n"); return 1; }
if(str == "crevass" && ONE == 0) {
  write("You slowly but surely wedge your way back into the jagged\n"+
	"crevass until you reach a small nook.\n");
  say(capitalize(TPRN)+" squeezes into the jagged crevass and disappears.\n");
  TP->move_player("crevass#players/eurale/Keep/k65.c");
  ONE = 1;
  return 1; }
else {
  write("Your try with all your might but can't get into the crevass.\n");
  return 1; }
}
