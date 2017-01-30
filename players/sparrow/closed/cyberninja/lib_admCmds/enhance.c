#include "../DEFS.h"
#include DEFS_GLEVELS


status main(string str)
{
/* Used for guild level promotions/demotions */
  int new_lev, current_lev, low_new_xp, alev;
  string who;
  object ob;

  if (!IPTP->guild_manager()) return 0;

  if (!str || !sscanf(str, "%s %d", who, new_lev) ||
     !find_player(who) || !present(GUILD_ID, find_player(who)))
  {
    write("Usage: enhance <member> <newlevel>.\n");
    return 1;
  }

  ob          = find_player(who);
  current_lev = (int)IPOB->guild_lev();

  if (new_lev == current_lev)
  {
    write(capitalize(who)+" is already of chip quality "+new_lev+"\n");
    return 1;
  }

  if (new_lev < 0)
  {
    write("You cannot drop a member below chip quality 0.\n");
    return 1;
  }

  alev = (int)IPOB->query_art_level();
  alev += new_lev;

  if (new_lev > MAX_QUALITY_LEVEL)
  {
    write("Be sure to read the help files on levels.\n");
    write_file(LOGDIR + "/ENHANCE", TRN+" enhanced "+ORN+
      " from quality "+current_lev+" to "+new_lev+". ("+ctime()+")\n");
    tell_object(ob, "You have been promoted to chip quality "+new_lev+".\n");
    IPOB->set_rank(new_lev);
    ob->add_guild_rank(-((int)ob->query_guild_rank()));
    ob->add_guild_rank(alev);
    low_new_xp = (int)call_other(GLEVELD, "low_exp", new_lev);
    IPOB->set_xp(low_new_xp);
    IPOB->save_me();
    ob->add_guild_exp(-((int)ob->query_guild_exp()));
    ob->add_guild_exp(low_new_xp);
    ob->save_me();
    move_object(IPOB, ob); /* force init */
    return 1;
  }

  if (new_lev > current_lev)
  {
    tell_object(ob, "You have been enhanced to chip quality "+new_lev+".\n");
    write_file(LOGDIR + "/ENHANCE", TRN+" promoted "+ORN+
      " from quality "+current_lev+" to "+new_lev+". ("+ctime()+")\n");
    IPOB->set_rank(new_lev);
    ob->add_guild_rank(-((int)ob->query_guild_rank()));
    ob->add_guild_rank(alev);
    low_new_xp = (int)call_other(GLEVELD, "low_exp", new_lev);
    IPOB->set_xp(low_new_xp);
    IPOB->save_me();
    ob->add_guild_exp(-((int)ob->query_guild_exp()));
    ob->add_guild_exp(low_new_xp);
    ob->save_me();
    move_object(IPOB, ob); /* force init */
    return 1;
  }

  if(new_lev < current_lev)
  {
    tell_object(ob, "You have been demoted to a chip quality of "+new_lev+"\n");
    write_file(LOGDIR + "/ENHANCE", TRN+" demoted "+ORN+
      " from quality "+current_lev+" to "+new_lev+". ("+ctime()+")\n");
    IPOB->set_rank(new_lev);
    ob->add_guild_rank(-((int)ob->query_guild_rank()));
    ob->add_guild_rank(alev);
    low_new_xp = (int)call_other(GLEVELD, "low_exp", new_lev);
    IPOB->set_xp(low_new_xp);
    IPOB->save_me();
    ob->add_guild_exp(-((int)ob->query_guild_exp()));
    ob->add_guild_exp(low_new_xp);
    ob->save_me();
    move_object(IPOB, ob); /* force init */
    return 1;
  }

  return 1;
}

