#define shit cult=clone_object("/players/dragnar/mons/cult.c");
#define fuck move_object(cult, this_object());
inherit "room/room";
object cult, master;
init() {
	::init();
	this_player()->set_fight_area();
	add_action("north","north");
}
reset(arg) {
/* shit fuck shit fuck shit fuck shit fuck  removed -Snow */
	shit
	fuck
	shit
	fuck	
	master=clone_object("/players/dragnar/mons/cultmaster.c");
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
"players/dragnar/rooms/lib6.c","east",
"players/dragnar/rooms/lib9.c","north",
});
}
north() {
	if(present("member", this_object())){
	write("The cult member says: I can't let you interrupt our meeting. You are\n"+
"not permitted passage.\n");
	return 1;
	}
}
