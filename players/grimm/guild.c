/*
 * Recode of guild.c
 * Rumplemintz
 */

#pragma strong_types
#include <ansi.h>

inherit "/room/room";

void reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_short("The Sacred Blood Doppleganger Guilds");
  set_long("You have entered the " + BOLD +
           "Sacred Blood Doppleganger Guild" + NORM + ".\n" +
           "Type 'list' for a list of commands.\n");
  dest_dir = (({ "/players/grimm/newbie/rooms/entrance", "east",
                 "/players/grimm/closed/obj/badge_stuff/guild_pr", "west"
  }));
}

int check_guild() {
  if ((string)this_player()->query_guild_name() == "doppleganger" ||
      this_object()->query_npc() )
    return 0;
  else {
    write("You are not a member of the Doppleganger's guild. " +
          "You cannot enter that room.\n");
    return 1;
  }
}

void tell_em(string str) {
  object *people;
  int n;

  people = users();
  for (n=0; n < sizeof(people); n++) {
  if((string)people[n]->query_guild_name() == "doppleganger")
    tell_object(people[n], BOLD + "[Grimm's Assistant]: " + NORM +
                this_player()->query_name() + " just " + str + 
                " the guild!\n");
  }
}


void init() {
  ::init();
  add_action("check_guild", "west");

  /* Guild Functions */
  add_action("unjoin", "unjoin");
  add_action("join",   "join");
  add_action("list",   "list");
  add_action("swap",   "swap");
  add_action("rejoin", "rejoin");
  add_action("cost",   "cost");
  add_action("advance","advance");
}

int list() {
  write("          Commands you can do:\n"+
        "          -----------------------------------------------------\n"+
        "          Advance .. Advance your level in the guild\n"+
        "          Cost ..... Check the costs in coins of advancing\n"+
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

  if (this_player()->query_guild_name()) {
    write("You have already joined a Guild.\n");
    return 1;
  }
  if ((string)this_player()->query_guild_name() == "doppleganger") {
     write("You are already a member.\n");
     return 1;
  }
  if ((int)this_player()->query_level() < 3) {
    write("You must be level 3 to join a guild.\n");
    return 1;
  }

  badge = clone_object("/players/grimm/closed/obj/badge");
  move_object(badge, this_player());
  this_player()->add_guild_exp(1);
  this_player()->set_guild_name("doppleganger");
  this_player()->set_guild_rank(1);
  tell_em("joined");
  write("You have just joined the Guild of Dopplegangers!!!\n");

  write_file("/players/grimm/closed/LOGS/guild",
             capitalize((string)this_player()->query_real_name()) +
             " just joined the guild.\n" +
             "The time is: " + ctime(time()) + ".\n" +
             "-----------------------------------------------------\n");
  return 1; 
}

scrap(str) {
  string ln,it,what;
  int j,i;
  if(!str) what="unjoined";
  else what=str;
  i=0;
  j=1;
  ln=read_file("/players/grimm/closed/obj/badge_stuff/register",j);
  while(ln) {
    if(ln==this_player()->query_real_name()+"\n") {
      i=1;
      write_file("/players/grimm/closed/obj/badge_stuff/reg.tmp",this_player()->query_real_name()+"  ->  "+what+"\n");
    } else write_file("/players/grimm/closed/obj/badge_stuff/reg.tmp",ln);
    j++;
    ln=read_file("/players/grimm/closed/obj/badge_stuff/register",j);
  }
  if(i) {
    rm("/players/grimm/closed/obj/badge_stuff/register");
    cp("/players/grimm/closed/obj/badge_stuff/reg.tmp",
       "/players/grimm/closed/obj/badge_stuff/register");
    rm("/players/grimm/closed/obj/badge_stuff/reg.tmp");
  } else
    write_file("/players/grimm/closed/obj/badge_stuff/register",
               this_player()->query_real_name()+"  ->  "+what+"---FRIED!\n");
  return 1;
}

status unjoin() {
  object badge;

  if ((string)this_player()->query_guild_name() != "doppleganger")
    return 1;

  write_file("/players/grimm/closed/LOGS/unguild",
             capitalize((string)this_player()->query_real_name()) +
             " had " + this_player()->query_guild_exp() +
             " guild exp when " + this_player()->query_pronoun() +
             " unjoined.\n" +
             "The time is: " + ctime(time()) + ".\n" +
             "--------------------------------------------------------\n");
  this_player()->add_exp((int)this_player()->query_exp() / 6);
  destruct(present("V-GUILD", this_player()));
  this_player()->set_title("[Dopple TRAITOR!]");
  this_player()->set_al_title("[Don't Trust me!]");
  this_player()->set_guild_name(0);
  this_player()->set_guild_rank(0);
  this_player()->set_guild_exp(0);
  tell_em("unjoined");
  write("You have just unjoined the doppleganger's guild.\n");
  return 1;
}

int cost() {
  if((string)this_player()->query_guild_name() != "doppleganger") {
    write("You are not a member of the guild yet...type \"join\"\n");
    return 1;
  }
  write("                        Costs to advance in the guild (in exp)\n"+
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
        "                        You currently have:  " +
        this_player()->query_guild_exp() + " guild exp.\n\n\n");
  return 1;
}

int swap(string str) {
  int amount, minexp;

  if ((string)this_player()->query_guild_name() != "doppleganger") {
    write("You are not a member...type \"join\"\n");
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
    write("You don't have enough experience available to swap that much.\n");
    write("You may swap a total of " + ((int)this_player()->query_exp() -
                                        minexp) + ".\n");
    return 1;
  }
  if ((int)this_player()->query_guild_exp() >= 180000) {
    write("You have already swapped the maximum amount.\n");
    return 1;
  }
  write_file("/players/grimm/closed/LOGS/swaps",
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
  int xp_needed;
  int x, y, z;
  if((string)this_player()->query_guild_name() != "doppleganger") {
    write("You are not a member...type \"join\"\n");
    return 1;
  }

  switch(this_player()->query_guild_rank()) {
    case 1: xp_needed = 5000;
    case 2: xp_needed = 15000;
    case 3: xp_needed = 30000;
    case 4: xp_needed = 50000;
    case 5: xp_needed = 75000;
    case 6: xp_needed = 105000;
    case 7: xp_needed = 140000;
    case 8: xp_needed = 180000;
    default:
      write("You are the highest level possible in the guild.\n");
      return 1;
      break;
  }
  if ((int)this_player()->query_guild_exp() < xp_needed) {
    write("You do not have enough exp on account to advance yet.\n");
    return 1;
  }
  this_player()->set_guild_rank((int)this_player()->query_guild_rank() + 1);
  write("You are now level " +
        this_player()->query_guild_rank() + " in the guild!\n");
  tell_em("advanced to " + this_player()->query_guild_rank() + " in");
  write_file("/players/grimm/closed/LOGS/advanced",
             capitalize((string)this_player()->query_real_name()) +
             " just advanced to level " +
             this_player()->query_guild_rank() +
             " in the guild.\n" +
             "The time is: " + ctime(time()) + ".\n" +
             "---------------------------------------------------------\n");
  return 1;
}

int rejoin() {
  object badge;

  if ((string)this_player()->query_guild_name() != "doppleganger") {
    write("You were not found in the guild's register.\n");
    return 1;
  }
  if (present("V-GUILD", this_player())) {
    write("You already have a guild badge, you do not need to rejoin.\n");
    write("Use the 'renew' command to get a new badge.\n");
    return 1;
  }
  write("Your name was found in the register. Management stresses its\n" +
        "apologies\n");
  move_object(clone_object("/players/grimm/closed/obj/badge"), this_player());
  tell_em("rejoined");
  return 1;
}

