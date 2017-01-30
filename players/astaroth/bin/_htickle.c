cmd_htickle(str) {
  if ("bin/ghost"->ghost(1))
    return 1;
  if (!str)
    write("Send a ticklee hug to whom?\n");
  else {
    object who;
   who=find_living(str);
    if (!who || !living(who))
      write("Tickle whom?\n");
    else if (who == this_player())
      write("Now why would you want to do that?!\n");
    else {
      object tickfile;
      tickfile = read_file("/players/astaroth/obj/tickle");
      tell_object(who, this_player()->query_name() + " tickles you.\n"+ tickfile +
    "\n");
      str = capitalize(str);
      write("You send a ticklee hug to " + str + ".\n");
      say(this_player()->query_name() + " sent a huge tickle to " + str + ".\n", who);
    }
  }
  return 1;
}
