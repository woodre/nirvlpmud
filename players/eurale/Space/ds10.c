#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("mortiss 1")) {
  move_object(clone_object("players/eurale/Space/NPC/mortiss1"),TO); }
if(!present("mortiss 2")) {
  move_object(clone_object("players/eurale/Space/NPC/mortiss2"),TO); }
if(!present("mortiss 3")) {
  move_object(clone_object("players/eurale/Space/NPC/mortiss3"),TO); }
set_light(0);

short_desc = "Deep Space";
long_desc =
  "  You manage to scale the short stone wall that is hiding this small\n"+
  "hole in the crater side.  There are signs of some kind of life here\n"+
  "as the floor has some neatly arranged stones covering it.\n";

items = ({
	"stones","The stones form some kind of bedding area",
});

dest_dir = ({
	"players/eurale/Space/ds5.c","out",
});

}
