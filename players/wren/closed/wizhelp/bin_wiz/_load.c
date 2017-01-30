int cmd_load(string str)
{
  string err;
  object env;
  if(!str)
  {
    write("Load what?\n");
    return 1;
  }
  if(!(str=(string)this_player()->valid_read(str)))
  {
    write("Invalid file.\n");
    return 1;
  }
  if(err=catch((mixed)str->load_me()))
  {
    write(err);
    return 1;
  }
  env=environment(this_player());
  move_object(this_player(), str);
  move_object(this_player(), env);
  write("Ok.\n");
  return 1;
}

