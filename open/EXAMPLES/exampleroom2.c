inherit "room/room";

int i;

reset(arg) {
	if(!present("brutus")) {
	  for(i=0;i<2;i++) {
	  move_object(clone_object("open/EXAMPLES/brutus"), this_object());
	}
    }
	if(!arg) {
	set_light(1);
	short_desc = "An Example room";
	long_desc = "\n"+
	"     This is a nice example room, coded by Rumplemintz so that all\n"+
	"the newer wizards would have something to look at.\n";
	dest_dir = ( {
		"open/EXAMPLES/exampleroom", "north",
		"open/EXAMPLES/exampleroom2", "south",
		"room/shop", "shop",
		});
	}
}
