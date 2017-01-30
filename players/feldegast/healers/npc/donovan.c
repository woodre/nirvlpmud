#include "../def.h"

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Master Donovan");
  set_alt_name("donovan");
  set_alias("master");
  set_short("Master Donovan");
  set_long(
    "Master Donovan is a human male standing a little over four feet\n"+
    "in height.  Snowy white hair tops his pale body and his eyes are\n"+
    "an odd shade of pink.  Despite his unimpressive physique, Donovan\n"+
    "has an air of authority and inspiring calm which can just as easily\n"+
    "change to an impish smile.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(21);
  set_wc(30);
  set_ac(20);
  set_hp(3000);
  set_al(1000);
  set_chat_chance(5);
  load_chat("Donovan says: I can "+BOLD+"train"+NORM+" you in the healing arts.\n");
  load_chat("Donovan meditates silently.\n");
  load_chat("Donovan smiles beatifically at you.\n");
  set_chance(15);
  set_spell_dam(400);
  set_spell_mess1("Donovan says: I'm sorry.\n"+
                  "You feel life drain from your body.\n");
  set_spell_mess2("Donovan says: I'm sorry.\n");
}

void init()
{
  ::init();
  if(MYOB)
  {
    add_action("cmd_advance", "train");
    add_action("cmd_leave", "Leave");
  }
  else
    add_action("cmd_join", "join");
  add_action("cmd_fix", "fix");
}

void long(string str)
{
  ::long(str);
  if(MYOB)
    write("Donovan can "+BOLD+"train"+NORM+" you in the healing arts or "+BOLD+"fix"+NORM+" you if your guild\n"+
          "abilities are broken.  If necessary, he can even help you "+BOLD+"Leave"+NORM+" the\nHealer's"+
          BOLD+"guild"+NORM+".\n");
  else
    write("You can "+BOLD+"join"+NORM+" the Healer's guild.\n");
}

int cmd_advance(string str)
{
  int freexp;
  int rank;
  int cost;
  int minlvl, minx;

  if((int)TP->query_extra_level())
    freexp = (int)TP->query_exp() - (int)call_other("/room/exlv_guild","get_next_exp", (int)TP->query_extra_level()-1);

  else
    freexp = (int)TP->query_exp() - (int)call_other("/room/adv_guild","get_next_exp", (int)TP->query_level()-1);

  rank = (int)MYOB->query_rank() + 1;
  switch(rank)
  {
    case 2: 
      cost = 20000;
      minlvl = 8;
      break;
    case 3:
      cost = 100000;
      minlvl = 12;
      break;
    case 4:
      cost = 200000;
      minlvl = 15;
      break;
    case 5:
      cost = 330000;
      minlvl = 18;
      break;
    case 6:
      cost = 350000;
      minlvl = 19; minx = 5;
      break;
    default:
      write("You cannot be trained.\n");
      return 1;
  }

  if((int)TP->query_level() < minlvl)
  {
    write("\nYou must be level "+minlvl+" to advance to the next rank.\n");
    return 1;
  }

  if((int)TP->query_extra_level() < minx)
  {
    write("\nYou must be level "+minlvl+"+"+minx+" to advance to the next rank.\n");
    return 1;
  }

  if(cost > freexp)
  {
    write("\nDonovan says: You are not yet ready to advance to the next level of skill\n"+
          "              in the healing arts.\n");
    return 1;
  }

  TP->add_exp(-cost);
  TP->add_guild_exp(cost);
  MYOB->set_rank(rank);
  TP->add_guild_rank(1);
  write("\nYou spend some time with Donovan learning the healing arts and developing your\n"+
        "inner sense of order.  In time, you feel that you have reached a new plateau in\n"+
        "your skills, and most go back out into the world to gain more experience before\nyou"+
        "can return.\n");
  CHANNEL->broadcast(GUILD_STRING, TPN+" has advanced to rank "+rank+"!\n");
  say(TPN+" advances to rank "+rank+".\n", ({ TP }) );
  hlog("guild_adv", TPN+" has advanced to rank " + rank + ". [ "+(int)TP->query_level()+"+"+(int)TP->query_extra_level()+"]\n");
  return 1;
}

int cmd_join(string str)
{
  object ob;
  if((int)TP->query_guild_string() || (int)TP->query_guild_rank() || (int)TP->query_guild_exp())
  {
    write("You must leave your current guild first.  If you are not already a member of a\n"+
          "guild, then speak to a wizard.\n");
    return 1;
  }

  if(exists(BANPATH + (string)TP->query_real_name() + ".o"))
  {
    write("You have been banned from this guild.  This may be the result of a\n"+
          "punitive measure, or because you have previously been a member of\n"+
          "this guild and then left.  If you wish to join this guild, you will\n"+
          "need to speak to a guild wizard.\n");
    return 1;
  }

  if((int)TP->query_level() < 5)
  {
    write("Donovan says: You must be at least level 5 to join.\n");
    return 1;
  }

  TP->set_guild_string(GUILD_STRING);
  TP->add_guild_rank(1);
  TP->set_guild_file(PATH+"gob.c");
  ob=clone_object(PATH+"gob.c");
  move_object(ob, TP);
  CHANNEL->broadcast(GUILD_STRING, TPN+" has joined the Healers Guild!\n");
  write("\nDonovan teaches you the ways of the healers.  With his help, you develop a sense\n"+
        "of the order and chaos in all things living and dead.  You learn how to remove the\n"+
        "chaos from plants and animals to heal them, and how to instill order to make them\n"+
        "better.  In time, you decide you are ready to put what you have learned into\n"+
        "practice and leave the grove to travel the world again.\n\n"+
        "Type "+BOLD+"know"+NORM+" for more information on your new guild abilities.\n");
  say(TPN+" has joined the Healers Guild.\n");
  hlog("guild_join", TPN+" has joined the guild. [ "+(int)TP->query_level()+"+"+(int)TP->query_extra_level()+"]\n");
  return 1;
}

int cmd_fix(string str)
{
  object ob;

  write("\nDonovan attempts to revives your memories of healing and the\nways of order and chaos.\n");
  say("Donovan converses with " + TPN + ".\n", ({ TP }));

  if(!exists("/" + SAVEPATH + (string)TP->query_real_name() + ".o"))
  {
    write("Donovan says: You are not a healer.  I can do nothing for you.\n");
    return 1;
  }

  if(MYOB)
  {
    MYOB->guild_restore();
  }
  else
  {
    ob = clone_object(PATH + "gob.c");
    move_object(ob, TP);
  }    
  return 1;
}

int cmd_leave(string str)
{
  if(!str || lower_case(str) != "guild")
  {
    notify_fail("If you wish to leave the healer's guild, you must type 'Leave guild'.\n");
    return 0;
  }
  write("Warning: You will lose 1/4 of your XP, and all guild rank and powers by leaving\n"+
        "this guild.  You will be unable to rejoin the guild in the future without talking\n"+
        "to a guild wizard about rejoining.  Are you still sure you wish to leave? (y/N) ");
  input_to("guild_leave");

  return 1;
}


void guild_leave(string str)
{
  string fname;
  int rank;
  int xp;
  int gxp;

  if(!str) return;
  str = lower_case(str);

  if(str != "y" && str != "yes")
  {
    write("Ok.\n");
    return;
  }

  fname = "/" + SAVEPATH + (string)TP->query_real_name() + ".o";

  /* Sanity check */

  if(!MYOB || !exists(fname))
  {
    write("There was a problem altering your statistics.  Please speak to a guild\n"+
          "wizard about this problem.\n");
    return;
  }

  /* Lose 1/4 of your xp for leaving. */

  xp = (int)TP->query_exp() / 4;
  TP->add_exp(-xp);
  call_other("room/adv_guild", "correct_level", this_player());
  call_other("room/exlv_guild", "correct_extra_level", this_object());

  /* Move their guild file to the banished directory. */

  cp(fname, BANPATH + (string)TP->query_real_name() + ".o");
  rm(fname);

  destruct(MYOB);

  /* Reset player's guild stats */

  TP->set_home(0);
  TP->set_guild_string(0);
  TP->set_guild_file(0);
  rank = (int)TP->query_guild_rank();
  TP->add_guild_rank(-rank);
  gxp = (int)TP->query_guild_exp();
  TP->add_guild_exp(-gxp);

  CHANNEL->broadcast(GUILD_STRING, BOLD+BLK+TPN+" has left the Healers Guild!\n"+NORM);

  write("\nDonovan says: It saddens me greatly to see you go, but we must all choose\n"+
        "                our own path.\n"+
        "You have left the Healer's Guild.  You lose "+xp+" experience points.\n");
  hlog("guild_leave", TPN+" has left the guild. [ "+rank+", "+xp+", -"+xp+"]\n");
  return;
}
