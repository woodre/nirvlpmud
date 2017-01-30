inherit "room/room";
	object trainer;
init() {
	::init();
	this_player()->set_fight_area();
	add_action("train","train");
}
reset(arg) {
/* This is an illegal monster. Its presence here is intentional. That is bad.
  * - Snow 7/14/98
	trainer=clone_object("/players/dragnar/WasteLands/mons/trainer.c");
	move_object(trainer, this_object());
  */
	if(arg) return;
set_light(1);
short_desc=("Training room for Mortal Kombat");
long_desc=
"This room is very dark, lighted by only a single torch on the wall.\n"+
"In one corner of the room you can see an old man looking at you.\n"+
"Even in the dim light you can see in his eyes that he is very wise.  Perhaps\n"+
"his knowledge could be useful to you.\n",
dest_dir=
({
"players/dragnar/WasteLands/rooms/temple-enter.c","west",
});
}
train(){
	object warrior;
	if(this_player()->query_money() < 1000) {
	write("The old man yells: You don't have enough coins!\n");
	return 1;
	}
	else {
	warrior=clone_object("/players/dragnar/WasteLands/mons/warrior.c");
	move_object(warrior, this_object());
	this_player()->add_money(-1000);
	write("The old man mumbles some words and a warrior appears.\n");
	return 1;
	}
}
