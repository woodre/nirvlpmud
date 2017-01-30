#define shit cult=clone_object("/players/dragnar/WasteLands/mons/cult.c");
#define fuck move_object(cult, this_object());
#define change cult=clone_object("/players/dragnar/WasteLands/mons/member.c");
#define pain move_object(cult, this_object());
inherit "room/room";
	object cult, master;
init() {
	::init();
	this_player()->set_fight_area();
	add_action("north","north");
	add_action("east","east");
}
reset(arg) {
/* shit fuck shit fuck change pain  removed -Snow */
	change
	pain
	change
	pain
	shit
	fuck
	master=clone_object("/players/dragnar/WasteLands/mons/cultmaster.c");
	move_object(master, this_object());
	if(arg) return;
set_light(1);
short_desc=("Wasteland's library");
long_desc=
"This room used to be some sort of meeting room.  It has a large table\n"+
"in the center with chairs around the outside.  As you glance up at\n"+
"the high gothic ceiling, you realize how strange it is that this room\n"+
"was so untouched from damage.\n",
dest_dir=
({
"players/dragnar/WasteLands/rooms/lib5.c","east",
"players/dragnar/WasteLands/rooms/lib6.c","north",
"players/dragnar/WasteLands/rooms/lib3.c","south",
});
}
east() {
	if(present("member")) {
	write("Cult member says: I can't let you interrupt our meeting.  You are not\n"+
"permitted passage.\n");
	return 1;
	}
}
north() {
	if(present("member")) {
	write("Cult member says: I can't let you interupt our meeting.  You are not\n"+
"permitted passage.\n");
	return 1;
	}
}
