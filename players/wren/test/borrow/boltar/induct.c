drop() { return 1; }
get()  { return 1; }

id(str) { return (str == "induct"); }

short() { return "induct"; }

init()
{
  if(this_player()->query_level() < 21)
    return destruct(this_object());
  else
    add_action("induct", "induct");
}

induct(str)
{
  object ob, thing;
  if(!str || !(ob=find_player(str)))
  {
    write("Bad syntax.\n");
    return 1;
  }
  ob->set_guild_rank(1);
  ob->set_guild_exp(1);
  ob->set_sword(0);
  ob->set_bow(0);
  ob->set_horse(0);
  ob->set_polearm(0);
  ob->set_knife(0);
  ob->set_club(0);
  ob->set_shield(0);
  ob->set_guild_file("players/boltar/templar/templar");
  if(ob->query_attrib("ste") > 10)
    ob->set_attrib("ste", 10);
  if(ob->query_attrib("mag") > 12)
    ob->set_attrib("mag", 12);
  ob->reset(1);
  ob->save_me();
  thing=clone_object("/players/boltar/templar/induct_obj");
  move_object(thing, ob);
  thing->load_func(this_object());
  return 1;
}

receive_func(ob)
{
  move_object(clone_object("/players/boltar/templar/templar"), ob);
  command("fixtitle", ob);
  "/players/maledicta/templar/rooms/nrecruit"->new_shout(
   ob->query_name() + " has just joined the Knights Templar.\n");
  write("Ok.\n");
  return 1;
}


