inherit "room/room";
realm() { return "NT"; }
object orge;
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
/* changed quest - added Ecave2-6.c  -Eurale  4/5/97
	orge=clone_object("/players/dragnar/WasteLands/mons/orge.c");
	move_object(orge, this_object());
*/
	if(arg) return;
set_light(1);
short_desc=("Ice caves");
long_desc=
"It is pitch black here.  Anything could be hiding in the darkness.\n"+
"It seems as if it could be easy to get lost in here.\n",
items=
({
});
dest_dir=
({
"players/dragnar/WasteLands/rooms/cave2-2.c","north",
"players/dragnar/WasteLands/rooms/cave2-5.c","south",
"players/dragnar/WasteLands/rooms/cave2-2.c","east",
"players/dragnar/WasteLands/rooms/cave2-2.c","west",
"players/dragnar/WasteLands/rooms/cave2-2.c","northeast",
"players/dragnar/WasteLands/rooms/cave2-2.c","northwest",
"players/dragnar/WasteLands/rooms/Ecave2-6.c","southeast",
"players/dragnar/WasteLands/rooms/cave2-2.c","southwest",
});
}
