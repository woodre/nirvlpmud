
#include "/room/clean.c"
reset(arg) {
   if(!arg)
     set_light(1);
}

short() { return "The Road to the Valley  [n,s]"; }

long() { write(
  "This is the town square of Rowan.  Some of the ground here\n"+
  "is quite uneven and many of the cobblestones have been\n"+
  "replaced.  The local pub lies to the south and off to the\n"+
  "southwest is the library.\n"+
  "     There are three obvious exits: south, east, west\n");
}

init() {
  add_action("south","south");
  add_action("east","east");
  add_action("west","west");
}

east() {
  this_player()->move_player("east#players/molasar/rowan/e_twn_sq.c");
  return 1; }

west() {
  this_player()->move_player("west#players/molasar/rowan/road3.c");
  return 1; }

south() {
  this_player()->move_player("south#players/molasar/rowan/inn.c");
  return 1; }
