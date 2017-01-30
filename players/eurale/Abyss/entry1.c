#define tpn this_player()->query_name()
#define tp this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Dusty Closet";
long_desc =
  "  You step behind the sliding curtain of what looks to be a narrow\n"+
  "closet.  There are clothes hanging on a bar that stretches from one\n"+
  "side of the room to the other.  The wooden floor is bare but the\n"+
  "finish has been worn off indicating that much traffic has visited\n"+
  "this place.\n";

items = ({
  "floor","Wood, darkened with age and much worn",
  "clothes","Old shirts, trousers and coats that have seen better days\n"+
	    "but oddly enough it looks like you could part them",
  "curtain","An old blanket that serves as a door to hide the closet contents",
  "bar","A round wooden rod, securely fastened to the walls on both ends",
});

dest_dir = ({
  "players/eurale/Abyss/entry.c","out",
});

}

init() {
  ::init();
  add_action("part","part");
}

part(str) {
if(!str) { write("Part what?\n"); return 1; }
if(str == "clothes") {
  write("You grab two of the hangers near the center of the bar and\n"+
	"push them just far enough apart to squeeze though...\n");
  tp->move_player("into the clothes#players/eurale/Abyss/entry2.c");
  return 1; }
}
