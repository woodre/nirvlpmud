inherit "room/room";
object portal, dragon;
init() {
	::init();
	add_action("enter","enter");
	this_player()->set_fight_area();
}
reset(arg) {
	
  portal=clone_object("/players/dragnar/WasteLands/obj/quest/portal.c");
	move_object(portal, this_object());
	dragon=clone_object("/players/dragnar/WasteLands/mons/dragon.c");
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
  "players/dragnar/WasteLands/rooms/cave1-9.c","south",
  });
}
enter(str) {
	object dragon, timer;
	dragon=present("dragon", environment(this_player()));
	if(str=="portal") {
	if(present("shardik",this_object())){
	dragon->attacked_by(this_player());
	write("Shardik awakes from his sleep to stop your passage.\n");
	return 1;
	}
	if(!present("magkey", this_player())) {
	write("For some reason you can't enter the portal.\n");
	return 1;
	}
	destruct(present("magkey", this_player()));
	timer=clone_object("/players/dragnar/WasteLands/obj/quest/timer.c");
	move_object(timer, this_player());
	write("You enter the portal and feel yourself leaping through time.\n");
	say(capitalize(this_player()->query_real_name())+" enters the portal.\n");
	this_player()->move_player("portal#/players/dragnar/WasteLands/rooms/past/cave1-10.c");
	return 1;
	}
}
