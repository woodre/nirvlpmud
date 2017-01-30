#include "../DEFS.h"
#include DEFS_GLEVELS


status membershipStatsUpdated;


status query_membership_updated()
{
  return membershipStatsUpdated;
}


void set_membership_updated(status updated)
{
  membershipStatsUpdated = updated;
}


status already_in_a_guild(object ob)
{
  /* Checks if player is in another guild */
  if((ob->query_guild_name() != 0) ||
  (ob->query_guild_exp()  != 0) ||
  (ob->query_guild_file() != 0) ||
  (ob->query_guild_rank() != 0))
  {
    return 1;
  }
  return 0;
}


status leave_ninjas(object ob)
{
/* So members can leave the guild */
  string file, counselPair;
  int guild_xp, guild_rank, real_exp;
  object corpse;

  if (!IPOB) return 0;

  guild_xp   = (int)IPOB->guild_exp();
  guild_rank = (int)IPOB->guild_lev();
  real_exp   = (int)call_other(ob, "query_exp", 0);

  IPOB->set_xp(-guild_xp);
  IPOB->set_rank(-guild_rank);
  IPOB->set_guild_name(0);

  if (IPOB->query_counselor())
  {
    counselPair = IPOB->query_counselor() + " " + ob->query_real_name();
    call_other(RECRUITD, "clearCouncelee", counselPair);
    IPOB->set_counselor(0);
  }

  IPOB->save_me();

  ob->set_guild_name(0);
  ob->set_title("The Ex-"+FUNKYNAME);
  ob->add_guild_exp(-((int)ob->query_guild_exp()));
  ob->add_guild_rank(-((int)ob->query_guild_rank()));
  ob->set_guild_file(0);
  ob->set_home("room/church");
  ob->stop_defense();

  set_membership_updated(0);

  file = NINJADIR + "/" + TP->query_real_name() + ".o";
  if (file_size(file) >= 0) rm(file);
  ob->hit_player(10000);
  destruct(IPOB);
  move_object(ob, "/room/church.c");
  return 1;
}


status join_ninjas(object ob)
{
/* Way for interested player to join guild */
  object recruitOb;

  if (ob->query_ghost())
  {
    tell_object(ob, "Ghosts cannot join this guild.\n");
    return 0; 
  }

  if ((string)ob->query_real_name() == "guest")
  {
    tell_object(ob, "Guests cannot join this guild.\n"); 
    destruct(ob);
    return 0; 
  }

  if (!present(RECRUIT, ob))
  {
    tell_object(ob, "Only recruits may join the guild directly.\n");
    return 0; 
  }

  recruitOb = present(RECRUIT, ob);

  if (IPOB)
  {
    tell_object(ob, "Already a member.\n");
    return 0; 
  }

  if (already_in_a_guild(ob))
  {
    tell_object(ob, "Guild statistics are non-zero.\n");
    tell_object(ob, "Players may only be a member of one guild.\n");
    return 0; 
  }

  if (ob->query_level() < MIN_JOIN_LEVEL)
  {
    tell_object(ob, 
      "Level to low, must at least be level "+
      MIN_JOIN_LEVEL+" to join.\n");
    return 0; 
  }

  write_file(LOGDIR + "/JOIN", 
    ORN+" joined the guild. ("+ctime()+")\n");

  move_object(clone_object(GUILDOBJ), ob);

  ob->set_guild_name(GUILDNAME);
  ob->add_guild_exp(1);
  ob->set_guild_file(GUILDOBJ);
  ob->save_me();

  IPOB->set_basexp(ob->query_exp());

  call_other(RECRUITD, "setCounselee", 
             recruitOb->query_recruiter() + " " + ob->query_real_name());
  IPOB->set_counselor(recruitOb->query_recruiter());

  IPOB->save_me();

  set_membership_updated(0);

  destruct(recruitOb);

  tell_object(ob, "Welcome to the "+FUNKYNAME+" guild.\n");

  tell_object(ob,"Implants are surgically placed inside your body.\n");
  tell_object(ob,"Your electronics are connected to the CyberNet.\n"+
                 "A generic neural microprocessor is placed in your head.\n");
  tell_object(ob,".....You are now a "+FUNKYNAME+"!\n");
  tell_object(ob,"Type 'cyber' to see the general guild help list.\n");
  say(OPN+" has joined the Ninjas!\n");
  call_other(CHANNELD, "overchannel", OPN+" has joined the Ninjas!\n");
  return 1;
}


void restoration(object ob)
{
  if (IPOB) destruct(IPOB);
  TP->stop_defense();
  move_object(clone_object(GUILDOBJ), ob);
}


void fix(object ob)
{
  int xp, qlev, alev;
  xp   = (int)IPOB->guild_exp();
  qlev = (int)IPOB->guild_lev();
  alev = (int)IPOB->query_art_level();
  ob->set_guild_name(GUILDNAME);
  ob->add_guild_rank(-((int)ob->query_guild_rank()));
  ob->add_guild_rank(qlev + alev);
  ob->add_guild_exp(-((int)ob->query_guild_exp()));
  ob->add_guild_exp(xp);
  if (!ob->query_guild_exp()) ob->add_guild_exp(1);
  ob->set_guild_file(GUILDOBJ);
  ob->save_me();
}

