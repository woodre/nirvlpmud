#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Drygulch";
long_desc =
	"  The roadway continues though the desert.  The grade seems to \n"+
	"taking an uphill slant and the going is getting harder.  The sand \n"+
	"and heat are almost unbearable \n";

items = ({
});

dest_dir = ({
	"/players/eurale/Drygulch/dgs2.c","north",
	"/players/eurale/Drygulch/dgs6.c","south",
	"players/eurale/Cave/dgs16.c","east",
});

}
