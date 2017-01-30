inherit "room/room";
object portal, dragon;
init() {
	::init();
	add_action("enter","enter");
	this_player()->set_fight_area();
}
reset(arg) {
	portal=clone_object("/players/dragnar/portal.c");
	move_object(portal, this_object());
	dragon=clone_object("/players/dragnar/mons/dragon.c");
	move_object(dragon, this_object());
	if(arg) return;
set_light(1);
short_desc=("Ice caves");
long_desc=
"It is very dark and difficult to see, but a portal in the center of the room\n"+
"has blue light coming from within it.  It looks like blue firelight.  One\n"+
"can only wonder what Shardik would do if you tried to enter it.\n",
items=
({
});
dest_dir=
({
"players/dragnar/rooms/cave1-9.c","south",
});
}
enter(str) {
	object dragon;
	dragon=present("dragon", environment(this_player()));
	if(str=="portal") {
	if(present("dragon",this_object())){
	dragon->attacked_by(this_player());
	write("Shardik awakes from his sleep to stop your passage.\n");
	return 1;
	}
	write("You enter the portal and feel yourself leaping through time.\n");
	say(capitalize(this_player()->query_real_name())+" enters the portal.\n");
	this_player()->move_player("portal#/players/dragnar/past/begin.c");
	return 1;
	}
}
