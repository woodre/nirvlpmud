#include "DEFS.h"
inherit "room/room";
int w;

reset(arg) {
if(!present("messenger")) {
  move_object(clone_object("players/eurale/Fiend/NPC/mess26"),TO); }
  if(arg) return;
set_light(0);

short_desc = "Fiendsville";
long_desc =
	"  You stand at the foot of ten stone steps.  The enclosure is\n"+
	"very well hidden by the the willow trees and bushes that have\n"+
	"grown up around it.  There is a heavy wooden door with some kind\n"+
	"of crest attached.  Although the area is unkempt, the door and\n"+
	"it's hardware seems well taken care of.\n";
	

items = ({
	"bushes","Dense, tall bushes with 2 inch thorns on it's branches",
	"trees","Old trees with branches that reach the ground",
	"crest","This is family crest of royalty with a shield and what\n"+
		"would appear to be bats encircling it",
	"door","A very thick door you could pull open if you tried",
});

dest_dir = ({
	"players/eurale/Fiend/mm17.c","climb",
});

}
init() {
  ::init();
  add_action("pull","pull");
  add_action("open","open");
  TP->set_fight_area();
}

open(str) {
  if(!str) { write("What would you try to open?\n"); return 1; }
  if(str == "door") {
	write("You try to open the door but it won't budge.  It looks\n");
	write("like it will take a much harder pull than that!\n");
	say(capitalize(TPRN)+" tries to open the door with no luck!\n");
  return 1; }
return 1; }

pull(str) {
if(!str) { write("You have to pull something!\n"); return 1; }
if(str == "door") {
w = (random(13));
if(w > 6) {
  write("With a mighty heave, you pull the door open and enter the crypt.\n");
  say("With a mighty heave, "+capitalize(TPRN)+" pulls the door open and enters..\n"+
      "and the heavy door quicky SLAMS SHUT! \n");
  TP->move_player("door#players/eurale/Fiend/mm36.c");
  return 1; }

else {
  write("You give a mighty heave but the door remains shut..\n");
  say(capitalize(TPRN)+" gives a mighty heave on the door but has no luck..\n");
  return 1; }

 return 1; }
return 1; }
