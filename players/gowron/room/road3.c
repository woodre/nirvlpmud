inherit "room/room";

reset(arg) {
	if (arg) 
	   return;
	set_light(1);
	short_desc = "Springfield Road Turn";
	long_desc = format("Springfield Road curves south here.  Back to the "+
			   "west you see the Flanders' and Simpsons' houses "+
			   "And to the east you see a looming mansion.  There "+
			   "is a gate and a sign by that gate as well.  To  "+
			   "your north is another house, but you are not sure "+
			   "who lives there.  Finally, to the south is the "+
			   "rest of town, including city hall, moe's tavern "+
			   "and the Kwik-E-Mart.\n", 75);
	items = ({ "gate", "It is a big gate, and it is locked\n",
		   "sign", "The C.M. Burns esate is not open to the public...yet\n", });
	dest_dir = ({ "/players/gowron/room/road2.c", "west",
		     "/players/gowron/room/road4.c", "south",
	             "/players/gowron/room/skinner1.c", "north", });
}
