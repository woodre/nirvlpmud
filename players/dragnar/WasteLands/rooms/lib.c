inherit "room/room";
int x,y;
	object dog;
init() {
	::init();
	this_player()->set_fight_area();
	add_action("open","open");
	add_action("enter","enter");
}
reset(arg) {
	dog=clone_object("/players/dragnar/WasteLands/mons/dog.c");
	move_object(dog, this_object());
	if(arg) return;
	if(!arg) x=1;
y=1;
set_light(1);
short_desc=("Entrance to the Wasteland's Library");
long_desc=
"Before you is the library.  It was built in the 1950's according to the\n"+
"concrete base of the building.  It must have been built well to withstand\n"+
"what caused the destruction of this town.  The huge door leading into\n"+
"the building seems to be closed.\n",
items=
({
"door","It looks heavy but it looks like you could open it"
});
dest_dir=
({
"players/dragnar/WasteLands/rooms/town.c","south",
});
}
open(str) {
	if(str=="door"){
	if(y < 2) {
	x=x+8;
	y=y+6;
	write("You strain and pull open the door.\n"+
"You wonder if you should enter now and see what is inside.\n");
	say(capitalize(this_player()->query_real_name())+" opens the door.\n");
	return 1;
	}
	else if(y > 2) {
	write("The door is already open.\n"+
"You may enter the library.\n");
	return 1;
	}
	}
}
enter() {
	if(x > 2) {
	call_other(this_player(),"move_player","enter#/players/dragnar/WasteLands/rooms/lib2.c");
	return 1;
	}
	else if(x < 2) {
	write("The door isn't open.\n");
	return 1;
	}
}
