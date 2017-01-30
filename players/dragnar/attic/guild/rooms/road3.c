inherit "room/room";
init() {
	::init();
}
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("Road to the Temple");
long_desc=
"The spears only stop when they reach the walls of the temple.  It seems\n"+
"very dark now, even for a Wasteland's day.  As you look over the\n"+
"temple you see a doorway leading into the darkness.  A cold chill runs\n"+
"up your spine as you think about entering in there however...\n",
dest_dir=
({
"players/dragnar/guild//rooms/temple.c","enter",
"players/dragnar/guild//rooms/road2.c","west",
});
}
