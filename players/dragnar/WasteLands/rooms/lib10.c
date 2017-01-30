#define shit cult=clone_object("/players/dragnar/WasteLands/mons/cult.c");
#define fuck move_object(cult, this_object());
inherit "room/room";
object cult, master;
init() {
	::init();
  add_action("push","push");
	this_player()->set_fight_area();
}
reset(arg) {
/* shit fuck shit fuck shit fuck shit fuck  removed -Snow */
	shit
	fuck	
	master=clone_object("/players/dragnar/WasteLands/mons/cultmaster.c");
	move_object(master, this_object());
	if(arg) return;
set_light(1);
short_desc=("Wasteland's library");
long_desc=
"This room seems to be another type of meeting room.  There are candles\n"+
"lighted all over the room that cast a strange glow on the room.  In\n"+
"the center of the room is a large table and the rich mahogany paneling\n"+
"that lines the walls makes it feel warm and comfortable.\n",
items = ({
  "table","A large, richly polished wooden table",
  "paneling", "Beautiful wood paneling that looks just a tad loose.\n"+
	"Makes you want to push on it to see?",
});
dest_dir=
({
"players/dragnar/WasteLands/rooms/lib9.c","south",
});
}

push(str) {
if(present("member")) {
  write("The cult member pushes you back.\n"); return 1; }
if(!str) { write("Push what?\n"); return 1; }
if(str == "paneling") {
  this_player()->move_player("paneling#players/dragnar/WasteLands/rooms/Elib11.c");
  return 1; }
}
