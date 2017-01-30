#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Deep Space";
long_desc =
  "  You are deep within a "+RED+"red crater"+NORM+".  There is an absence of light\n"+
  "but what light there is makes everything take on a slightly red \n"+
  "color.  The path down is getting narrower and you can just make\n"+
  "out some shadows that might be tunnels in the crater walls.\n";

items = ({
	"path","Obviously, much less used from here on",
	"shadows","There are just too many shadows to tell which are holes\n"+
		"and which are really shadows.  Maybe you could try\n"+
		"to 'peer <direction>'",
});

dest_dir = ({
	"players/eurale/Space/ds4.c","up",
	"players/eurale/Space/ds6.c","down",
});

}

init() {
  ::init();
  add_action("peer","peer");
  add_action("climb","climb");
  add_action("scale","scale");
  add_action("crawl","crawl");
}

peer(str) {
if(!str) { write("You peer into the shadows and see.... blackness.\n");
    return 1; }
if(str == "up") {
  write("You can just make out the path leading upward.\n"); return 1; }
if(str == "down") {
  write("The blackness below makes seeing impossible.\n"); return 1; }

if(str == "east" || str == "e") {
  write("A close look reveals nothing but a shadow..\n"); return 1; }
if(str == "southeast" || str == "se") {
  write("A dark shadow is all that's there..\n"); return 1; }
if(str == "south" || str == "s") {
  write("You peer into the blackness of a shadow..\n"); return 1; }
if(str == "southwest" || str == "sw") {
  write("Nothing there but a shadow...\n"); return 1; }
if(str == "north" || str == "n") {
  write("This dark shadow looked like a hole...but wasn't.\n"); return 1; }

if(str == "northeast" || str == "ne") {
  write("As your eyes adjust to the dark, you see a hidden niche that\n"+
	"you might be able to climb into.\n"); return 1; }
if(str == "west" || str == "w") {
  write("A closer look reveals a hidden opening covered by a rock\n"+
	"wall that you should be able to scale.\n"); return 1; }
if(str == "northwest" || str == "nw") {
  write("You look closely but can't tell so you feel and you discover\n"+
	"a small opening you might be able to get into if you crawl.\n");
  return 1; }
}

climb(str) {
if(!str) { write("What are you trying to climb into?\n"); return 1; }
if(str == "niche" || str == "ne" || str == "northeast") {
  this_player()->move_player("niche#players/eurale/Space/ds12.c");
  return 1; }
}

scale(str) {
if(!str) { write("What would you like to scale?\n"); return 1; }
if(str == "wall") {
  this_player()->move_player("opening#players/eurale/Space/ds10.c");
  return 1; }
}

crawl(str) {
if( (!str) || str == "nw" || str == "northwest") {
  this_player()->move_player("tunnel#players/eurale/Space/ds11.c");
  return 1; }
}
