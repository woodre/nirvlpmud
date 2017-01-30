inherit "room/room";
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("Angel Grove Town Square");
long_desc=
"This is the town square of the small town of Angel Grove.\n"+
"Main Street begins and ends here.  There is a small flowerbed located\n"+
"on the edge, and a small fountain in the center.\n"+
"There is a road leading away from the town to the west.\n"+
"A small sign is posted right next to you.\n"+
"",
items=
({
"sign","\n"+
"\n"+
"\n"+
"              WELCOME\n"+
"                     TO\n"+
"                       ANGEL\n"+
"                            GROVE\n",
"flowerbed","A patch of different colored tulips",
"fountain","A fountain of a giant fish, with crystal clear water pouring from its mouth",
});
dest_dir=
({
"players/beck/room/street1.c","east",
"players/beck/room/road2.c","west",
});
}
