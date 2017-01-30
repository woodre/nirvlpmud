#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Drygulch";
long_desc =
	"  As you continue south you enter a rocky canyon.  The footing \n"+
	"is treacherous and the canyon seems to be getting more and more \n"+
	"narrow.  The roadway takes a sharp turn and disappears behind a \n"+
	"large outcropping of solid rock.\n";

items = ({
	"roadway","The roadway looks conspicuously worn",
	"rock","This large boulder has streaks of pyrite running through it",
});

dest_dir = ({
	"/players/eurale/Drygulch/dgs5.c","north",
	"/players/eurale/Drygulch/dgs7.c","east",
});

}
