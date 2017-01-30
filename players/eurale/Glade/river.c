#include "defs.h"
inherit "room/room";
int rs;

reset(arg) {
  if(arg) return;
set_light(1);
rs = 1;

short_desc = "A raging river";
long_desc =
 "  All around you, swirling, bubbling water......and ice cold.\n"+
  "Between the waves, you just get a glimpse of the embankment...\n";

items = ({
  "embankment","Your hope of escape if you can climb it",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("climb","climb");
  add_action("search","search");
}

climb(str) {
int num;
  num = random(30);
if(!str) {
  write("Your flail around in the cold water but the current seems to\n"+
	"be pulling you farther out from the embankment....\n");
  TP->hit_player(25 + random(10));
  return 1; }
if(str != "embankment") {
  write("You reach for the "+str+" to climb out but lose your grip and\n"+
	"slip back into the cold, cold water...\n");
  TP->hit_player(25 + random(15));
  return 1; }
if(str == "embankment" && TP->query_attrib("luc") > num) {
  write("With a super effort, you get a hand hold int he slippery\n"+
	"embankment and pull yourself out of the cold water...\n");
  TP->move_player("embankment#players/eurale/Glade/eg12.c");
  return 1; }
else {
  write("You reach for the slippery embankment but the current pulls\n"+
	"you under and you get a mouthful of water...... COUGH!\n");
  TP->hit_player(30 + random(20));
  return 1; }
}

search() {
if(rs == 1) {
  write("You quickly dive down and feel along the silty river bottom.\n"+
	"You feel the edge of something metal and pull it out...\n");
  move_object(clone_object("players/eurale/Glade/OBJ/shield"),TP);
  rs = 0;
  return 1; }
else {
  write("You hold your nose, dive down into the river and feel through\n"+
	"the silt along the embankment.... but find nothing!\n");
  return 1; }
}
