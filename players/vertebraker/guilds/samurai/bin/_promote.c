cmd_promote(str)
{
  if(this_player()->query_guild_rank() < 11)
    return 0;
  if(!str)
  {
    write("Promote who?\n");
  }
  else
  {
    object ob;
    
    if(!(ob = find_player(str)))
    {
      write("You don't see \""+str+"\" online.\n");
    }
    else
    {
      if(ob->query_guild_name() != "samurai")
      {
        write("That is not a Samurai!\n");
      }
      else
      {
        if(ob->query_guild_rank() != 0)
        {
          write("They must be rank 0.\n");
        }
        else
        {
          ob->set_guild_rank(1);
          command("id :has promoted "+capitalize(str)+" to Rank 1.", this_player());
        }
      }
    }
  }
  return 1;
}
      