#include "/players/guilds/bards/bard_lib/lib.h"
#include <ansi.h>
inherit ROOM;

realm() { return "NT"; }
query_no_fight(){ return 1; }

void create() {

  if(!present("book_board",this_object())){
  move_object(
    clone_object("/players/guilds/bards/boards/storyboard.c"),
  this_object()); }

	::create();
  set_short(HIM+"The Bardic Writing Room"+NORM);
  set_long(HIM+
    "The Bardic Writing Room\n"+NORM+
    "This room is completely bare with the exception of a large oak\n"+
    "table in the center of the room.  The walls are empty of\n"+
    "anything at all, and are simply paneled in dark oak.  The floor\n"+
    "is made of wood slats, and the ceiling arches up from the west\n"+
    "to the east.  There is a sturdy chair before the table, and on\n"+
    "the table is a large book opened to a blank page.  Next to the\n"+
    "book is a stack of scratch paper, several quills, and a ink\n"+
    "well.  There is a doorway to the east leading to the song room.\n"
    );
  set_items(([
    "walls" :
    "The walls are paneled in a sturdy looking oak.\n",
    "table" :
    "This is a large oak table with a book and writing implements on it.\n",
    "floor" :
    "A bare floor that is made of oak slats.\n",
    "slats" :
    "Wooden slats that make up the floor.\n",
    "ceiling" :
    "The ceiling is low in the east and arches upwards to the west.\n",
    "chair" :
    "A sturdy oak chair.\n",
    "paper" :
    "This is a stack of scratch paper for practicing your writing skills.\n",
    "quills" :
    "Feather quills for dipping in the ink well and writing.\n",
    "well" :
    "An ink well for dipping your quill into.\n",
    "doorway" :
    "This doorway leads to the song room.\n",
    ]));
  set_smells(([
    "default" :
    "The smell of fresh ink permeates this room.\n",
    ]));
  set_sounds(([
    "default" :
    "It is very silent here.\n",
    ]));
  set_exits(([
    "east" : "/players/guilds/bards/bardrooms/songs",
    ]));
  set_light(1);
  replace_program(ROOM);
}
