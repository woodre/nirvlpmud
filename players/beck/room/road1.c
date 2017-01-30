inherit "room/room";
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("???");
long_desc=
"The road here is extremly dusty and appears to be rarely used.\n"+
"Soon you find yourself in a thick forest with tall hardwood trees all around.\n"+
"You get chills down your spine as you ponder why people wouldn't come to\n"+
"a place as naturally beautiful as here.\n"+
"Off to the east a bit you notice a small rock formation, but it\n"+
"appears inaccesible from here.  To the north you see an intersection\n"+
"as well as more open land.  South, the road narrows down to a path.\n"+
"",
items=
({
});
dest_dir=
({
"players/beck/room/crossroads.c","north",
"players/beck/room/path1.c","south",
});
}
