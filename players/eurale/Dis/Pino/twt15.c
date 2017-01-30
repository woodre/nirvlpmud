#include "DEFS.h"
inherit "room/room";
int p1;

reset(arg) {
p1 = 1;

if(!present("geppetto")) {
  move_object(clone_object("players/eurale/Dis/Pino/NPC/gepp"),TO); }
if(!present("messenger")) {
  move_object(clone_object("players/eurale/Dis/Pino/mess15"),TO); }

  if(arg) return;
set_light(0);

short_desc = "Monstro's mouth";
long_desc =
	"  As you begin to swim farther out, a whale of a whale pops up\n"+
	"in front of you, opens it's huge jaws, and sucks you in.  The \n"+
	"stench of rotting fish is overwhelming.  There are all kinds\n"+
	"of things floating in the murky water about you and stuck in\n"+
	"the muck between the huge teeth.  You won't last long here\n"+
	"unless you can manage to kick your way out.\n";

items = ({
	"things","Pieces of wood, chunks of half-digested fish, sea weed",
});

dest_dir = ({
});

}

init() {
  ::init();
  add_action("search","search");
  add_action("kick","kick"); }

kick() {
  this_player()->move_player("kick#players/eurale/Dis/Pino/twt14.c");
  return 1; }

search(str) {
object ob;
  ob = present("geppetto");
  if(ob) {
	write("Geppetto says quit searching and help me!\n");
  return 1; }

if(!str) { write("What would you like to search?\n"); return 1; }
if(str == "water") {
  if(!present("geppetto") && (p1 == 1)) {
  write("You search through the flotsam and muck and find a puzzle piece\n");
  move_object(clone_object("players/eurale/Dis/misc/puz1.c"),
	this_player());
  p1 = 0;
  return 1; }

  if(!present("geppetto") && (p1 == 0)) {
  write("You search through the rotting fish and find nothing.\n");
  return 1; }
 return 1; }
return 1;
}
