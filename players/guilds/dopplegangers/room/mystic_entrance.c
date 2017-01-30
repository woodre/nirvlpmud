/*
 * Mystic guild faction (Dopplegangers) entrance
 * Rumplemintz
 */

#pragma strong_types

#include <ansi.h>
#include "/sys/wizlevels.h"
#include "../def.h"

inherit "room/room";

void reset(int arg) {
  if (arg)
    return;
  set_light(1);
  short_desc = "The Doppleganger Mystics' Faction";
  long_desc = "You have entered the Doppleganger Mystics' Faction.\n" +
              "Type 'list' for a list of commands.\n";
  dest_dir = ({
    "/players/grimm/rooms/haphaz_c3", "east",
    GUILD_DIR + "room/mystic_guildhall", "west",
  });
}

void init() {
  ::init();
  add_action("west", "west");  /* Mystic Faction member check */
  add_action("list", "list");
  add_action("unjoin", "unjoin");
  add_action("join", "join");
  add_action("swap", "swap");
  add_action("cost", "cost");
  add_action("advance", "advance");
}

int west() {
  string proom;
  object badge;

  badge = present("V-GUILD", this_player());
  proom = "/players/guilds/dopplegangers/room/mystic_guildhall";

  if ((int)this_player()->query_level() < WL_WIZARD) {
    if (!badge ||
        !badge->query_faction("mystic") ||
        (string)this_player()->query_guild_name() != "doppleganger") {
      write("You are not a member of the Mystics' Faction.\n" +
            "You cannot enter that room.\n");
      if (find_object(proom))
        tell_room(find_object(proom),
                  this_player()->query_name() + " tried to enter the room " +
                  "but got kicked out!\n");
      return 1;
    }
  }
  return 0;
}

int list() {
  write("          Commands you can do:\n"+
        "          -----------------------------------------------------\n"+
        "          Advance .. Advance your level in the faction\n"+
        "          Cost ..... Check the costs in coins of advancing\n"+
        "          Join ..... Join the faction\n"+
        "          List ..... This menu\n"+
        "          Swap ..... Swap <x> experience for <x> faction experience\n"+
        "          Unjoin ... Unjoin the faction (loosing all faction rank!)\n"+
        "          -----------------------------------------------------\n\n");
  return 1;
}

int join() {
  object badge;

  badge = present("V-GUILD", this_player());
  
  if (this_player()->query_npc()) return 0;

  if (!badge || (string)this_player()->query_guild_name() != "doppleganger") {
    write("You are not a member of the Dopplegangers!\n");
    return 1;
  }
  if (badge->query_faction("barbarian") || badge->query_faction("mystic")) {
    write("You are already a member of a Doppleganger faction.\n");
    return 1;
  }
  if ((int)this_player()->query_guild_rank() < 9) {
    write("You must be guild level 9 in the Dopplegangers Guild to join.\n");
    return 1;
  }
  if ((int)this_player()->query_guild_exp() < 200000) {
    write("You must first prove yourself worthy.\n" +
          "You must ask the Sage of Reeseport for help by typing:\n" +
          "\"judge my soul\"\nIn the Sage's house.\n");
    return 1;
  }
  write("You have just joined the Mystics Faction!!!\n");
  this_player()->set_guild_rank(10);
  badge->set_faction("mystic");
  badge->reset();
  badge->save_me(1);
  command("renew", this_player());
  write_file(GUILD_LOG + "join",
             capitalize((string)this_player()->query_real_name()) +
             " joined the Mystic Faction - Time: " + ctime() + "\n" +
             "-------------------------------------------------\n");
  CHAND->channel_message("dopplegangersM",
                        this_player()->query_name() +
                        " just joined the Mystics Faction!!!",
                        HIB + "[Grimm's Assistant]: " + NORM);
  say(this_player()->query_name() +
      " just joined the Doppleganger Mystic Faction!!!\n");
  return 1;
}

void unjoin() {
  object badge;

  badge = present("V-GUILD", this_player());
  if (!badge->query_faction("mystic")) {
    write("You are not a member of the Mystic Faction!\n");
    return;
  }
  write("WARNING: This will remove all Mystic Faction status.\n" +
        "         You will lose all of your swapped guild experience\n" +
        "         above guild level 9.\n" +
        "Are you sure you want to do this? (Y or N)\n");
  write("->> ");
  input_to("unjoin_decision");
}

int unjoin_decision(string str) {
  object badge;

  if (!str || str == "N" || str == "no" || str == "No") {
    write("Aborting...\n");
    return 1;
  }

  badge = present("V-GUILD", this_player());

  CHAND->channel_message("dopplegangersM",
                         this_player()->query_name() +
                         " just left the Mystic Faction!!!",
                         HIB + "[Grimm's Assistant]: " + NORM);
  write_file(GUILD_LOG + "unjoin",
             capitalize((string)this_player()->query_real_name()) +
             " unjoined the Mystic Faction - Time: " + ctime() + "\n" +
             "Guild Exp: " + this_player()->query_guild_exp() + "\n" +
             "Guild Rank: " + this_player()->query_guild_rank() + "\n" +
             "----------------------------------------------------\n");
  badge->remove_faction("mystic");
  badge->set_guild_exp(180000);
  this_player()->set_guild_rank(9);
  badge->reset();
  badge->save_me(1);
  command("renew", this_player());
  say(this_player()->query_name() + " has left the Mystic Faction.\n");
  return 1;
}

int cost() {
  object badge;

  badge = present("V-GUILD", this_player());
  if (!badge || !badge->query_faction("mystic")) {
    write("You are not a member of the Mystic Faction yet...type \"join\".\n");
    return 1;
  }
  write(
"                        Costs to advance in the faction (in exp)\n"+
"                        ----------------------------------------\n"+
"                        Level 10 ......................... Given\n"+
"                        Level 11 ........................ 250000\n"+
"                        Level 12 ........................ 300000\n"+
"                        Level 13 ........................ 350000\n"+
"                        Level 14 ........................ 400000\n"+
"                        Level 15 ........................ 450000\n"+
"                        ----------------------------------------\n"+
"                        You currently have:            " +
                         this_player()->query_guild_exp() + "\n\n");
  return 1;
}

int swap(string str) {
  int amount, minexp;
  object badge;

  badge = present("V-GUILD", this_player());
  if (!badge || !badge->query_faction("mystic")) {
    write("You are not a member of the Mystic Faction yet...type \"join\".\n");
    return 1;
  }

  if (!str) {
    write("How much experience do you want to swap to guild experience?\n");
    return 1;
  }
  if (sscanf(str, "%d", amount) != 1) {
    write("Usage: swap <amount>\n");
    return 1;
  }
  if (amount <= 0) {
    write("You must swap a positive amount.\n");
    return 1;
  }
#if 0
  if ((int)this_player()->query_extra_level() < 1)
    minexp = (int)this_player()->query_exp() -
             (int)call_other("room/adv_guild",
                             "get_next_exp",
                             (int)this_player()->query_level() - 1);
  else
    minexp = (int)this_player()->query_exp() -
             (int)call_other("room/exlv_guild",
                             "get_next_exp",
                             (int)this_player()->query_extra_level() - 1);
  if (amount < -minexp) {
#else
  if (amount > (int)this_player()->query_free_exp()) {
#endif
    write("You don't have enough experience available to swap that much.\n");
    write("You may swap a total of " +
#if 0
          ((int)this_player()->query_exp() - minexp) +
#else
          (int)this_player()->query_free_exp() +
#endif
          ".\n");
    return 1;
  }
  write_file(GUILD_LOG + "swap",
             capitalize((string)this_player()->query_real_name()) +
             " just swapped " + amount + " exp.\n" +
             "Remaining XP: " + this_player()->query_exp() + "\n" +
             "The time is : " + ctime(time()) + "\n" +
             "---------------------------------------------------\n\n");
  this_player()->add_exp(-amount);
  this_player()->add_guild_exp(amount);
  write("Thank you for using Dopplerz 'R Us Franchised Swapping Credit " +
        "Union.\n");
  return 1;
}

int advance() {
  int minexp;
  object badge;

  badge = present("V-GUILD", this_player());
  if (!badge || !badge->query_faction("mystic")) {
    write("You are not a member of the Mystic Faction yet...type \"join\".\n");
    return 1;
  }
  switch(this_player()->query_guild_rank()) {
  case 10: minexp = 250000; break;
  case 11: minexp = 300000; break;
  case 12: minexp = 350000; break;
  case 13: minexp = 400000; break;
  case 14: minexp = 450000; break;
  default:
    write("You are at the highest level in the Mystic Faction.\n");
    return 1;
    break;
  }
  if ((int)this_player()->query_guild_exp() < minexp) {
    write("You do not have enough guild experience to advance.\n");
    return 1;
  }
  this_player()->add_guild_rank(1);
  CHAND->channel_message("dopplegangerM",
                         this_player()->query_name() +
                         " just advanced to level " +
                         this_player()->query_guild_rank() +
                         " in the guild!!\n",
                         HIB + "[Grimm's Assistant]: " + NORM);
  write_file(GUILD_LOG + "advance",
             capitalize((string)this_player()->query_real_name()) +
             " just advanced to level " +
             this_player()->query_guild_rank() + ".\n" +
             "The time is : " + ctime(time()) + "\n" +
             "------------------------------------------------------\n\n");
  return 1;
}

