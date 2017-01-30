inherit "room/room";
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("Crossroads");
long_desc=
"This is where two main roads intersect.  To the east you can barly make\n"+
"out some signs of civilization.  To the north you see some farmland.\n"+
"The roads to the west and south look like they have hardly been used.\n"+
"Looking down them you get a slightly eerie feeling, as they appear to\n"+
"fade from view in the distance.\n"+
"",
items=
({
});
dest_dir=
({
"players/beck/room/road2.c","east",
"players/beck/room/road1.c","south",
"players/beck/room/road3.c","west",
"players/beck/room/farm1.c","north",
});
}
