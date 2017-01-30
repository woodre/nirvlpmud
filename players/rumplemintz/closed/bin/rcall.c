rcall(str) {
  string name, with, what;
  int iwhat;
  object ob;

  if (!str)
    return 0;
  if (sscanf(str, "%s %s %d", name, with, what) == 3)
    iwhat = 1;
  else if (sscanf(str, "%s %s %s", name, with, what) != 3) {
    if (sscanf(str, "%s %s", name, with) == 2)
      iwhat = 0;
    else
      return 0;
  }
  if (name == "here")
    ob = environment(this_player());
  else
    ob = present(name, environment(this_player()));
  if (name == "me")
    ob = this_player();
  if (!ob)
    ob = find_living(name);
  if (!ob) {
    write("No such object here.\n");
    return 1;
  }
  write("Got: ");
  write(call_other(ob, with, what));
  write("\n");
  say(this_player()->query_name()+" patched the internals of "+ob->short()+".\n");
  return 1;
}
