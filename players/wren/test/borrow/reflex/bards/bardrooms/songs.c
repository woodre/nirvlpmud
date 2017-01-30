#include "/players/reflex/lib/lib.h"
#include "/players/reflex/lib/include/ansi.h"
inherit ROOM;

realm() { return "NT"; }
query_no_fight(){ return 1; }

void create() {

  if(!present("sheet_music",this_object())){
  move_object(
    clone_object("/players/reflex/guilds/bards/boards/songboard.c"),
  this_object()); }

	::create();
  set_short(HIM+"The Sound of Music"+NORM);
  set_long(HIM+
    "The Bardic Song Room\n"+NORM+
    "The song room is a mess.  Sheet music litters the floor and\n"+
    "music stands are all over, some tipped over and some upright.\n"+
    "There are slots lining the walls all around, and each is\n"+
    "labeled with the name of the Bard who owns them.  In some\n"+
    "are stuffed folders filled with sheets of music and songs.\n"+
    "Several instruments are mounted on the east wall, and a piano\n"+
    "is on the west wall.  There is a doorway to the east that\n"+
    "leads to the poetry room.  To the west is an door to the\n"+
    "reading room where stories are written.  The teleport chamber\n"+
    "is to the south.\n"
    );
  set_items(([
    "music" :
    "Sheet music is scattered everywhere in this room.\n",
    "floor" :
    "The floor is littered with the remains of many attempts at songwriting.\n",
    "stands" :
    "These are music stands designed to hold sheet music.\n",
    "folders" :
    "These folders are what Bards put their sheet music into.\n",
    "instruments" :
    "Virtually any instrument you can imagine is here, and in stark contrast\n"+
    "to the rest of the room, they are all very well maintained.\n",
    "piano" :
    "A fine upright piano stands against the west wall.\n",
    "doorway" :
    "This doorway leads east to the poetry room.\n",
    "door" :
    "The west door leadsd to the reading room.\n",
    ]));
  set_smells(([
    "default" :
    "The smell of ink is in the air, and musty paper.\n",
    ]));
  set_sounds(([
    "default" :
    "It is very silent here.\n",
    ]));
  set_exits(([
    "west" : "/players/reflex/guilds/bards/bardrooms/stories",
    "east" : "/players/reflex/guilds/bards/bardrooms/poetry",
    "south" : "/players/reflex/guilds/bards/bardrooms/teleport",
    ]));
  set_light(1);
  replace_program(ROOM);
}
