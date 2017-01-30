#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Ocean shore";
long_desc =
	"  You stand on the shore of a great blue/green ocean.  The waves\n"+
	"with their white caps come crashing into the shore with a rhythmic\n"+
	"regularity and then recede to join the main body again.  This \n"+
	"angry water would make one think twice about taking a swim.\n";

items = ({
	"ocean","A vast sea of blue green water dotted with seagulls",
});

dest_dir = ({
	"players/eurale/Dis/Pino/twt11.c","south",
});

}

init() {
  ::init();
  add_action("swim","swim"); }

swim() {
  this_player()->move_player("swim#players/eurale/Dis/Pino/twt14.c");
  return 1; }
