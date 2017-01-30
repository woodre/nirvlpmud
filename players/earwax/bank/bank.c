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
 *   Implementation by Vertebraker, quite a few code changes.               *
 *   10/13/05 Earwax: Daemonized it.                                        *
 * *************************************************************************/

#include <ansi.h>

#pragma weak_types
#pragma combine_strings

/* Definitions */            
#define BANKD    "/players/earwax/bank/bankd.c"
#define LANDD    "/players/earwax/housing/land_daemon.c"
#define STUFFD   "/players/earwax/housing/sort_daemon.c"
#define BANKDATA "/players/earwax/bank/bank"
#define TLOG     "TRANSFERS"

#define DSP_NUM(x) (string)STUFFD->comma_number(x)
#define BAR "\
================================================================="

inherit "/room/room.c";
       
/* **************************************************************************
 * Function:    show_sign, read_sign                                       *
 * Description: Show the contents of a sign.                               *
 * Arguments:   none                                                       *
 * Return:      string                                                     *
 * *************************************************************************/
string
show_sign()
{
  return "You can do the following here:\n"
         +HIW+"balance\n\
deposit"+NORM+" <amount> (or 'all')\n"+HIW+"\
withdraw"+NORM+" <amount>\n"+HIW+"\
transfer"+NORM+" <player> <amount> <reason>\n\
\nSee 'help bank' for additional information before opening an account!\n";
  /* Stuffs to put in later 
         "statement\n"+
  */ 
}

void long(string str)
{
  if(str=="sign"||str=="the sign")
  {
    write(show_sign());
  }
  else ::long(str);
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
 * Arguments:   None                                                       *
 * Return:       int                                                        *
 * *************************************************************************/

string get_balance_str(int balance)
{
  return (string)BANKD->get_balance_str(balance);
}

status
do_balance()
{
	return (status)BANKD->do_balance();
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
  return (status)BANKD->do_transfer(arg, tp);
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
	return (status)BANKD->do_withdraw(arg);
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
	return (status)BANKD->do_deposit(arg);
}
/* **************************************************************************
 * Function:     init                                                       *
 * Description:  actions to occur when a living enters room                 *
 * Arguments:   none                                                       *
 * Return:       void                                                       *
 * *************************************************************************/
void
init()
{
	::init();
  BANKD->bank_init();  
  add_action("read_sign", "read");
  add_action("do_balance", "balance");
  add_action("do_withdraw", "withdraw");
  add_action("do_deposit", "deposit");
  add_action("do_transfer", "transfer");

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
  ::reset(arg);
  
  if (arg)
    return;
  
  set_light(1);
  set_no_clean(1);
  short_desc = HIY + "3rd Nirvana InterNational Bank" + NORM+NORM;
  long_desc = "\
  Beautiful stained glass windows adorn this temple to money;\n\
here, gold is the god, and tellers are its priests and\n\
priestesses. A statue of Earwax stands proudly in the middle\n\
of the room. There is a small "+HIW+"sign"+NORM+" here.\n";
  items =
  ({ 
    "windows", "\
A beautiful tribute to money in its various forms",
"stained glass windows", "\
A beautiful tribute to "+HIG+"money"+NORM+" in its various forms",
"glass windows", "\
A beautiful tribute to "+HIG+"money"+NORM+" in its various forms",
"tellers", "\
Their eyes are alit with "+HIG+"avarice"+NORM,
"priests", "\
Their eyes are glowing with "+HIG+"greed"+NORM,
"priestesses", "\
Their eyes are glowing with "+HIG+"greed"+NORM,
"temple", "\
This is a temple dedicated to the gods of "+HIY+"GOLD"+NORM,
"god", HIY+"GOLD"+NORM+" is GOD here",
"gold", "It's locked away nice and safe - from you",
"statue", "Great likeness, akin to Michaelangelo's David.\nBut the penis is just as small",
"earwax", "Great likeness, akin to Michaelangelo's David.\nBut the penis is just as small",
"sign", "",
          });
  dest_dir = ({ "/room/bank", "south" });
  /* Add an accounts room later? */
}

status is_castle() { return 1; }
