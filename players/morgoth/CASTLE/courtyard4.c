inherit "room/room";
status door_is_open;

reset(arg)
{
  if (arg) return;
  set_light(1);
  short_desc = "A large courtyard\n";
  long_desc = "A large courtyard\n"+
              "There is a door to the west.\n";
  dest_dir = 
  ({
      "players/morgoth/CASTLE/courtyard1", "north",
      "players/morgoth/CASTLE/courtyard7", "south",
      "players/morgoth/CASTLE/courtyard5", "east"
  });
}

init()
{
  add_action("look_at_door", "look");
  add_action("exa_door", "exa");
  add_action("open_door", "open");
  add_action("close_door", "close");
  add_action("move_west", "west");
  ::init();
}

look_at_door(str)
{
  if(str == "at door")
  {
    write("You see a heavy and thick wood door\n");
    return 1;
  }
}

exa_door(str)
{
  if(str == "door")
  {
    write("You see nothing special about the door\n");
    return 1;
  }
}

open_door(str)
{
  if(str == "door")
  {
    if(!door_is_open)
    {
      write("The door creaks as it swings open..\n");
      say(call_other(this_player(), "query_name") + " opens the door.\n");
      door_is_open = 1;
      return 1;
    }
   if(door_is_open)
   {
     write("The door is already opened !\n");
     return 1;
   }
  }
}

close_door(str)
{
  if(str == "door")
  {
    if(!door_is_open)
    {
      write("The door is already closed !\n");
      return 1;
    }
   if(door_is_open)
   {
     write("The door closes with a groan..\n");
     say(call_other(this_player(), "query_name") + "closes the door.\n");
    door_is_open = 0;
    return 1;
   }
  }
}
move_west()
{
  if(!door_is_open)
  {
    write("You must open the door first !\n");
    return 1;
  }
 if(door_is_open)
  {
    call_other(this_player(), "move_player", "west#players/morgoth/CASTLE/westhall");
    return 1;
  }
}
