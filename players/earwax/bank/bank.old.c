/* **************************************************************************
 * File:           ~/bank/bank.c                                            *
 * Function:       Bank System: withraw what they put in during a boot,     *
 *                 what they don't, saves, for use for houses and such.     *
 * Author:         Earwax                                                   *
 * Copyright:      Copyright (c) 2004 Earwax.  All rights reserved.         *
 * Source:         5/23/04                                                  *
 * Notes:          Mainly for players to build up cash for housing.         *
 *                 Don't read this if you can't stand cursing.              *
 * Change History:                                                          *
 * *************************************************************************/

#include <ansi.h>

#pragma weak_types
#pragma combine_strings

/* Definitions */
#define WAXFUNS "/players/earwax/lib/waxfuns.c"              
#define BANK "/players/earwax/bank/bank.c"
#define LANDD "/players/earwax/housing/land_daemon.c"
#define STUFFD "/players/earwax/housing/sort_daemon.c"
#define BANKDATA "players/earwax/bank/bank"
#define TLOG "/players/earwax/bank/TRANSFER"

inherit "/room/room.c";

/* Global Variables */
static mapping  Current;      /* ([ Name : Withdrawable amount ])          */
       mixed   *Xfers;        /* ({ ({ Name, Amount, Remarks }) })         */
/* **************************************************************************
 * Function:     show_sign, read_sign                                       *
 * Description:  Show the contents of a sign.                               *
 * Arguements:   none                                                       *
 * Return:       string                                                     *
 * *************************************************************************/
string
show_sign()
{
  return "You can do the following here:\n"
         +HIW+"balance\n"+
         "deposit"+HIK+" <amount> (or 'all')\n"+HIW+
         "withdraw"+HIK+" <amount>\n"+HIW+
         "transfer"+HIK+" <amount> <player> <reason>\n"+NORM+NORM;
  /* Stuffs to put in later 
         "statement\n"+
  */ 
}

status
read_sign(string arg)
{
  if (arg == "sign" || arg == "at sign")
  {
    write(show_sign());
    return 1;
  }
  
  notify_fail("You can only read or look at the sign.\n");
  return 0;
}
/* **************************************************************************
 * Function:     do_balance, clan_balance                                   *
 * Description:  Show a player's or clan's bank balances                    *
 * Arguements:   None                                                       *
 * Return:       int                                                        *
 * *************************************************************************/
status
do_balance(string arg)
{
  int balance, now;
  string t, name;

  name = (string)this_player()->query_real_name();
  balance = (int)this_player()->query_bank_balance();  
  now = (member(Current, name) ? Current[name] : 0);
  t = (balance ? HIY : (balance < 0 ? HIR : YEL)) 
    + (string)STUFFD->comma_number(balance) + NORM + NORM;
  write("Your bank balance is: "+t+"\n");
  write("You may ");
  write((now ? "withdraw up to "+now+" coins.\n" : "not withdraw coins.\n"));
  return 1;
}

status
clan_balance(string arg)
{
  int index;
  
  return 1;
}
/* **************************************************************************
 * Function:     transfer                                                   *
 * Description:  Transfer funds to a player from institution or player      *
 * Arguements:   arg                                                        *
 * Return:       int                                                        *
 * *************************************************************************/
varargs status
do_transfer(string arg, object tp)
{
  object ob;
  string reason, from, to, filename, name, message;
  int amount, fbal, flag;
  
  /*
   * Do the standard checks: syntax, enough funds to cover the transaction.
write("Amount: "+amount+"\nTo: "+to+"\nReason: "+reason+"\n");
   */
  if (!tp) { flag = 1; tp = this_player(); }

  if (!arg || (sscanf(arg, "%d %s %s", amount, to, reason) != 3
    && sscanf(arg, "%s %d %s", to, amount, reason) != 3))
  {
    notify_fail("Syntax: transfer <amount> <toplayer> <reason> - or -\n"
      +         "        transfer <player> <amount> <reason>.\n");
    return 0;
  }
  
  if ((int)tp->query_bank_balance() < amount)
  {
    notify_fail("You don't have the funds to transfer "+amount+" coins to "+to+".\n");
    return 0;
  }

  name = (string)tp->query_real_name();

  /*
   * Player to transfer is online, that makes it easier :)
   */
  if ((ob = find_player(to))) 
  {
    string t;

    t = (string)STUFFD->comma_number(amount);
    tell_object(ob, HIY+capitalize(name)+" just transfered "+t+" to your bank account.\n"
      +"Reason: "+reason+"\n"+NORM+NORM);
    write("You transfer "+t+" coins to "+capitalize(to)+"'s bank account.\n");
    tp->add_bank_balance(-amount);
    ob->add_bank_balance(amount);
    message = (string)WAXFUNS->date_time()+": "
      + HIR + " XFER " + NORM + NORM +"("+amount+") "
      + capitalize(name) + " to "+ capitalize(to)
      + " (online): " + reason + "\n";
    write_file(TLOG, message);
    this_object()->add_message(to, 0, message);
    return do_balance("Verte tells you, 'Leave my sheep alone!'\n");
  }
  
  message = (string)WAXFUNS->date_time()+": "
    + HIR + " XFER " + NORM + NORM +"("+amount+") "
    + capitalize(name) + " to "+ capitalize(to) + " (player): " + reason + "\n";
  write_file(TLOG, message);
  this_object()->add_message(to, amount, message);
  tp->add_bank_balance(-amount);
  return do_balance("SkullFuckedByALeperColony.com - Verte's life story");
}
/* **************************************************************************
 * Function:     do_withdraw, clan_withdraw                                 *
 * Description:  Withdraw cash from Current fundage                         *
 * Arguements:   None                                                       *
 * Return:       int                                                        *
 * *************************************************************************/
status
do_withdraw(string arg)
{
  int amount, curr;
  string name;

  name = (string)this_player()->query_real_name();

  if (!Current || !(member(Current, name)))
  {
    notify_fail("You don't have any funds to withdraw this reboot.\n");
    return 0;
  }
    
  if (!arg || !strlen(arg))
  {
    notify_fail("How much would you like to withdraw\n");
    return 0;
  }
  
  if (sscanf(arg+"", ""+"%d", amount) != 1 && arg != "all")
  {
    notify_fail("You must specify an amount to deposit.\n");
    return 0;
  }

  if (arg == "all")
  {
    curr = (int)this_player()->query_money();
    amount = (((80000 - curr) < Current[name]) ? (80000 - curr) : Current[name]);
  }
  
  if (!amount)
  {
    notify_fail("Uhm, okay, you withdraw nothing.\n");
    return 0;
  }
  
  if (amount < 0)
  {
    notify_fail("Why on earth would you want to withdraw a negative amount?\n");
    return 0;
  }
    
  if (amount > Current[name])
  {
    notify_fail("You don't have that withdrawable cash.\n");
    return 0;
  }
  
  if (amount > (int)this_player()->query_bank_balance())
  {
    notify_fail("You must resolve your negative bank balance first.\n");
    return 0;
  }
  
  this_player()->add_money(amount);
  write("You withdraw "+amount+" coins from the bank.\n");
  Current[name] -= amount;
  this_player()->add_bank_balance(-amount);
  return do_balance("Yeah Verte, you like it in your ear don't you!\n");
}
/* **************************************************************************
 * Function:     do_deposit, clan_deposit                                   *
 * Description:  Deposit cash into accounts, withdrawable until reboot.     *
 * Arguements:   None                                                       *
 * Return:       int                                                        *
 * *************************************************************************/
status
do_deposit(string arg)
{
  int amount, curr;
  string name;
  
  if (!arg || !strlen(arg))
  {
    notify_fail("How much would you like to deposit?\n");
    return 0;
  }
  
  if (sscanf(arg+"", ""+"%d", amount) != 1 && arg != "all")
  {
    notify_fail("You must specify an amount to deposit.\n");
    return 0;
  }
  
  if (arg == "all")
    amount = (int)this_player()->query_money();
     
  if (!amount)
  {
    notify_fail("Uhm, okay, you deposit nothing.\n");
    return 0;
  }
  
  if (amount < 0)
  {
    switch(random(5))
    {
      case 0 : notify_fail("You deposit, hey, WAIT a SECOND!  You're smoove, but not smoove enough.\n");
      case 1 : notify_fail("If you are reading this, you're in big trouble.\n");
      case 2 : notify_fail("Come on now, how stupid do you think we are?\n");
      case 3 : notify_fail("The teller whispers to you, 'Not on my watch buster!'\n");
      case 4 : notify_fail("Yeah, sure, we'll get right on that.\n");
    }
    return 0;
  }
    
  if (amount > (int)this_player()->query_money())
  {
    notify_fail("You don't have that much money.\n");
    return 0;
  }
  
  name = (string)this_player()->query_real_name();
  curr = (int)this_player()->add_bank_balance(amount);
  if (member(Current, name)) Current[name] += amount;
  else Current[name] = amount;
  this_player()->add_money(-amount);
  
  if ((int)this_player()->query_level() < 20)
    command("save", this_player());
  
  write("You deposit: "+amount+" coins that are withdrawable until reboot.\n");    
  return do_balance("HUG MY NUTS VERTE!\n");
}
/* **************************************************************************
 * Function:     add_message                                                *
 * Description:  transfer information etc                                   *
 * Arguements:   name, amount, reason                                       *
 * Return:       void                                                       *
 * *************************************************************************/
void
add_message(string name, int amount, string reason)
{
  restore_object(BANKDATA);
  
  if (!sizeof(Xfers))
    Xfers = ({ ({ name, amount, reason }) });
  else
    Xfers += ({ ({ name, amount, reason }) });
    
  save_object(BANKDATA);   
}
/* **************************************************************************
 * Function:     init                                                       *
 * Description:  actions to occur when a living enters room                 *
 * Arguements:   none                                                       *
 * Return:       void                                                       *
 * *************************************************************************/
void
init()
{
  string name;
  int i, flag;
  mixed *arr;

  ::init();
  arr = ({ ({ }) });  
  name = (string)this_player()->query_real_name();

  i = sizeof(Xfers);
  flag = 0;
  
  if (i)
    while(i--)
    {
      if (sizeof(Xfers[i]) && Xfers[i][0] == name)
      {
        string t; t = (string)STUFFD->comma_number(Xfers[i][1]);
        flag = 1;
        this_player()->add_bank_balance(Xfers[i][1]);
        write(HIY+"=================================================================\n"+NORM+NORM);
        write("TRANSFER TO YOU: "+t+" - "+Xfers[i][2]);
        arr += Xfers[i];
        Xfers[i] = ({ ({ }) });
      }
    }
  
  if (flag)
  {
    write(HIY+"=================================================================\n"+NORM+NORM);
    Xfers -= arr;
    save_object(BANKDATA);
  }
  
  add_action("read_sign", "read");
  add_action("do_balance", "balance");
  add_action("do_withdraw", "withdraw");
  add_action("do_deposit", "deposit");
  add_action("do_transfer", "transfer");
  add_action("read_sign", "look");
  add_action("read_sign", "l");
}  
/* **************************************************************************
 * Function:     reset                                                      *
 * Description:  Called upon creation and resets                            *
 * Arguements:   status arg (0 for creation, 1 for resets)                  *
 * Return:       void                                                       *
 * *************************************************************************/
void
reset(status arg)
{
  ::reset(arg);
  
  if (arg)
    return;
  
  set_light(1);
  short_desc = HIY + "Earwaxian National Bank" + NORM+NORM;
  long_desc = (string)WAXFUNS->line_wrap("Beautiful stained glass windows adorn this \
temple to money; here, gold is the god, and tellers are its priests and \
priestesses.  There is a small "+HIW+"sign"+NORM+NORM+" you can "+HIW+"read" +
  NORM+NORM+" or "+HIW+"look"+NORM+NORM+" at.\n");
  items = ({ "windows" , "A beautiful tribute to money in its various forms"
           , "stained glass windows", "They depict money in its various forms"
           , "glass windows", "They dipict money in its various forms"
           , "tellers", "Their eyes are lit with avarice"
           , "priests", "Their eyes are glowing with greed"
           , "priestesses", "Their eyes are glowing with greed"
           , "temple", "This is a temple dedicated to the gods of gold"
           , "god", "Gold is god here"
           , "gold", "It's locked away nice and safe - from you"
          });
  dest_dir = ({ "/room/bank", "south" }); /* Add an accounts room later? */
  Current = ([ ]); 
  Xfers = ({ ({ }) });
  restore_object(BANKDATA);
}

        
