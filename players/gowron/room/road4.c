inherit "room/room";

reset(arg) {
	if (arg)
	   return;
	set_light(1);
	short_desc = "Springfield Road South";
	long_desc = format("You are now travelling on South Springfield "+
			   "road.  To your south are more businesses "+
			   "and directly to your east is Moe's tavern. "+
			   "Across the street from Moe's is the city "+
			   "Police station.\n", 75);
	dest_dir = ({ "/players/gowron/room/road3.c", "north",
		      "/players/gowron/room/road5.c", "south",
		      "/players/gowron/room/moes.c", "east",
		      "/players/gowron/room/police.c", "west", });
}
