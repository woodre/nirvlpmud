#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "A Star-filled Sky";
long_desc =
	"  You sprinkle the fairy dust and begin to feel lighter.  All\n"+
	"of a sudden you're able to fly.  So up you go...... higher and\n"+
	"higher.  The view from here is breathtaking.  You can see a \n"+
	"pirate ship anchored near an island down below and off in the\n"+
	"distance the twinkling lights of London and the safety of your\n"+
	"bedroom back home.\n";

items = ({
	"ship","A pirate ship for sure as it's flying the Jolly Roger",
	"island","A small, green island",
	"lights","The outline of London near bedtime",
});

dest_dir = ({
	"players/eurale/Dis/Pan/pc15.c","ship",
	"players/eurale/Dis/Pan/pc16.c","island",
	"players/eurale/Dis/Pan/pch8.c","home",
});

}
