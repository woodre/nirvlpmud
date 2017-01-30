init()
{
  if(this_player()->query_level() < 21)
    return destruct(this_object());
  else
    add_action("bye", "bye");
}

bye(str)
{
  object ob, ob2;
  if(!str || !(ob=find_player(str)))
  {
    write("Type: 'bye <player>'\n");
    return 1;
  }
  if(ob->query_guild_name() != "Knights Templar")
  {
    write("He's not a knight.\n");
    return 1;
  }
  if(ob2=present("KnightTemplar", ob))
    destruct(ob2);
  ob->set_guild_name(0);
  ob->set_guild_rank(0);
  ob->set_guild_exp(0);
  rm("/players/boltar/templar/member/"+lower_case(str)+".o");
  write("Ok.\n");
  return 1;
}

drop() { return 1; }
get()  { return 1; }

id(str) { return (str == "bye"); }

short() { return "bye"; }
