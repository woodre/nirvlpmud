#define tp this_player()
#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIG+"Enchanted Glade"+NORM;
long_desc =
 "  The tall grass surrounds you.  It makes it impossible to see in\n"+
 "any direction.  There are large rocks that the grass has grown up\n"+
 "around.  As the wind gently blows through the swaying grass, it\n"+
 "makes a soothing swishing sound.\n";

items = ({
  "grass","Tall, wide grass",
  "rocks","Various size boulders, very white and sparkling",
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
  tp->move_player("into the grass#players/eurale/Glade/eg10.c");
  return 1; }
south() {
  tp->move_player("into the grass#players/eurale/Glade/eg12.c");
  return 1; }
east() {
  write("The grass is too thick and tangled to go that way.\n");
  return 1; }
west() {
  tp->move_player("into the grass#players/eurale/Glade/eg8.c");
  return 1; }
