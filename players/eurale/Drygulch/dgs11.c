#define tp this_player()->query_name()
#define TO this_object()
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("wild bill")) {
  move_object(clone_object("players/eurale/Drygulch/NPC/hickock"),TO); }
set_light(1);

short_desc = "Drygulch";
long_desc =
	"  You leave the roadway and step up onto the porch of a small \n"+
	"building with bars on it's windows.  There is a rocking chair \n"+
	"sitting beside the door to the north.  Large lettering over the \n"+
	"door says 'Drygulch Sherrif Office.' \n";

items = ({
	"porch","A cover porch with a hand rail running the whole width \n"+
		"of the building and down the sides",
	"bars","Heavy metal bars, securely anchored in the walls to prevent \n"+
		"both entrance and escape",
	"chair","A comfortable looking wooden rocker",
});

dest_dir = ({
	"/players/eurale/Drygulch/law_off.c","north",
	"/players/eurale/Drygulch/dgs9.c","south",
});

}
