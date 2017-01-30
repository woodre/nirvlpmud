cmd_hhug(str) {
  if ("bin/ghost"->ghost(1))
    return 1;
  if (!str)
    write("Send a huge hug to whom?\n");
  else {
    object who;
   who=find_living(str);
    if (!who || !living(who))
      write("Hug whom?\n");
    else if (who == this_player())
      write("Now why would you want to do that?!\n");
    else {
      object hugfile;
      hugfile = read_file("/open/colleen/hug");
      tell_object(who, this_player()->query_name() + " hugs you.\n"+ hugfile + "
\n");
      str = capitalize(str);
      write("You send a huge hug to " + str + ".\n");
      say(this_player()->query_name() + " sent a huge hug to " + str + ".\n", wh
o);
    }
  }
  return 1;
}
