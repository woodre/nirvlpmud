#include "def.h"

inherit ROOM;

mapping room_list;

reset(arg) 
{
  if(arg) return;
  set_light(1);
  set_no_teleport(1);
  short_desc=AREANAME;
  long_desc=
"  This is a large corridor that connects the main tower of the healer hall to\n"+
"the east wing where many healers live.  A strong old staircase made out of\n"+
"rounded old stone leads upstairs.  An arched doorway leads outside into the\n"+
"garden, and another archway leads east to the residences.\n";
  dest_dir=({
    ROOMPATH+"hall","west",
    ROOMPATH+"blah","east"
  });
  room_list = ([ ]);
}

init() 
{
  ::init();
  add_action("cmd_east","east");
}

cmd_east() 
{
  object room;
  string name;
  if(!present(GUILD_ID,TP)) 
  {
    write("You can't go that way unless you're invited.\n");
    return 1;
  }

  name = TP->query_real_name();

  if(!room_list[name])
  {
    room=clone_object(ROOMPATH+"myroom");
    room->set_owner_name(name);
  }
  else
    room = room_list[name];

  move_object(TP,room);
  command("look",TP);
  return 1;
}
