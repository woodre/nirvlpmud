inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(1);
  short_desc = "Elevallie Road";
  long_desc = "    You are on the main road in Elevallie.  To the East of you, you\n"+
	"see a shop of some sort, and to the West of you, you see a pub.  To the North\n"+
	"you see the road, and to the South, is more road.\n";
  dest_dir=({
    "players/rumplemintz/room/elevall/room1", "north",
    "players/rumplemintz/room/elevall/shop", "east",
    "players/rumplemintz/room/elevall/pub", "west",
    "players/rumplemintz/room/elevall/room3", "south",
  });
  }
}
