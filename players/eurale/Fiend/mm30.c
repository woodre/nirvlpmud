#define tp this_player()
#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";
int db;  /*  draw bridge 0-raised, 1-lowered  */

reset(arg) {
db = 0;
  if(arg) return;
set_light(0);

short_desc = "Fiendsville";
long_desc =
	"  You are in a small clearing at the end of a narrow path that\n"+
	"cuts through the dense thorn bushes.  In front of you is what\n"+
	"appears to be a very deep ravine with steep sides.  A wooden\n"+
	"bridge with a large hand crank is anchored on the side.\n";

items = ({
	"bushes","Thick, tall bushes with very sharp thorns",
	"ravine","A deep valley, obviously cut into the rocks with sides\n"+
		"that go straight down...  making it impossible to climb\n"+
		"down",
	"bridge","A wooden draw bridge",
	"crank","The means to raise and lower the bridge",
});

dest_dir = ({
	"players/eurale/Fiend/mm29.c","path",
	"players/eurale/Fiend/mm38.c","cross",
});

}
init() {
  ::init();
  add_action("cross","cross");
  add_action("raise","raise");
  add_action("lower","lower");
  tp->set_fight_area();
}

cross(str) {
  if(db == 0) { write("The bridge is raised......\n"); return 1; }
  if(db == 1 && (!str)) {
    write("What is it you'd like to cross?\n"); return 1; }
  if(db == 1 &&  str == "bridge") {
    write("You cross the wooden bridge.....\n");
    say(tpn+" leaves across the wooden bridge...\n");
    tp->move_player("bridge#players/eurale/Fiend/mm38.c");
    return 1; }
}

lower(str) {
  if(!str) { write("I'm confused... lower what?\n"); return 1; }
  if(str == "bridge") {
	write("You turn the heavy crank and lower the bridge..\n");
	say(tpn+" turns the heavy crank and lowers the bridge..\n");
	db = 1;
	return 1; }
}
