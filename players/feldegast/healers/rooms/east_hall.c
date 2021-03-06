#include "def.h"

inherit ROOM;

mapping rooms;

reset(arg) {
  if(arg) return;
  set_no_teleport(1);
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  This is a large corridor that connects the main tower of the healer hall\n"+
"to the east wing where many healers live.  A strong old staircase made out\n"+
"of rounded old stone leads upstairs.  An arched doorway leads outside into\n"+
"the garden, and another archway leads east to the residences.\n";
  dest_dir=({
    ROOMPATH+"garden2","north",
    ROOMPATH+"hall","west",
    ROOMPATH+"blah","east",
    ROOMPATH+"tower", "up",
  });
  rooms = ([ ]);
}

init() {
  ::init();
  add_action("cmd_east","east");
  add_action("cmd_list", "list");
  if(TP->query_level() > 20)
    add_action("cmd_enter", "enter");
}

cmd_east() {
  object room;
  if(!present(GUILD_ID,TP)) {
    write("You can't go that way unless you're invited.\n");
    return 1;
  }
  if(!rooms[TP->query_real_name()])
  {
    room=clone_object(ROOMPATH+"myroom");
    room->set_owner_name(TP->query_real_name());
    rooms[TP->query_real_name()] = room;
    move_object(TP,room);
  }
  else
    move_object(TP, rooms[TP->query_real_name()]);
  command("look",TP);
  return 1;
}

int cmd_list(string str)
{
  string *names;
  int i;
  names = keys(rooms);
  write("The following rooms are loaded:\n");
  for(i = 0; i < sizeof(names); i++)
    write((i+1)+". "+names[i]+"\n");
  return 1;
}

int cmd_enter(string str)
{
  if(!str) {
    notify_fail("Usage: Enter <name>\n");
    return 0; 
  }
  if(!rooms[str])
  {
    write("That person's room is not loaded.\n");
    return 1;
  }
  move_object(TP, rooms[str]);
  command("look", TP);
  return 1;
}
