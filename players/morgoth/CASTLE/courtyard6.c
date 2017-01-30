inherit "room/room";
status door_is_open, door_is_locked;

reset(arg)
{
  if (arg) return;
  door_is_locked = 1;
  set_light(1);
  short_desc = "A large courtyard\n";
  long_desc = "A large courtyard\n"+
              "There is a door to the east.\n";
  dest_dir = 
  ({
      "players/morgoth/CASTLE/courtyard3", "north",
      "players/morgoth/CASTLE/courtyard9", "south",
      "players/morgoth/CASTLE/courtyard5", "west"
  });
}

init()
{
  add_action("look_at_door", "look");
  add_action("exa_door", "exa");
  add_action("open_door", "open");
  add_action("unlock_door", "unlock");
  add_action("move_east", "east");
  ::init();
}

look_at_door(str)
{
  if(str == "at door")
  {
    write("You see a heavy iron bar door\n");
    return 1;
  }
}

exa_door(str)
{
  if(str == "door")
  {
    write("You see a small key hole in the door.\n");
    return 1;
  }
}

open_door(str)
{
  if(str == "door")
  {
    if(!door_is_open)
    {
    if(!door_is_locked)
    {
      write("The door creaks as it swings open..\n");
      say(call_other(this_player(), "query_name") + " opens the door.\n");
      door_is_open = 1;
      return 1;
    }
    if(door_is_locked)
    {
      write("You must unlock the door first !\n");
      return 1;
    }
    }
   if(door_is_open)
   {
     write("The door is already opened !\n");
     return 1;
   }
  }
}



unlock_door(str)
{
  if(str == "door")
  {
  if(!door_is_locked)
  {
    write("The door is not locked.\n");
    return 1;
  }
    if(present("iron key", this_player()))
    {
      write("The door unlocks with a loud click !\n");
      say(call_other(this_player(), "query_name") + "unlocks the door.\n");
      door_is_locked = 0;
      return 1;
    }
  write("You do not possess the right key.\n");
  return 1;
  }
}
move_east()
{
  if(!door_is_open)
  {
    write("You must open the door first !\n");
    return 1;
  }
 if(door_is_open)
  {
    call_other(this_player(), "move_player", "east#players/morgoth/CASTLE/banq_hall");
    return 1;
  }
}
