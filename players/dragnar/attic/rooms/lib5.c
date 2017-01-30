#define shit cult=clone_object("/players/dragnar/mons/cult2.c");
#define fuck move_object(cult, this_object());
inherit "room/room";
int x,y;
	object cult, master;
init() {
	::init();
	this_player()->set_fight_area();
	add_action("open","open");
	add_action("enter"); add_verb("enter");
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
	if(!arg) x=1;
y=1;
set_light(1);
short_desc=("Wastelands Library");
long_desc=
"The room is very dark, lighted by only candles on the wall.  There is\n"+
"a door on the east side of the room, however it seems to be well protected.\n",
items=
({
"door","It leads to the cults supply room and looks very heavy"
});
dest_dir=
({
"players/dragnar/rooms/lib4.c","west",
});
}
open(str) {
	if(str=="door"){
	if(y < 2) {
	x=x+8;
	y=y+6;
	write("You pull open the door and see a room full of the cults supplies.\n");
	say(capitalize(this_player()->query_real_name())+" opens the door.\n");
	return 1;
	}
	else if(y > 2) {
	write("The door is already open, perhaps you could enter.\n");
	return 1;
	}
	}
}
enter() {
	if(present("member")) {
	write("The Cult Master stops you.\n"+
"He stares at you and you feel a deep fear.\n");
	return 1;
	}
	if(x > 2) {
	call_other(this_player(),"move_player","enter#/players/dragnar/rooms/libstorage.c");
	return 1;
	}
	else if(x < 2) {
	write("The door is closed.\n");
	return 1;
	}
}
