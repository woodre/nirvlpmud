/*  Drygulch stable  */

#define tp this_plaher()->query name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Drygulch Stable";
long_desc =
	"  As you step inside the building, it takes a moment for your \n"+
	"eyes to adjust to the darkness.  The sweet smell of hay touches \n"+
	"your nose.  You can see stalls lining both sides of the building. \n"+
	"There is a small, hand-printed sign on the wall near the door. \n";

items = ({
	"stalls","The building is too large to see well all the way into \n"+
		"the horse stalls",
	"sign","The sign says:  Horses boarded - 2 bits a day",
});

dest_dir = ({
	"/players/eurale/Drygulch/dgs10.c","north",
	"/players/eurale/Stable/sta2.c","south",
	"/players/eurale/Stable/sta9.c","east",
	"/players/eurale/Stable/sta5.c","west",
});

}
