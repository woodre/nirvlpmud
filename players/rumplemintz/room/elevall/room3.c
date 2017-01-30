inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(1);
  short_desc = "Elevallie Road";
  long_desc = "    You are on the main road in Elevallie.  To the East of you, you\n"+
	"see a Magic Shop, and to the West, a Toy Shop.  To the North, you see road\n"+
	"and off in the distant South, you can see a Castle.\n";
  dest_dir=({
    "players/rumplemintz/room/elevall/room2", "north",
    "players/rumplemintz/room/elevall/magicshop", "east",
    "players/rumplemintz/room/elevall/toyshop", "west",
  });
  }
}
