#include "/players/eurale/defs.h"
inherit "room/room";
int KD;  /* to keep track of Kodragon here or not  */

reset(arg) {
  if(arg) return;
set_light(0);
KD = 1;   /*  Kodragon is in  */

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  You have crawled back into a VERY tight, dark alcove.  The\n"+
	"walls of the opening are very rough and unfinished as the work\n"+
	"here was abandoned early.  Small shelf-like pieces of stone\n"+
	"stick out with their razor edges waiting to cut an unsuspect-\n"+
	"ing adventurer.\n";

items = ({
	"shelf","These are just pieces of stone not completely chipped\n"+
		"away.  They form little shelves.  You might possibly\n"+
		"find something if you searched them",
});

dest_dir = ({
	"players/eurale/Keep/k23.c","out",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("search","search");
  add_action("out","out");
}

out() {
if(TP->query_attrib("luc") < random(40)) {
  write("As you try to back out of the tight tunnel you find yourself\n"+
	"caught on one of the sharp stones.... You CUT yourself..\n");
  TP->heal_self(-(20 + random(15)));
  return 1; }
else {
  TP->move_player("out#players/eurale/Keep/k23.c");
    ("/players/eurale/Keep/k23.c")->set_ONE(0);
    return 1; }
}

search(str) {
if(!str) { write("You search the floor and find nothing..\n"); return 1; }
if((str == "stone" || str == "shelf") && KD == 1) {
  write("You carefully slide your hand over the stone shelf...\n\n"+
        "You feel something furry.......\n\n"+
        "It jumps off the shelf nearly landing on your face.....\n");
  move_object(clone_object("players/eurale/Keep/NPC/kodragon"),TO);
  KD = 0;
  return 1; }
else {
  write("You carefully slide your hand over the stone shelf...\n"+
	"There is a noticeable warm spot where once something had\n"+
	"been laying but it's gone now.....\n");
  return 1; }
}
