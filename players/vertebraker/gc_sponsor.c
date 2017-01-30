#include "/players/guilds/bards/def.h"

status main(string str) {
  string who, sponsor;
  int level, level2;
  object ob, OB;
  
  if (spell(-300, 1, 0) == -1)
    return 0;
  if(!GOB->query_is_gc())
    FAIL("You're not a GC, and shouldn't even be seeing this.\n"+
         "Please see the Guild Wizard.\n");
         
  if (!str || sscanf(str, "%s", who) != 1)
    FAIL("To sponsor a new bard type: sponsor <bard to be>\n");
  
  /* <change by="Erasmios" date="2001-07-05"> */
  ob = find_player(who);

  if (!ob || !present(ob, environment(TP)))
    FAIL("The new Bard must be in the lounge with you.");
  
  sponsor = (string)find_player(who)->query_real_name();
  
  if (ob->query_level() < 5) {
    write
    ("Players must be at least level Five to join the Bardic Guild.\n");
    return 1;
  }
  
  if(ob->query_guild_name()){ write("They are in a guild.\n"); return 1; }
  if(ob->query_guild_rank()){ write("They are in a guild.\n"); return 1; }
  if(ob->query_guild_exp()){ write("They are in a guild.\n"); return 1; }
  if(ob->query_pl_k()){ write("They are PK!\n"); return 1; }

  level = (int)ob->query_level();
  OB = clone_object("/players/guilds/bards/instrument.c");
  move_object(OB, ob);
  OB->set_bard_level("1");
  OB->set_sponsor(tp);
  ob->set_guild_name("bard");
  ob->set_title("the Apprentice");
  write("You have sponsored " + CAP + " into the Bardic Guild!.\n");
  tell_object(ob,
    "You have been sponsored into the Bardic Guild by " +
    tp + "\n" + "You are now a Bard!\n\n" +
    "Type 'lore' for information, and 'sco' to see your new stats.\n\n"
  + "You are given a Bardic Instrument.\n\n");
  command("bt A NEW BARD HAS ENTERED THE REALMS OF MAGIC", ob);
  command("pppp", ob);
  write_file("/players/guilds/bards/logs/sponsor", tp + "(" +
    tp + ") sponsored " + ob->query_name() + "(" +
  ob->query_level() + ")->" + ctime(time()) + "\n");
  return 1;
}
