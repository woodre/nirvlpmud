#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Drygulch";
long_desc =
	"  You have worked your way up a long, rocky dead-end canyon. \n"+
	"The rock sides go straight up and one would have to be able to \n"+
	"climb straight up to get out.  The hand and foot holds look \n"+
	"virtually non-existant at best.  Another hot, thirsty walk back \n"+
	"out. \n";

items = ({
	"holds","These tiny, tiny outcrops just might allow someone to \n"+
		"climb up..... dare you try",
});

dest_dir = ({
	"/players/eurale/Drygulch/dgs5.c","west",
});

}

init() {
  ::init();
  add_action("move","climb"); }

move(str) {
  if(query_verb() == "climb") {
  this_player()->move_player("climb#players/eurale/Cave/dgs17.c");
  return 1; }
return ::move(str); }
