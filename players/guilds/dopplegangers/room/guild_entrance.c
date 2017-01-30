/*
 * Doppleganger Guild Entrance
 */

#include <ansi.h>
#include "/sys/wizlevels.h"
#include "../def.h"

inherit "room/room";

void reset(int arg) {
  if (arg) return;
  set_light(1);
  short_desc = "The Sacred Blood Doppleganger Guild";
  long_desc = "You have entered the " + HIW +
              "Sacred Blood Doppleganger Guild" + NORM + ".\n" +
              "Type 'list' for a list of commands.\n";
  dest_dir = ({
    GUILD_DIR + "room/guildhall", "west",
    "/players/grimm/newbie/rooms/entrance", "east",
  });
}

void init() {
  ::init();
  add_action("west", "west");   /* Doppleganger guild member check */
  add_action("list", "list");
  add_action("unjoin", "unjoin");
  add_action("join", "join");
  add_action("swap", "swap");
  add_action("rejoin", "rejoin");
  add_action("cost", "cost");
  add_action("advance", "advance");
}

int west() {
  string proom;

  proom = "/players/guilds/dopplegangers/room/guild_hall";
    
  if ((string)this_player()->query_guild_name() != "doppleganger" &&
     (int)this_player()->query_level() < WL_WIZARD) {
    /* Not a Doppleganger, and not a wizard? Don't allow entrance */
    write("You are not a member of the Doppleganger's guild.\n");
    write("Only the chosen will be allowed to enter here!\n");
    write("Join our guild before entering the guild's party room.\n");
    if (find_object(proom))
      tell_room(find_object(proom),
                  this_player()->query_name() + " tried to enter the room " +
                  "but got kicked out!\n");
    return 1;
  }
  return 0;
}

int list() {
  write("          Commands you can do:\n"+
        "          -----------------------------------------------------\n"+
        "          Advance .. Advance your level in the guild\n"+
        "          Cost ..... Check the costs of advancing\n"+
        "          Join ..... Join the guild\n"+
        "          List ..... This menu\n"+
        "          Rejoin ... Rejoin the guild if your badge is messed up\n"+
        "          Swap ..... Swap <x> experience for <x> guild experience\n"+
        "          Unjoin ... Unjoin the guild (loosing all guild rank!)\n"+
        "          -----------------------------------------------------\n\n");
  return 1;
}

int join() {
  object badge;

  if (this_player()->query_npc()) return 0;
  if (this_player()->query_guild_name()) {
    write("You are already a member of another guild.\n");
    return 1;
  }
  if (present("V-GUILD", this_player())) {
    write("You are already a member.\n");
    return 1;
  }
  if (this_player()->query_level() < 3) {
    write("You must be at least level 3 before you join.\n");
    return 1;
  }
  if (restore_object(GUILD_DIR + "member/" +
      (string)this_player()->query_real_name())) {
    write("You were already a Dopplegagner once, and left.\n");
    write("Please contact a wizard if you wish to join again.\n");
    return 1;
  }
  write("You have just joined the Guild of Dopplegangers!!!\n");
  CHAND->channel_message("dopplegangers",
                         capitalize((string)this_player()->query_real_name()) +
                         " just joined the Dopplegangers!!!\n",
                         HIR + "[Dopples] " + NORM + "Grimm's Assistant: ");
  badge = clone_object("/players/guilds/dopplegangers/guildob");
  move_object(badge, this_player());
  write_file(GUILD_LOG + "join",
             this_player()->query_real_name() + " just joined the guild.\n" +
             "The time is: " + ctime(time()) + ".\n" +
             "----------------------------------------------------------\n");
  this_player()->set_guild_exp(1);
  this_player()->set_guild_name("doppleganger");
  this_player()->set_guild_rank(1);
  this_player()->set_guild_file("/players/guilds/dopplegangers/guildob.c");
  badge->reset();
  badge->set_morph("bat");
  badge->set_fang_hit(5);
  badge->save_me(1);
  this_player()->save_character();
  return 1;
}

int unjoin() {
  if (((string)this_player()->query_guild_name() != "doppleganger") ||
      (!restore_object(GUILD_DIR + "member/" +
                      this_player()->query_real_name()))) {
    write("You are not a member of the Dopplegangers!\n");
    return 1;
  }
  write("WARNING: This will remove all status from the guild.\n");
  write("You will lose 1/6 of your regular experience as well!\n");
  write("Are you sure you want to do this?  (Y or N)\n");
  write("->> ");
  input_to("unjoin_decision");
  return 1;
}

unjoin_decision(string str) {
  if ((!str) || str == "n" || str == "N" || str == "no" || str == "No") {
    write("You have made a wise choice.  Leaving your status intact.\n");
    return 1;
  }
  CHAND->channel_message("dopplegangers",
                         capitalize((string)this_player()->query_real_name()) +
                         " just left the Dopplegangers!!!\n",
                         HIR + "[Dopples] " + NORM + "Grimm's Assistant: ");
  write_file(GUILD_LOG + "unjoin",
             capitalize(this_player()->query_real_name()) + ":\n" +
             "Guild Exp: " + this_player()->query_guild_exp() + "\n" +
             "Exp:       " + this_player()->query_exp() + "\n" +
             "Guild Lev: " + this_player()->query_guild_rank() + "\n" +
             "Time:      " + ctime(time()) + "\n" +
             "------------------------------------------------------\n");

  this_player()->add_exp(-((int)this_player()->query_exp() / 6) );

  destruct(present("V-GUILD", this_player()));
  this_player()->set_title("[Dopple TRAITOR!]");
  this_player()->set_al_title("[Don't Trust me!]");
  this_player()->set_guild_exp(0);
  this_player()->set_guild_name(0);
  this_player()->set_guild_rank(0);
  this_player()->set_guild_file(0);
  this_player()->set_home(0);
  this_player()->save_character();
  write("You have just left the Doppleganger Guild.\n");
  return 1;
}

int cost() {
  if((string)this_player()->query_guild_name() != "doppleganger") {
    write("You are not a member of the Doppleganger Guild.\n");
    return 1;
  }
  write(
"                        Costs to advance in the guild (in exp)\n"+
"                        --------------------------------------\n"+
"                        Level 1 ..........................Free\n"+
"                        Level 2 ......................... 5000\n"+
"                        Level 3 ........................ 15000\n"+
"                        Level 4 ........................ 30000\n"+
"                        Level 5 ........................ 50000\n"+
"                        Level 6 ........................ 75000\n"+
"                        Level 7 ....................... 105000\n"+
"                        Level 8 ....................... 140000\n"+
"                        Level 9 ....................... 180000\n"+
"                        --------------------------------------\n"+
"                        You currently have:            " +
                         this_player()->query_guild_exp() + "\n\n");
  return 1;
}

int swap(string str) {
  int amount, minexp;

  if ((string)this_player()->query_guild_name() != "doppleganger") {
    write("You are not a Doppleganger!\n");
    return 1;
  }
  if (!str) {
    write("How much experience to you want to swap to guild experience?\n");
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
#if 0 /* Using query_free_exp now - Rumplemintz */
  if (this_player()->query_extra_level() < 1)
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
#if 0 /* Which changes this message as well */
          ((int)this_player()->query_exp() - minexp) +
#else
          (int)this_player()->query_free_exp() +
#endif
          "\n");
    return 1;
  }
  write_file(GUILD_LOG + "swap",
             capitalize((string)this_player()->query_real_name()) +
             " just swapped " + amount + " exp.\n"+
             "The time is : " + ctime(time()) + "\n" +
             "---------------------------------------------------\n\n");
  this_player()->add_exp(-amount);
  this_player()->add_guild_exp(amount);
  write("Thank you for using Dopplerz 'R Us Swapping Credit Union.\n");
  return 1;
}

int advance() {
  int minexp;

  if ((string)this_player()->query_guild_name() != "doppleganger") {
    write("You are not a Doppleganger!\n");
    return 1;
  }
  switch(this_player()->query_guild_rank()) {
  case 1: minexp = 5000; break;
  case 2: minexp = 15000; break;
  case 3: minexp = 30000; break;
  case 4: minexp = 50000; break;
  case 5: minexp = 75000; break;
  case 6: minexp = 105000; break;
  case 7: minexp = 140000; break;
  case 8: minexp = 180000; break;
  default:
    write("You are at the highest level in the Doppleganger's Guild.\n");
    return 1;
    break;
  }
  if ((int)this_player()->query_guild_exp() < minexp) {
    write("You do not have enough guild experience to advance.\n");
    return 1;
  }
  this_player()->add_guild_rank(1);
  write_file(GUILD_LOG + "advance",
             capitalize((string)this_player()->query_real_name()) +
             " just advanced to level " +
             this_player()->query_guild_rank() + ".\n" +
             "The time is : " + ctime(time()) + "\n" +
             "---------------------------------------------------\n\n");
  CHAND->channel_message("dopplegangers",
                         capitalize((string)this_player()->query_real_name()) +
                         " has advanced to guild level " +
                         this_player()->query_guild_rank() + "!!!\n",
                         HIR + "[Dopples] " + NORM + "Grimm's Assistant: ");
  return 1;
}

int rejoin() {
  object badge;

  if (present("V-GUILD", this_player())) {
    write("You already have a badge, use renew to get a new one.\n");
    return 1;
  }
  if ((string)this_player()->query_guild_name() != "doppleganger") {
    write("You are not a member of the Doppleganger Guild.\n");
    return 1;
  }
  if (!restore_object(GUILD_DIR + "member/" +
                      (string)this_player()->query_real_name())) {
    write("Cannot find your Doppleganger information, please seek a Wizard.\n");
    return 1;
  }
  badge = clone_object("/players/guilds/dopplegangers/guildob");
  move_object(badge, this_player());
  return 1;
}
