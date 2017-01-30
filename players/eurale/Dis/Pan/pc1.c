#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Westminster Bridge Road";
long_desc =
	"  You walk along the historic Westminster Bridge Road.  It \n"+
	"winds it's way along the Thames River until it reaches the\n"+
	"grand Westminster Bridge.  On the other side of the bridge \n"+
	"is Picadilly Circle that borders one of London's many parks.\n";

items = ({
	"river","A wide, fast-flowing river",
});

dest_dir = ({
	"players/eurale/Dis/Pan/pc2.c","bridge",
	"players/eurale/Dis/rooms/hub.c","southeast",
});

}
