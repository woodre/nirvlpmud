#include "/players/eurale/closed/ansi.h"
#define tpn this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  You have managed to squeeze yourself into a dark, deep crack.\n"+
	"If you reach farther back, you can feel that the crack is get-\n"+
	"ting larger, maybe even enough to get turned around so you\n"+
	"could get out.  The sharp edges of the stones are digging into\n"+
	"your skin but you should be able to continue..  A very strong\n"+
	"odor assaults your nose from deeper in the crack..\n";

items = ({
});

dest_dir = ({
	"players/eurale/Keep/k27.c","out",
});

}

init() {
  ::init();
  add_action("back","back");
  add_action("smell","smell");
  add_action("search","search");
}

back(str) {
  write("You find a small fingerhold and pull yourself deeper into the\n"+
	"dark crack....\n");
  this_player()->move_player("darkness#players/eurale/Keep/k29.c");
  return 1;
}

smell(str) {
if(!str) { write("Smell what?\n"); return 1; }
if(str == "odor") {
  write("You sniff the air...  It is the unmistakable odor of rotten eggs.\n");
  return 1; }
}

search() {
  write("You carefully slide your hand back into the crevass and discover\n"+
	"that you can probably go 'back' farther.\n");
  return 1; }
