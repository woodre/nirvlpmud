inherit "room/room";

reset(int arg) {
	if (arg)
	   return;
	set_light(1);
	short_desc = "Springfield Entrance";
	long_desc = "Welcome to Springfield.  This is the first of many gateways "
		+"in Gowron's realm.  Expect to see more in the future.  There"+
		 " is a tree next to you, and a road leading east towards the town.\n";
	long_desc = format(long_desc, 75);
	items = ({ "tree", "Springfield's famous lemon tree.", });
	dest_dir = ({ "/players/gowron/room/road1.c", "east",
		      "/room/forest1.c", "exit" });
}
