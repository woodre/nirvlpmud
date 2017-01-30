#define tpn this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Deep Space";
long_desc =
	"  You stand on the surface of a desolate and strange planet.  The\n"+
	"landscape around you is barren but beautiful.  The structures\n"+
	"that rise all about you look a lot like minature mountains that \n"+
	"are made of rock or soil.  There are large craters dotting this\n"+
  "place as far as you can see.  There is an odd metallic capsule\n"+
  "sitting here with an open door.\n";

items = ({
	"surface","Very fine green dust... almost powdery",
	"landscape","Mountainous with craters and many small holes in\n"+
		"in the ground",
	"structures","Small mountains, none higher than 100 feet",
	"craters","Openings of different sizes and depths",
  "capsule","A silver, metallic, pod-like capsule.",
});

dest_dir = ({
	"players/eurale/Space/ds17.c","north",
	"players/eurale/Space/ds2.c","east",
	"players/eurale/Space/teleport_down.c","enter",
});

}
