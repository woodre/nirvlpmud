inherit "room/room";
init() {
	::init();
}
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("Road to a Temple");
long_desc=
"Death has no meaning here.  Every few feet you pass another face\n"+
"with the same empty look.  The sky seems to be getting darker as you walk down\n"+
"this road of death.  In front of you now is a type of temple\n"+
"that the road seems to lead to.\n",
dest_dir=
({
"players/dragnar/guild/rooms/road.c","west",
"players/dragnar/guild/rooms/road3.c","east",
});
}
