inherit "room/room";
	object key, healer, launcher, gold;
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	healer=clone_object("/players/dragnar/heal/vodka.c");
	move_object(healer, this_object());
	launcher=clone_object("/players/dragnar/weapons/launcher.c");
	move_object(launcher, this_object());
/*  removed for quest change 4/5/97  - Eurale
	key=clone_object("/players/dragnar/key.c");
	move_object(key, this_object());
*/
	gold=clone_object("obj/money");
	gold->set_money(random(5000)+3000);
	move_object(gold, this_object());
	if(arg) return;
set_light(5);
short_desc=("Cult storage room");
long_desc=
"This is the cults storage room.  They must have taken over the building\n"+
"as there meeting grounds.  You have a sudden urge to leave so that\n"+
"they don't find you looking around.\n",
dest_dir=
({
"players/dragnar/rooms/lib5","out",
});
}
