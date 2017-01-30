#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("traag")) {
  move_object(clone_object("players/eurale/Keep/NPC/traag"),TO); }
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  You stand behind a giant slab of moveable stone.  There are\n"+
	"two curved stairways leading up into the stone.  This area is\n"+
	"much nicer and less crude with tapestry hanging on the walls\n"+
	"and carpet covering the stone steps leading up.\n";

items = ({
	"tapestry","Beautiful hand-crafted cloth with various crests.\n"+
		"The colors are stunning.... probably won in battle.",
	"carpet","Thick black carpet to soften the steps and deaden \n"+
		"the sounds",
});

dest_dir = ({
	"players/eurale/Keep/k62.c","northwest",
	"players/eurale/Keep/k62.c","northeast",
	"players/eurale/Keep/k2.c","out",
});

}

init() {
  ::init();
  add_action("northwest","northwest");
  add_action("northeast","northeast");
}

northwest() {
  if(present("traag")) {
    write("Tragg grips you with a taloned hand and says 'Go Back!'\n");
    say("Tragg stops "+capitalize(TPRN)+" from climbing the stairs..\n");
    return 1; }
  else {
    TP->move_player("northwest#players/eurale/Keep/k62.c");
    return 1; }
}

northeast() {
  if(present("traag")) {
    write("You feel the taloned hand of Tragg on your shoulder and \n"+
	  "he hisses: Go back before it's too late!\n");
    say("Tragg grabs "+capitalize(TPRN)+" by the shoulder and stops him.\n");
    return 1; }
  else {
    TP->move_player("northwest#players/eurale/Keep/k62.c");
    return 1; }
}
