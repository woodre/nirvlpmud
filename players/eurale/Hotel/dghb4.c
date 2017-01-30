#include "defs.h"
inherit "room/room";

reset(arg) {

if(!present("wyatt")) {
  move_object(clone_object("players/eurale/Hotel/NPC/beckworth"),TO); }

  if(arg) return;
set_light(0);

short_desc = "Drygulch Hotel basement";
long_desc =
	"  The floor is littered with debris, most of it unrecognizable. \n"+
	"There is a pungent odor that hangs in the air almost taking your \n"+
	"breath away.  A few stones are arranged in a small circle on the \n"+
	"dirt floor.\n";

items = ({
	"debris","From the looks of them, old camp scraps of some kind",
	"stones","A small circle with ashes in the center..  maybe a \n"+
		"fire had been lit here",
});

dest_dir = ({
	"/players/eurale/Hotel/dghb2.c","east",
});

}

init() {
  ::init();
  add_action("sniff","sniff");
  add_action("smell","smell");
}

sniff(str) {
  if(!str) {write("What do you wish to sniff?\n"); return 1;}
  if(str != "odor") {
  write("You might want to 'sniff' something.\n");
  return 1; }
  else {
  write("It has a strong amonia smell to it... burns your nose.\n");
  return 1; } }

smell(str) {
  write("You might want to 'sniff' it.\n");
return 1; }
