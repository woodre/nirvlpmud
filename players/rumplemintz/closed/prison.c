short()
{
  return "A darkened room with no way out!";
}

long()
{
  write("You are in a prison cell.\n You have obviously pissed someone off.\n");
  write("There are no exits.\n");
}

reset(arg)
{
  if (arg)
    return;
  set_light(1);
}

init()
{
  add_action("quit"); add_xverb("");
}

quit()
{
  if(call_other(this_player(),"query_real_name", 0) !="rumplemintz")
    {
      long();
      write("You can't do that here.\n");
      return 1;
    }
  return 0;
}
