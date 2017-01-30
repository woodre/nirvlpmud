inherit "room/room";
realm() { return "NT"; }
int x,y;
	object guard;
init() {
	::init();
	this_player()->set_fight_area();
	add_action("open","open");
	add_action("enter","enter");
}
reset(arg) {
	guard=clone_object("/players/dragnar/WasteLands/mons/guard.c");
	move_object(guard, this_object());
	guard=clone_object("/players/dragnar/WasteLands/mons/guard.c");
	move_object(guard, this_object());
	if(arg) return;
	if(!arg) x=1;
y=1;
set_light(5);
short_desc=("Wastelands Town");
long_desc=
"The entrance into the building is a long hallway.  At the end of the hallway\n"+
"are a set of doors leading to the north end of the hall.  Two guards\n"+
"are standing watch and look to be determined in doing their job.\n",
items=
({
"doors","They look heavy but it looks like you could open them"
});
dest_dir=
({
"players/dragnar/WasteLands/rooms/past/town4.c","south",
});
}
open(str) {
	if(str=="doors"){
	if(present("guard", this_object())){
	object guard;
	guard=(present("guard",this_object()));
	guard->attacked_by(this_player());
	write("The guard gets pissed and tries to kill you.\n");
	return 1;
	}
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
"You may enter the doorway.\n");
	return 1;
	}
	}
}
enter() {
	if(x > 2) {
	call_other(this_player(),"move_player","enter#/players/dragnar/WasteLands/rooms/past/town6.c");
	return 1;
	}
	else if(x < 2) {
	write("The door isn't open.\n");
	return 1;
	}
}
