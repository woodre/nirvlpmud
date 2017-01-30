int cmd_at(string str)
{
  object other_player;
  object old_room;
  string cmd, who;
  
  if(!str) return 0;
  if((int)this_player()->query_level() < 50)
    return 0;
    
  if (sscanf(str, "%s %s", who, cmd) != 2) 
  {
    write("Usage: 'at <player> <cmd>'\n");
    return 1;
  }

  other_player = find_living(who);
  if(!other_player) 
  {
    write("There is no living creature named " + who + ".\n");
    return 1;
  }

  old_room = environment(this_player());
  move_object(this_player(), environment(other_player));
  command(cmd, this_player());
  move_object(this_player(), old_room);
  return 1;
}
