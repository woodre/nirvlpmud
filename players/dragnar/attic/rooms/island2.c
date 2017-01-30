inherit "room/room";
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("Island of darkness");
long_desc=
"As you come up to the building you notice it is some sort of ancient temple.\n" +
"It has words encripted on the sides but they are in a language you \n" +
"can't understand.  At the front of the building are 2 huge doors\n" +
"leading inside.  The doors are open and it seems to be lighted by\n" +
"firelight within.\n",
dest_dir=
({
"players/dragnar/rooms/island.c","south",
"players/dragnar/rooms/temple-enter.c","enter",
});
}
