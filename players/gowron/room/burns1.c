inherit "room/room";

	status nohound;
reset(arg) {
	int i;
	object ob,hnd;
	ob = present("dog", this_object());
	if (!ob) {
	   for (i=0;i<random(10);i++) {
		hnd = clone_object("players/gowron/room/obj/hound.c");
		move_object(hnd,this_object());
           }
        }
        set_light(1);
	short_desc = "Burns Courtyard";
	long_desc = "You are in the courtyard of the C.M. Burns Estate.  "+
		    "You are being ravaged by vicious dogs all around you.  You know you "+
		    "have to eliminate them before you can go any further into "+
		    "the mansion.  To your west you see the rest of town, while  "+
		    "to your north east you see the looming mansion\n";
	dest_dir = ({ "/players/gowron/room/burns_house.c", "east",
		      "/players/gowron/room/road3.c", "west", });
	long_desc = format(long_desc, 75);
}
