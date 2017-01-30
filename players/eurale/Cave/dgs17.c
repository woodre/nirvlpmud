#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {

if(!present("messenger")) {
move_object(clone_object("players/eurale/Cave/mess17.c"),
	this_object()); }

  if(arg) return;
set_light(1);

short_desc = "Drygulch";
long_desc =
	"  You climb slowly and carefully, picking the best hand holds \n"+
	"and foot holds you can find.  At long last, you reach a narrow \n"+
	"ledge not visible from below.  There is a small dark opening \n"+
	"in the rocky face of the canyon wall that you can probably fit \n"+
	"through if you're careful..  The footing is very treacherous \n"+
	"here and the fall would be deadly. \n";

items = ({
	"opening","A cave mouth, well hidden from below",
});

dest_dir = ({
	"/players/eurale/Cave/cav1.c","in",
	"/players/eurale/Cave/dgs16.c","down",
});

}
