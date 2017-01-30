#define tpn this_player()->query_name()
inherit "room/room";
int n;  /* note marker  0-gone, 1-there  */

reset(arg) {
n = 1;
  if(arg) return;
set_light(1);

short_desc = "Phantasm";
long_desc =
	"  You stand inside the gates of Phantasm.  Roads lead off in \n"+
	"lots of different directions.  There is a tall post with 7 signs \n"+
	"attached to the top. \n";

items = ({
	"signs","The signs read... \n\n"+
		"          Piglet Parkway -> north\n"+
		"       Memory Lane -> west\n"+
		"             Diamond Mine Drive -> southeast\n"+
		"          Timberwood Trail -> south\n"+
		"               Shade Lane -> northeast\n"+
		"        Westminster Bridge Road -> northwest\n"+
		"                 King's Way -> east\n"+
		"  \n\n",
	"post","You might try looking at the 'signs'",
});

dest_dir = ({
	"/players/eurale/Dis/rooms/greet.c","out",
	"/players/eurale/Dis/rooms/pp1.c","north",
	"players/eurale/Dis/Pino/twt1.c","south",
	"players/eurale/Dis/SnWht/dmd1.c","southeast",
	"players/eurale/Dis/rooms/ml1.c","west",
	"players/eurale/Dis/Slpy/sl1.c","northeast",
	"players/eurale/Dis/Pan/pc1.c","northwest",
	"players/eurale/Dis/Hood/rh1.c","east",
});

}

init() {
  ::init();
  add_action("search","search");
}

search() {
if(n == 0) {
  write("You dig around the area and find nothing.\n"); return 1; }
if(n == 1) {
  say(tpn+" finds something in the sand.\n");
  write("You dig around the base of the sign post and unturn an old\n");
  write("parchment note...\n");
  move_object(clone_object("players/eurale/Dis/misc/note.c"),
	this_player());
  n = 0;
  return 1; }
}
