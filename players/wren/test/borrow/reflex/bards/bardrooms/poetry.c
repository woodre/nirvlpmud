#include "/players/reflex/lib/lib.h"
#include "/players/reflex/lib/include/ansi.h"
inherit ROOM;

realm() { return "NT"; }
query_no_fight(){ return 1; }

void create() {

  if(!present("poet writings",this_object())){
  move_object(
    clone_object("/players/reflex/guilds/bards/boards/poemboard.c"),
  this_object()); }

	::create();
  set_short(HIM+"A Poetic Place"+NORM);
  set_long(HIM+
    "The Bardic Poetry Room\n"+NORM+
    "The walls in this room are made of a pale ash wood, and are\n"+
    "completely bare, with the exception of the dozens of poems\n"+
    "scrawled all over the walls.  You can see the writings of\n"+
    "literally hundreds of years worth of Bards, however the most\n"+
    "recent generation has obscured the previous writings.  There\n"+
    "is a doorway leading to the songwriting room to the west.\n"
    );
  set_items(([
    "walls" :
    "The walls are made of a pale ash, and are covered in writing.\n",
    "writings" :
    "Poetry covers the walls in this room, if you <look poems> you can\n"+
    "perhaps read some of them\n",
    "doorway" :
    "This is a mohogany doorway leading to the next room.  Very sturdy.\n",
    ]));
  set_smells(([
    "default" :
    "You smell chalk from the scrawled writings on the walls.\n",
    ]));
  set_sounds(([
    "default" :
    "It is very silent here.\n",
    ]));
  set_exits(([
    "west" : "/players/reflex/guilds/bards/bardrooms/songs",
    ]));
  set_light(1);
  replace_program(ROOM);
}
