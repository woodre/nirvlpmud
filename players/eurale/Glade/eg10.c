#define tp this_player()
#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIG+"Enchanted Glade"+NORM;
long_desc =
 "  This is a beautiful spot.  The grass is much shorter here and there\n"+
 "is a huge, flowered bush just to the east.  The tall, swaying grass\n"+
 "is visible both to the west and south.\n";

items = ({
  "grass","Short, field grass....growing wild",
  "flowers","Small, pink, delicate flowers",
  "bush","A thick bush with long pointed thorns on its branches",
});

dest_dir = ({
});

}

init() {
  ::init();
  add_action("search","search");
  add_action("north","north");
  add_action("south","south");
  add_action("east","east");
  add_action("west","west");
}

search() {
  write("You search the area and find nothing special.\n");
  return 1; }

north() {
  write("The thorns and grass prevent movement this direction.\n");
  return 1; }
south() {
if(present("ettin")) {
  write("Ettin laughs and runs to block your way.\n");
  return 1; }
else {
  tp->move_player("into the grass#players/eurale/Glade/eg11.c");
  return 1; }
}
east() {
  write("You start to push through the thorn bush and OUCH.... it's\n"+
	"just too thick and picky to go that way.\n");
  tp->heal_self(-random(20));
  return 1; }
west() {
if(present("ettin")) {
  write("The giant stops you with a meaty arm.\n");
  return 1; }
else {
  tp->move_player("west#players/eurale/Glade/eg9.c");
  return 1; }
}
