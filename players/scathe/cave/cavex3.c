#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("Machaville");
    set_long("\
This is the cave of the dreaded Macha.  This large creature is of\n\
immense strength and durablity.  Only the bravest should attempt\n\
this monster!\n");
    set_light(1);
    set_exits(([
	"south":"/players/scathe/cave/caved3",
	]));
}

void reset(int arg) {
    object monster;

    ::reset(arg);
    if (!present("macha", this_object())) {
	monster = clone_object("/players/scathe/monsters/macha");
	move_object(monster, this_object());
    }
}

void init() {
   ::init();
   add_action("dir","pick");
  add_action("south","south");
}
status dir() {
   write("The Macha bites your hand off!\n");
   this_player()->hit_player(15);
   return 1;
}

south() {
if(present("macha")) {
  write("The Macha grins and says, 'You've come this far, let's fight!\n");
  return 1; }
else {
  this_player()->move_player("south#players/scathe/cave/caved3.c");
  return 1; }
}
