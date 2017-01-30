/*  Jurassic Park  */

#define tp this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Jurassic Park";
long_desc =
	"  You have managed to work your way into the densest thicket\n"+
	"of jungle underbrush you have ever encountered.  Absolutely\n"+
	"no light penetrates through the canopy above.  The jungle\n"+
	"sounds can be heard all about but you are well protected and\n"+
	"hidden completely from sight.\n";

items = ({
  "underbrush","Large, dark green ferns that require no light",
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

west() {
  write("The underbrush is much too thick to get through that way.\n");
  return 1; }

south() {
  write("The thick jungle makes passage that way impossible.\n");
  return 1; }

east() {
  tp->move_player("underbrush#players/eurale/Park/jp55.c"); return 1; }

north() {
  tp->move_player("underbrush#players/eurale/Park/jp44.c"); return 1; }
