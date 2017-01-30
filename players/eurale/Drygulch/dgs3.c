#define tpn this_player()->query_name()
#define tp this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Drygulch";
long_desc =
	"  The road continues for as far as the eye can make it out.  The\n"+
	"desert, although harsh, has a certain beauty to it.  The cacti \n"+
	"and the tumbleweeds provide variation to this never-ending \n"+
   "landscape of sand.  Just off the road stands a dilapidated old\n"+
   "lineman's shack in serious disrepair.. a sign of better days.\n";

items = ({
	"cacti","The only green item in a sea of brown.  It will sustain\n"+
		"life with precious liquid if need be",
	"tumbleweeds","These wind-blown tumblers zig-zag their way across\n"+
		"the baren landscape... only stopping for calm",
  "shack","An old wooden lineman's shack that is beginning to lean\n"+
          "from the prairie winds.  Maybe you could still enter it",
});

dest_dir = ({
	"/players/eurale/Drygulch/dgs2.c","east",
	"/players/eurale/Drygulch/dgs4.c","west",
});

}

init() {
  ::init();
  add_action("enter","enter");
}

enter(str) {
if(!str) { write("Enter what?\n"); return 1; }
if(str == "shack") {
  write("You open the creaky old door and enter the shack..\n");
  say(tpn+" wanders off the road toward the shack..\n");
  tp->move_player("shack#players/eurale/Abyss/entry.c");
  return 1; }
}
