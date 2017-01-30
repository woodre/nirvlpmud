int cmd_load(string str)
{
  string err;
  object env;
  string tmp;
  if(!str)
  {
    write("Load what?\n");
    return 1;
  }
  str = resolve_path(str);
   /* Need to automatically add .c if not there, -Bp */
  if (sscanf(str,"%s.c",tmp) != 1) str = str + ".c";
  if (file_size(str) <= 0)
  {
    write("Invalid file.\n");
    write("str = "+str+"\n");
    return 1;
  }
  if(!this_player()->query_errormsgs() && (err = catch(str->load_me())))
  {
    write(err);
    return 1;
  }
  else str->load_me();
  env=environment(this_player());
  move_object(this_player(), str);
  move_object(this_player(), env);
  write("Ok.\n");
  return 1;
}

