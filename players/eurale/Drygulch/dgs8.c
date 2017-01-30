#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Drygulch";
long_desc =
	"  The wagon path travels east across some open area.  There are \n"+
	"signs of recent travel here with fresh hoof marks, mostly shoed. \n"+
	"The hotel is off to the west and there is another building of \n"+
	"some kind off to the southeast.  Directly to the south is the \n"+
	"raucious town saloon. \n";

items = ({
	"marks","These tracks were made by a horse with horseshoes",
	"building","The building is a little too far away to see clearly",
});

dest_dir = ({
	"players/eurale/Drygulch/dgs12.c","south",
	"/players/eurale/Drygulch/dgs9.c","east",
	"players/eurale/Drygulch/dgs1.c","west",
});

}
