inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(1);
  short_desc = "Elevallie Road";
  long_desc = "    You are on the main road in Elevallie.  To the East of you, you\n"+
	"see a weaponry.  To the West of you, you can see an armory.  To the North\n"+
	"you see the gates of Elevallie, and to the South is more road.\n";
  dest_dir=({
    "players/rumplemintz/room/elevall/gate", "north",
    "players/rumplemintz/room/elevall/weaponry", "east",
    "players/rumplemintz/room/elevall/armory", "west",
    "players/rumplemintz/room/elevall/room2", "south",
  });
  }
}
