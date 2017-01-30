#define shit cult=clone_object("/players/dragnar/WasteLands/mons/cult.c");
#define fuck move_object(cult, this_object());
inherit "room/room";
object cult, master;
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
/* shit fuck shit fuck shit fuck shit fuck  removed -Snow */
	shit
	fuck
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
"the center of the room is a large table, and what seems to be a knife.\n",
dest_dir=
({
"players/dragnar/WasteLands/rooms/lib6.c","west",
});
}
