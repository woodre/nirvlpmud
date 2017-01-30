#define tp this_player()
#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";
int PATRONE,PATRONS;

reset(arg) {
  if(arg) return;
set_light(0);
PATRONE = 0;
PATRONS = 0;

short_desc = HIG+"Enchanted Glade Cave"+NORM;
long_desc =
  "  You stand in a cool, moist cavern.  There is a sign attached to\n"+
  "the dirt wall.  The opening out is bright and looks like a small\n"+
  "lighted circle in a wall of darkness.  The cavern has openings that\n"+
  "lead off both east and south.\n";

items = ({
  "sign","An arrow pointing east says 'Men' and one pointing south\n"+
	"says 'Women'",
  "opening","The cave mouth leading out",
});

dest_dir = ({
	"players/eurale/Glade/eg22.c","out",
  "players/eurale/Glade/eg25.c","south",
  "players/eurale/Glade/eg24.c","east",
});

}

realm() { return "NT"; }

set_PATRONE(i) { PATRONE = i; }
query_PATRONE() { return PATRONE; }
set_PATRONS(i) { PATRONS = i; }
query_PATRONS() { return PATRONS; }

init() {
  ::init();
  add_action("search","search");
  add_action("east","east");
  add_action("south","south");
}

search() {
  write("You search the area and find nothing special.\n");
  return 1; }

east() {
if(PATRONE == 0) {
  tp->move_player("east#players/eurale/Glade/eg24.c");
  PATRONE = 1;
  return 1; }
else {
  write("Sorry, that room is already in use.\n");
  return 1; }
}

south() {
if(PATRONS == 0) {
  tp->move_player("south#players/eurale/Glade/eg25.c");
  PATRONS = 1;
  return 1; }
else {
  write("Sorry, that room is already in use.\n");
  return 1; }
}
