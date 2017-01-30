inherit "room/room";

reset(arg) {
	if (arg)
	   return;
	short_desc = "Simpson Porch";
	long_desc = "You are standing on the porch in front of the house "+
		    "of Homer and Marge Simpson.  It is a two story house with a garage.  It is not a mansion "+
		    "by any definition, and it resembles many of the other houses on this block.  "+
		    "Although it is not glamarous, it is the place the Simpsons "+
		    "call home.  The sound of saxophone is a bit stronger here "+
		    "than it was on the street.  The door is unlocked, you could "+
		    "probably go right in.\n";
	long_desc = format(long_desc, 75);
	dest_dir = ({ "/players/gowron/room/shouse1.c", "enter",
	        "/players/gowron/room/road1.c", "south", });
	set_light(1);
}
