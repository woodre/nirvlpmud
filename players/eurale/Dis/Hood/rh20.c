#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Nottingham";
long_desc =
	"  This is the town square of Nottingham.  There are small shops\n"+
	"lining the wall that surrounds the city.  The castle of King\n"+
	"Richard is just to the west and the front doors have been swung\n"+
	"open to accept visitors.\n";

items = ({
	"wall","A tall wooden wall",
	"shops","Various types of shops including the local seamstress,\n"+
		"bakery and blacksmith",
	"castle","An imposing structure made of stone",
});

dest_dir = ({
	"players/eurale/Dis/Hood/rh21.c","enter",
	"players/eurale/Dis/Hood/rh19.c","northwest",
	"players/eurale/Dis/Hood/rh23.c","northeast",
	"players/eurale/Dis/Hood/rh24.c","east",
	"players/eurale/Dis/Hood/rh25.c","south",
});

}
