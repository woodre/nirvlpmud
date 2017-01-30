#include "DEFS.h"
inherit "room/room";
int wm,one;

reset(arg) {
wm = 1;
one = 0;
  if(arg) return;
set_light(0);

short_desc = "Fiendsville";
long_desc =
	"  This is an eerie place.  The shrubbery has been left unattended\n"+
	"for so long that it's grown out of control.  Thorny bushes grow\n"+
	"in abundance everywhere.  The huge weeping willow trees cast\n"+
	"long, dark shadows... making it impossible to see.\n";
	

items = ({
        "bushes","Dense, tall bushes with two inch thorns on its branches",
	"trees","Old trees with branches that reach the ground",
	"shrubbery","Various bushes and vines, all out of control",
});

dest_dir = ({
	"players/eurale/Fiend/mm29.c","west",
	"players/eurale/Fiend/mm27.c","south",
});

}
init() {
  ::init();
  add_action("west","west");
  TP->set_fight_area();
}

west() {
if(wm == 0 && !present("wolf man")) {
  TP->move_player("west#players/eurale/Fiend/mm29.c");
  return 1; }
if(present("wolf man")) {
  write("Wolf man prevents you from going that way!\n");
  say("Wolf man stops "+capitalize(TPRN)+" from going that way!\n");
  return 1; }
if(!present("wolfman") && one == 1) {
  write("You are frozen in fear, knees knocking.....\n"); return 1; }
if(wm == 1 && !present("wolf man")) {
  write("There is movement in the bushes beside the path...\n\n");
  say("There is movement in the bushes beside the path...\n\n");
  one = 1;
  call_out("talk",6);
  return 1; }
return 1; }

talk() {
  say(
	"The bushes rustle as something runs along beside....\n\n"+
	"You hear a wolf's howl.... very loud and very close..\n\n");
  call_out("talk2",8);
  return 1; }

talk2() {
  say(
	"A large hairy form comes hurdling out of the bushes..\n\n");
  call_out("talk3",7);
  return 1; }

talk3() {
  say("The Wolf Man slowly stands....\n");
  move_object(clone_object("players/eurale/Fiend/NPC/wolfman"),TO);
  wm = 0;
  return 1; }
