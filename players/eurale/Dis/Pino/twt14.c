#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Ocean shore";
long_desc =
	"  You stop and tread water about 150 yards from shore.  The waves\n"+
	"are making you bob up and down.  Your heart is pounding from the\n"+
	"exertion to get here.  Visibility is very poor.  You get an \n"+
	"occasional glimpse of the shore and......  Was that something\n"+
	"farther out?  Maybe you should swim a little farther or float in.\n";

items = ({
	"shore","A white line of sand ringing the water",
});

dest_dir = ({
	"players/eurale/Dis/Pino/twt13.c","float",
});

}

init() {
  ::init();
  add_action("swim","swim"); }

swim() {
  this_player()->move_player("swim#players/eurale/Dis/Pino/twt15.c");
  return 1; }
