#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Brownstone House";
long_desc =
	"  You have entered one of the beautiful brownstone houses that\n"+
	"circle the park along Picadilly Circle.  These houses are\n"+
	"built up rather than out to conserve space.  There is a large\n"+
	"window looking out of this living area.  An overstuffed chair\n"+
	"and couch provide ample seating for any guests.  There is a\n"+
	"door that is closed, presumably to the upstairs.  There is\n"+
	"a small sign tacked to the wall above the door.\n";

items = ({
	"window","The window looks out on Picadilly Circle and the park",
	"chair","A tapestry covered easy chair",
	"couch","A tapestry covered couch, extra long",
	"sign","The sign reads: The Darlings\n",
	"door","A 6-panel, solid wood door",
});

dest_dir = ({
	"players/eurale/Dis/Pan/pc7.c","out",
});

}

init() {
  ::init();
  add_action("open","open"); }

open(str) {
  if(!str) { write("What are you trying to open?\n"); return 1; }
  if(str == "door") {
    this_player()->move_player("door#players/eurale/Dis/Pan/pch8.c");
    return 1; }
return 1;
}
