#include "DEFS.h"
inherit "room/room";
object spade;
int sp;  /* spade.... 1 = here, 0 = gone  */
int digs,here;  /* digs = # of attemps, here = 1 in, 0 gone  */

reset(arg) {
sp = 1;
here = 1;
digs = 0;
  if(arg) return;
set_light(0);

short_desc = "Fiendsville";
long_desc =
	"  This is an eerie place.  The shrubbery has been left unattended\n"+
	"for so long that it's grown out of control.  Thorny bushes grow\n"+
	"in abundance everywhere.  The huge weeping willow trees cast\n"+
	"long, dark shadows... making it impossible to see.  Some of the\n"+
	"trees have even died, leaving skeletal looking remains lurking\n"+
	"in the bushes.  One such twig, devoid of branches, is sticking\n"+
	"up out of the ground just beside the path.\n";
	

items = ({
	"bushes","Dense, tall bushes with 2 inch thorns on it's branches",
	"trees","Old trees with branches that reach the ground",
	"shrubbery","Various bushes and vines, all out of control",
	"twig","A closer look reveals this 'twig' to be smooth and straight,\n"+
		"much like the handle of a shovel.  Can you 'unearth' it",
});

dest_dir = ({
	"players/eurale/Fiend/mm22.c","east",
});

}
init() {
  ::init();
  add_action("unearth","unearth");
  add_action("dig","dig");
  TP->set_fight_area();
}

unearth(str) {
  if(!str) { write("What would you like to unearth?\n"); return 1; }
  if(sp == 1 && str == "twig") {
	write("That really isn't a twig...try shovel!\n"); return 1; }
  if(str == "shovel") {
	if(sp == 0) { write("No shovel here, just a twig..\n"); return 1; }
	if(sp == 1) {
	write("You take a small shovel from the ground...\n");
	sp = 0;
    spade = clone_object("players/eurale/Fiend/OBJ/shovel.c");
	move_object(spade,this_player());
	return 1; }
  return 1; }
return 1; }

dig() {
if(present("shovel",this_player())) {
  if(digs == 0) {
	write("You dig in the hard clay and find nothing...\n");
	write("Maybe just one more try?\n");
	say(capitalize(TPRN)+" digs in the hard clay.....\n");
	digs = 1;
	return 1; }
  if(digs == 1 && here == 1) {
	write("You dig deeper into the hard clay.....\n");
	write("Something moves.......\n");
	say(capitalize(TPRN)+" digs in the hard clay....\n");
  move_object(clone_object("players/eurale/Fiend/OBJ/hole"),TO);
  move_object(clone_object("players/eurale/Fiend/NPC/clay"),TO);
	here = 0;
	return 1; }

return 1; }  /* if they have a shovel  */
return 1; }
