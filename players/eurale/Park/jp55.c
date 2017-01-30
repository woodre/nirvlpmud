/*  Jurassic Park  */

#define tp this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Jurassic Park";
long_desc =
	"  You have come upon some sort of clearing in this thick growth\n"+
	"of underbrush.  You can see the stumps of a few trees that have\n"+
	"been cut down, not fallen down.  In the tall grass you can just\n"+
	"make out a partially covered sign.\n";

items = ({
  "underbrush","Large, dark green ferns that require no light",
  "stumps","Trees that have obviously been cut with a saw",
  "sign","Coming soon - Jurassic Park Bed and Breakfast",
  "grass","Free-growning, tall marsh type grasses",
});

dest_dir = ({
});

}

init() {
  ::init();
  add_action("north","north");
  add_action("south","south");
  add_action("east","east");
  add_action("west","west");
}

north() {
  write("The underbrush is much too thick to get through that way.\n");
  return 1; }

south() {
  write("The thick jungle makes passage that way impossible.\n");
  return 1; }

east() {
  tp->move_player("underbrush#players/eurale/Park/jp56.c"); return 1; }

west() {
  tp->move_player("underbrush#players/eurale/Park/jp54.c"); return 1; }
