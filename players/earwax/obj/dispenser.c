/* **********************************************************************
 * /players/earwax/obj/dispenser.c
 *
 * Dispenser for my products
 *
 * - Earwax 6/03
 *
 * **********************************************************************
*/
#include "defs.h"

#define DLOG "/players/earwax/obj/dlog"

inherit WAXFUNS;
inherit "/obj/clean";

/* Global Variables */
string *Products;

/* Prototypes */
status tracker_info(string arg);
status dispense_tracker(string arg);
status do_list(string arg);

status get() { return 0; }
status drop() { return 1; }

string short() { return HIK+"An Earwaxian Products Dispenser"+NORM+NORM; }

status id(string arg) { return (arg == "dispenser" || arg == "machine"); }

void long() {
  say((string)this_player()->query_name()+" looks at "+short()+".\n");
  write(short()+"\n");
  write(YEL+"----------------------------------------------------------------------\n"+NORM+NORM);
  write("This is a machine that dispenses creations of the wizard Earwax.\n");
  write("\n");
  do_list("products");
  write(YEL+"----------------------------------------------------------------------\n"+NORM+NORM);
}

status
do_info(string arg)
{
  if (arg == "tracker")
  {
    return tracker_info(arg);
  }

  if(!Products) this_object()->reset(0);
  if (!arg || member_array(arg, Products) < 0)
  {
    notify_fail("Invalid selection.  What would you like information on?\n");
    return 0;
  }

  cat(INFO_PATH+arg);
  return 1;
}

status
do_purchase(string arg)
{
  int cost, index;
  string prod;
  object ob;

  if (arg == "tracker")
    return dispense_tracker(arg);

  if(!Products) this_object()->reset(0);
  if ((index = member_array(arg, Products)) < 0)
  {
    notify_fail("Invalid selection.  See "+HIW+"list products"+NORM+NORM+".\n");
    return 0;
  }

  if(!Products) this_object()->reset(0);
  prod = PRODUCTS+Products[index];
  sscanf((string)prod->query_cost(), "%d"+"", cost);

  if ((int)this_player()->query_money() < cost)
  {
    if (arg == "syringe" && (string)this_player()->query_guild_name() == "cyberninja")
    {
      object gob;

      gob = present("implants", this_player());
      if (gob) 
      {
        write("Not enough coins, checking credit balance...\n");
        if ((int)gob->balance() < cost)
        {
          write("You lack the coins and credits for this purchase.\n");
          return 1;
        }
        else
        {
          write("Taking funds from your credit balance...\n");
          gob->addToBalance(-cost);
          gob->save_me();
          cost = 0;
        }
      }
      else
      {
        notify_fail("You don't have "+cost+" coins.\n");
        return 0;
      }
    }
    else
    {
      notify_fail("You don't have "+cost+" coins.\n");
      return 0;
    }
  }

  ob = clone_object(prod);
  write_file(DLOG, ctime() + ": "+arg+" purchased by "+capitalize((string)this_player()->query_real_name())+".\n");
  move_object(ob, this_player());
  write("Congratulations, you have just purchased "+(string)ob->short()+".\n");
  say((string)this_player()->query_name()+" purchases a "+(string)ob->short()+".\n", this_player());
  this_player()->add_money(-cost);
  return 1;
}



void
reset(status arg)
{
  int i;

  if (arg)
    return;

  set_no_clean(1);
  i = sizeof(Products = get_dir(PRODUCTS+"*.c"));

  while(i--)
    sscanf(Products[i], "%s.c", Products[i]);
}

status
do_list(string arg)
{
  int i, siz;
  string temp;

  if (arg && arg != "products")
  {
    notify_fail("List what?\n");
    return 0;
  }

  write("The following products are available for purchase:\n\n");

  write(lalign("FREE!", 10) + lalign("tracker", 15) + "The Legendary PK Tracker (must be level 10).\n");
  if(!Products) this_object()->reset(0);
  siz = sizeof(Products);

  for (i = 0; i < siz; i++)
  {
    temp = PRODUCTS + Products[i];
    write(lalign((string)temp->query_cost(), 10)
    + lalign((string)temp->query_my_name(), 15)
    + lalign((string)temp->query_desc(), 50) + "\n");
  }

  write("\n"+HIW+"info <product>"+NORM+NORM+" to see information about a product.\n");
  write(HIW+"purchase <product>"+NORM+NORM+" to purchase one.\n");
  return 1;
}












/* ===========================================
 * PK Tracker Stuff
 * ===========================================
*/
status tracker_info(string arg) {

  write(HIK+"Legendary PK Tracker"+NORM+NORM+"\n\
The PK tracker was developed by Earwax and Jareel to provide a standard of \n\
judging the worth of player-kills.  It's a small device that will autoload \n\
on a player, and provide a means of tracking their kills, deaths, and the \n\
point values of their kills.\n\n");

write("\
The way points break down is fairly complex, but in a nutshell, players \n\
below level 10 are worth no points, players from level 11 to 19 are worth \n\
their level in points, and there's an additional point per 10 x-levels of \n\
the target.  The killer also gains a point per 100 PK points of their victim. \n\
In other words, a level 19+9 player with 230 PK points would be worth 19+1+2 \n\
base points.  Finally, the tank of a fight will gain 2 additional points, \n\
although for everyone hitting behind him, he loses 1 point.  In other words, \n\
for each additional player killing the victim, everyone loses 1 point, but \n\
the tank gains a bounus of 2 points. \n\n");

write("\
The reason for the points being done this way is simply an attempt to encourage \n\
more players to attack groups, to attack stronger pkers (rather than attacking \n\
the weak link every time), and to slightly discourage the usual pack-hunting. \n\
Solo kills are more rewarding under this system, as is attacking strong pkers \n\
and higher level players.  Lastly, kills recorded by players under level 10, \n\
whether they have a tracker or not, will not award points.  This is to create \n\
a more even playing field, where players won't be trying to stay at level 9 to \n\
pull kills or prey on other low level chars, if all players are over level 10 \n\
it's a more even playing-field, and the integrity of the points is more valid. \n\
"+HIR+"Comments, bugs, and suggestions can be mailed to Earwax and/or Jareel."+NORM+"\n");
  return 1;
}

status dispense_tracker(string arg) {
  object ob;

  if (!arg || arg != "tracker") {
    notify_fail("syntax: info tracker\n");
    return 0;
  }

  if (present(TRACKER_ID,this_player())) {
    notify_fail("You already have a PK Tracker.\n");
    return 0;
  }

  if ((int)this_player()->query_level() < 10) {
    notify_fail("You must be level 10 to receive a PK Tracker.\n");
    return 0;
  }

  ob = clone_object(TRACKER_OBJ);
  if (!ob) {
    notify_fail("Object did not clone.  Mail Earwax.\n");
    return 0;
  }
  write("Congratulations, you now have a PK Tracker.  Good luck and happy\
 hunting.\n");
  move_object(ob,this_player());
  return 1;
}

void
init()
{
  add_action("do_purchase", "purchase");
  add_action("do_info", "info");
  add_action("do_list", "list");
}
