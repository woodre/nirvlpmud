int cmd_in(string str)
{
  object room;
  object old_room;
  string cmd;
  
  if((int)this_player()->query_level() < 50)
    return 0;
  
  if (!str || sscanf(str, "%s %s", room, cmd) != 2) 
  {
    write("Usage: 'in <file> <cmd>'\n");
    return 1;
  }
  room = (object)this_player()->valid_read(room);
  if(!room) 
  {
    write("Invalid file name.\n");
    return 1;
  }
  old_room = environment(this_player());
  move_object(this_player(), room);
  command(cmd, this_player());
  move_object(this_player(), old_room);
  return 1;
}
