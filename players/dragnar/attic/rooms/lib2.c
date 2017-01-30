inherit "room/room";
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("Wastelands Library");
long_desc=
"Directly in frount of you is the main desk.  To the east and west are\n"+
"rooms full of books, however most of the books are scattered all over the floor.\n"+
"The attendant at the desk is long dead.  It looks as if her skull got crushed.\n",
items=
({
});
dest_dir=
({
"players/dragnar/rooms/lib.c","south",
"players/dragnar/rooms/lib3.c","west",
});
}
