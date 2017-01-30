#include "DEFS.h"
inherit "room/room";
string tpn;
int in;

reset(arg) {
in = 1;
  if(arg) return;
set_light(0);

short_desc = "Fiendsville";
long_desc =
	"  You stand under a dilapidated roof that used to cover the\n"+
	"the porch that ran around this building.  To the north is a\n"+
	"set of french doors that is partially open leading to the in-\n"+
	"side of the building.  There is a boarded up window on the side of\n"+
	"the building with a sign over it.  The pillars supporting the\n"+
	"roof have weathered and the paint has peeled off leaving them\n"+
	"at the mercy of the elements.\n";
	

items = ({
	"roof","Still intact but with a couple of holes",
	"doors","Wooden doors with broken windows",
	"window","This used to be the ticket window.  It has been boarded\n"+
		"up but it looks as if one of the boards is loose and you\n"+
		"could shift it",
        "sign","The weathered sign reads:  Opera House Tickets",
	"pillars","Ornate wooden pillars",
});

dest_dir = ({
	"players/eurale/Fiend/mm34.c","enter",
	"players/eurale/Fiend/mm11.c","west",
});

}

init() {
  ::init();
  add_action("shift","shift");
  TP->set_fight_area();
}

shift(str) {
if(!str) { write("What are you trying to shift?\n"); return 1; }
if(str == "board") {
  if(in == 0) { write("You shift the board and find nothing...\n");
	return 1; }
  if(in == 1) {
	in = 0;
	write("You grab the loose board and shift it...\n");
	call_out("grem",2);
	return 1; }
 return 1; }
}

grem() {
  say(
	"The old board creaks as it is shifted aside...\n");
	call_out("grem1",3); return 1; }

grem1() {
  say(
	"Something races past the opening.... \n"+
	"and jumps out on the porch......\n");
    move_object(clone_object("players/eurale/Fiend/NPC/stripe"),TO);
	return 1; }
