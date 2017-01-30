/* **************************************************************************
 * File:           ~/bank/bankd.c                                           *
 * Function:       The code behind the bank, ATMs                           *
 * Author:         Earwax                                                   *
 * Copyright:      Copyright (c) 2005 Earwax.  All rights reserved.         *
 * Source:         10/13/05                                                 *
 * Notes:                                                                   *
 * Change History:                                                          *
 *                        11/5/05: Verte added no clean, !Current check     *
 * *************************************************************************/

#include <ansi.h>

#pragma weak_types
#pragma combine_strings

/* Definitions */            
#define BANK     "/players/earwax/bank/bank.c"
#define LANDD    "/players/earwax/housing/land_daemon.c"
#define STUFFD   "/players/earwax/housing/sort_daemon.c"
#define BANKDATA "players/earwax/bank/bank"
#define TLOG     "TRANSFERS"
#define GETO     "/players/earwax/bank/ghettofix.c"

#define DSP_NUM(x) (string)STUFFD->comma_number(x)
#define BAR "\
================================================================="

/* Global Variables */
static mapping  Current;      /* ([ Name : Withdrawable amount ])          */
       mixed   *Xfers;        /* ({ ({ Name, Amount, Remarks }) })         */

status is_castle() { return 1; }
status id(string arg) { return arg == "LD"; }
/* **************************************************************************
 * Function:     add_message                                                *
 * Description:  transfer information etc                                   *
 * Arguments:   name, amount, reason                                       *
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
 * Function:     do_balance, clan_balance                                   *
 * Description:  Show a player's or clan's bank balances                    *
 * Arguments:   None                                                       *
 * Return:       int                                                        *
 * *************************************************************************/

string get_balance_str(int balance)
{
  return (((balance>0)?HIG:(balance<0?HIR:""))+
          DSP_NUM(balance)+NORM);
}

status
do_balance()
{
  int    balance;
  string t, name;
  object x;

  name = (string)(x=this_player())->query_real_name();
  balance = (int)x->query_bank_balance();  

  write("\
Your bank balance is: "+get_balance_str(balance)+".\n\
You may "+(Current[name] ? 
   "withdraw up to "+Current[name]+" coins.\n" :
   "not withdraw coins.\n"));
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
 * Arguments:   arg                                                        *
 * Return:       int                                                        *
 * *************************************************************************/
varargs status
do_transfer(string arg, object tp)
{
  object ob;
  string reason, from, to, filename, name, message;
  int amount, fbal, flag;
  
  if (!tp)
  {
    flag = 1;
    tp = this_player();
  }
  
  if((int)tp->query_level() >= 21)
  {
    write("No wizards.\nUse a test char.");
    return 1;
  }

  if (!arg || (sscanf(arg, "%d %s %s", amount, to, reason) != 3
    && sscanf(arg, "%s %d %s", to, amount, reason) != 3) ||
    amount <= 0)
  {
    notify_fail("\
Syntax: transfer <amount> <toplayer> <reason> -or-\n\
        transfer <player> <amount> <reason>.\n");
    return 0;
  }
  
  if ((int)tp->query_bank_balance() < amount)
  {
    notify_fail("You don't have the funds to transfer "+
         amount+" coins to "+to+".\n");
    return 0;
  }

  name = (string)tp->query_real_name();
 

  /*
   * Player to transfer is online, that makes it easier :)
   */
  if ((ob = find_player(to)) && 
      (int)ob->query_level() < (int)this_player()->query_level())
  {
    string t;

    t = DSP_NUM(amount);
    tell_object(ob, HIY+
capitalize(name)+" just transferred "+t+" to your bank account.\n\
Reason: "+reason+"\n"+NORM+NORM);
    write("You transfer "+t+" coins to "+capitalize(to)+"'s bank account.\n");
    tp->add_bank_balance(-amount);
    ob->add_bank_balance(amount);
    message = ctime()[4..15]+": "+HIR+"XFER"+NORM+" ("+amount+") "+
              capitalize(name)+" to "+capitalize(to)+" (online): "+
              reason + "\n";
    if(Current[name] >= amount) Current[name] -= amount;
    log_file(TLOG, message);
/*
    this_object()->add_message(to, 0, message);
*/
    command("save", tp);
    return do_balance();
  }
  message = ctime()[4..15]+": "+HIR+"XFER"+NORM+" ("+amount+") "+
            capitalize(name)+" to "+capitalize(to)+ " (player): " + reason + "\n";
  log_file(TLOG, message);
  add_message(to, amount, message);
  if(Current[name] >= amount) Current[name] -= amount;
  tp->add_bank_balance(-amount);
  command("save", tp);
  return do_balance();
}
/* **************************************************************************
 * Function:     do_withdraw, clan_withdraw                                 *
 * Description:  Withdraw cash from Current fundage                         *
 * Arguments:   None                                                       *
 * Return:       int                                                        *
 * *************************************************************************/
status
do_withdraw(string arg)
{
  int amount, curr, t;
  string name;

  name = (string)this_player()->query_real_name();

  if (!Current || !Current[name])
  {
    notify_fail("You don't have any funds to withdraw this reboot.\n");
    return 0;
  }
    
  if (!arg)
  {
    notify_fail("How much would you like to withdraw?\n");
    return 0;
  }
  
  if (arg == "all")
  {
    int geld;
    
    curr = (int)this_player()->query_money();
    amount = (((geld=(80000 - curr)) < Current[name]) ? 
              geld : Current[name]);
  }
  
  else if (!sscanf(arg, "%d", amount) || amount <= 0)
  {
    notify_fail("You must specify an amount to deposit.\n");
    return 0;
  }
      
  if (amount > Current[name])
  {
    notify_fail("You only have "+Current[name]+" coins available \
for withdrawal.\n");
    return 0;
  }
  
  if (amount > (int)this_player()->query_bank_balance())
  {
    notify_fail("\
You must resolve your negative bank balance first.\n");
    return 0;
  }

  t = (int)this_player()->query_money();
  if (t + amount > 80000)
  {
    amount = 80000 - t;
    write("You only need "+amount+" coins to reach max coins.\n");
  }
  
  this_player()->add_money(amount);
  write("You withdraw "+amount+" coins from the bank.\n");
  Current[name] -= amount;
  this_player()->add_bank_balance(-amount);
  command("save", this_player());
  return do_balance();
}
/* **************************************************************************
 * Function:     do_deposit, clan_deposit                                   *
 * Description:  Deposit cash into accounts, withdrawable until reboot.     *
 * Arguments:   None                                                       *
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

  if (arg == "all")
    amount = (int)this_player()->query_money();
  
  else if(!sscanf(arg,"%d",amount))
  {
    notify_fail("You must specify an amount to deposit.\n");
    return 0;
  }
     
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
         break;
      case 1 : notify_fail("If you are reading this, you're in big trouble.\n");
       break;
      case 2 : notify_fail("Come on now, how stupid do you think we are?\n");
         break;
      case 3 : notify_fail("The teller whispers to you, 'Not on my watch buster!'\n");
        break;
       break;
      case 4 : notify_fail("Yeah, sure, we'll get right on that.\n");
       break;
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
  Current[name] += amount;
  this_player()->add_money(-amount);
  
  if ((int)this_player()->query_level() < 20)
    command("save", this_player());
  
  write("You deposit "+amount+" coins which are available to be \
withdrawn until reboot [or crash ;)].\n");    
  return do_balance();
}
/* **************************************************************************
 * Function:     bank_init                                                  *
 * Description:  called by bank init                                        *
 * Arguments:    none                                                       *
 * Return:       void                                                       *
 * *************************************************************************/

void
bank_init()
{
  string name;
  int i, flag;
  mixed *arr;
  object x;

  if((x=this_player()) && query_ip_name(x))
  {
    arr = ({ ({ }) });  
    name = (string)x->query_real_name();
    
    if (i = sizeof(Xfers))
    while(i--)
      if (sizeof(Xfers[i]) && Xfers[i][0] == name)
      {
        string t; t = (string)STUFFD->comma_number(Xfers[i][1]);
        flag = 1;
        this_player()->add_bank_balance(Xfers[i][1]);
        write(HIY+BAR+NORM+"\n");
        write("TRANSFER TO YOU: "+t+" - "+Xfers[i][2]);
        arr += Xfers[i];
        Xfers[i] = ({ ({ }) });
      }
  
    if (flag)
    {
      write(HIY+BAR+NORM+"\n");
      Xfers -= arr;
      save_object(BANKDATA);
    }
  }
}  
/* **************************************************************************
 * Function:     reset                                                      *
 * Description:  Called upon creation and resets                            *
 * Arguments:   status arg (0 for creation, 1 for resets)                  *
 * Return:       void                                                       *
 * *************************************************************************/
void
reset(status arg)
{
  if (arg)
    return;
    
/*
  set_no_clean(1);
*/
  Xfers = ({ ({ }) });
  restore_object(BANKDATA);
  /* Add an accounts room later? */
 if(!Current)
  Current = ([ ]); 
/*
  move_object(this_object(), BANK);
*/

  /* In an effort to stop this damn thing from resetting 
   * Note: I hate using call_out() - it's one of the biggest lag
   * producers, however here, I'm kind of desperate.
  call_out("StayinAlive", 6000);
   */
}

void StayinAlive()
{
  object ob;

  if (!(ob = find_object(GETO)))
    ob = clone_object(GETO);

  move_object(ob, BANK);
  move_object(ob, this_object());
  /* Kiddies, don't do this at home...*/
  while(remove_call_out("StayinAlive") != -1);
  call_out("StayinAlive", 6000);
}

/* Ghetto fix for some shit. */
status getofix(string who, int amount) {
  object ob;
  if ((int)this_player()->query_level() < 1000) return 0;
  Current[who] += amount;
  ob = find_player(who);
  if (!ob) return 0;
  ob->add_bank_balance(amount);
  return 1;
}
