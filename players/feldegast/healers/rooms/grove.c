#include "def.h"

inherit ROOM;

reset(arg) {
  if(!present("donovan"))
    move_object(clone_object(NPCPATH+"donovan"), this_object());
  if(arg) return;
  set_no_teleport(1);
  set_light(1);
  short_desc=GRN+"Healer's Grove"+NORM;
  long_desc=
"  Ironwood trees surround this clearing on every side.  A huge stone\n\
ankh has been constructed in the center of the clearing.  A path leads\n\
back to the garden.  This is a place of perfect peace and tranquility.\n\
Nothing can harm you here.\n";
  items=({
    "trees", "They are tall, beautiful, and full of life",
    "clearing", "reflexive",
    "ankh", "The ankh is the symbol of life and rebirth",
    "path", "It leads south, back to the garden",
  });
  dest_dir=({
    ROOMPATH+"garden1","leave",
  });
}

void init()
{
  ::init();
  add_action("cmd_leave", "leave");
}

int cmd_leave(string str)
{
  if((string)TP->query_guild_name() != GUILD_STRING)
  {
    TP->move_player("leave#/players/feldegast/realm/Caladon/3x6");
    return 1;
  }
}
