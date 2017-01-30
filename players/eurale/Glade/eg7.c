#define tp this_player()
#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIG+"Enchanted Glade"+NORM;
long_desc =
  "  You stand it a patch of very tall grass.  As it sways back and\n"+
  "forth in the breeze, it makes a soothing 'swishing' sound.  Above\n"+
  "the grass to the south and west you can make out the tops of tall\n"+
  "trees.\n";

items = ({
  "grass","Wide-bladed grass, almost 6 feet tall",
  "trees","The green tops of tall trees",
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
  tp->move_player("into the grass#players/eurale/Glade/eg8.c");
  return 1; }
south() {
  tp->move_player("into the grass#players/eurale/Glade/eg6.c");
  return 1; }
east() {
  write("The grass is too thick to go that way.\n");
  return 1; }
west() {
  write("The grasses is much to thick and tangled to go that way.\n");
  return 1; }
