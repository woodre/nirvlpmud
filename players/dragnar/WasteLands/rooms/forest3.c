inherit "room/room";
int x;
object dog;
init() {
	::init();
	add_action("search","search");
	this_player()->set_fight_area();
}
exit() {
  if(this_player())
    this_player()->clear_fight_area();
}
reset(arg) {
  move_object(clone_object("players/dragnar/WasteLands/mons/dog2.c"), this_object());
  move_object(clone_object("players/dragnar/WasteLands/mons/dog2.c"),this_object());
  move_object(clone_object("players/dragnar/WasteLands/mons/dog2.c"),this_object());
	if(arg) return;
set_light(1);
short_desc=("Dark forest");
long_desc=
"A huge gorge running through the forest blocks your way here.\n"+
"It looks as if something made a gash in the land.  Some rubble\n"+
"is laying in the darkness on the edge of the gorge.\n",
items=
({"rubble","Something shiny catches your eye, maybe you should search more carefully",
});
dest_dir=
({
"players/dragnar/WasteLands/rooms/forest.c","west",
});
}
search() {
	object shard, dog;
	if(present("dog")){
	write("The dog won't let you get close to the rubble.\n");
	return 1;
	}
	if(x==1) {
	write("You don't find anything in the rubble.\n");
	say(capitalize(this_player()->query_real_name())+" searches through the rubble.\n");
	return 1;
	}
	if(random(100) > 40) {
	write("You find an old bag.\n");
	say(capitalize(this_player()->query_real_name())+" searches through the rubble and finds an old bag.\n");
	x=1;
	shard=clone_object("/players/dragnar/WasteLands/obj/bag.c");
	move_object(shard, this_player());
	return 1;
	}

	dog=clone_object("/players/dragnar/WasteLands/mons/dog.c");
	move_object(dog, this_object());
	dog=clone_object("/players/dragnar/WasteLands/mons/dog.c");
	move_object(dog, this_object());
	dog=clone_object("/players/dragnar/WasteLands/mons/dog.c");
	move_object(dog, this_object());
	write("Three more dogs trot into the room snarling and growling at you.\n");
  x=1;
	return 1;
}
