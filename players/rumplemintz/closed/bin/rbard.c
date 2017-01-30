status rbard(string str) {
  object ob, OB;
  if (!str) return 0;
  ob = find_player(str);
  if (!ob) return 0;
  if (ob->query_guild_name()) return 0;
  if (ob->query_guild_rank()) return 0;
  if (ob->query_guild_exp()) return 0;
  if (ob->query_pl_k()) return 0;
  OB = clone_object("/players/guilds/bards/instrument");
  move_object(OB, ob);
  OB->set_bard_level("1");
  OB->set_sponsor("Rumplemintz");
  ob->set_guild_name("bard");
  ob->set_title("the Apprentice");
  write("Bardified " + ob->query_name() +"\n");
  tell_object(ob,
    "You have been sponsored into the Bardic Guild by Rumplemintz.\n"+
    "You are now a Bard!\n\n"+
    "Type 'lore' for information, and 'sco' to see your new stats.\n\n"+
    "You are given a Bardic Instrument.\n\n");
  command("bt A NEW BARD HAS ENTERED THE REALMS OF MAGIC", ob);
  command("pppp", ob);
  write_file("/players/guilds/bards/logs/sponsor", "Rumplemintz sponsored "+
             ob->query_name()+ "(" + ob->query_level()+")->" + ctime()+"\n");
  return 1;
}
