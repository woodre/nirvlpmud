int
main(string arg)
{
  object ob;

  if (!this_player())
    return 1; /* Error prevention :) */

  if (!arg)
    ob = this_player();
  else
    ob = find_player(arg);

  if (!ob)
    ob = present("arg", this_player());
  if (!ob)
    ob = present("arg", environment(this_player()));
  if (!ob)
    ob = find_object("arg");
  if (!ob)
  {
    notify_fail("Not found: "+arg+"\n");
    return 0;
  }

  write("Filename of "+arg+": "+file_name(ob)+"\n");
  write("Environment of "+arg+": "+file_name(environment(ob))+"\n");
  ob = first_inventory(ob);
  write("Commencing stealth scan: \n");

  while(ob)
  {
    write("FILENAME: "+file_name(ob)+"\n");
    ob = next_inventory(ob);
  }

  write("Scan of "+arg+" complete.\n");
  return 1;
}
