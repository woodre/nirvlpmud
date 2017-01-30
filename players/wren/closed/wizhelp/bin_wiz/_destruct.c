void destruct_inventory()
{
  object ob, oc;
  ob = first_inventory(this_player());
  while(ob)
  {
    oc=next_inventory(ob);
    if(!ob->id("ND"))
    {
      destruct(ob);
      write("destruct: " + (string)ob->short() + ".\n");
    }
    ob=oc;
  }
}

int cmd_destruct(string str)
{
  object ob;
  if (!str) {
    write("Destruct what?\n");
    return 1;
  }
  str = lower_case(str);
  if (str == "all")
  {
    destruct_inventory();
    return 1;
  }
  if(!(ob=present(str, this_player())) &&
     !(ob=present(str, environment(this_player()))))
  {
    write("You don't see " + str + " here.\n");
    return 1;
  }
  this_player()->checked_say((string)ob->short() +
   " is disintegrated by " + (string)this_player()->query_name() + 
   ".\n");
  destruct(ob);
  write("Ok.\n");
  return 1;
}
