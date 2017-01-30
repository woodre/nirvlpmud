int cmd_clone(string str)
{
  string err;
  string pwd;
  object ob;
  if (!str)
  {
    write("Clone what object?\n");
    return 1;
  }
  if(str=="player.c" || str=="/obj/player.c")
  {
    write("That is not allowed.\n");
    this_player()->illegal_patch("cloned player.c");
    return 1;
  }
  str=(string)this_player()->valid_read(str);
  if(!str || (err=catch(ob=clone_object(str))))
  {
    if(err)
      write("Clone failure..\n"+err);
    else
      write("Clone what?\n");
    return 1;
  }
  pwd=(string)this_player()->query_pwd();
  if((pwd && pwd[0..4]=="/open") ||
   str[0..4]=="/open")
    log_file("OPEN",
     ctime()+" "+(string)this_player()->query_real_name()+
     " cloned "+str+"\n");
  this_player()->checked_say((string)this_player()->query_name()+
   " fetches something from another dimension.\n");
  if((status)ob->get())
  {
    this_player()->add_weight((int)ob->query_weight());
    move_object(ob, this_player());
  }
  else
    move_object(ob, environment(this_player()));
  write("Ok.\n");
  return 1;
} 
