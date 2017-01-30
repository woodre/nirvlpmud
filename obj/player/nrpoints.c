/*
 *      File:                   /obj/rewards/nrpoints.c
 *      Function:               Nirvana Reward Points Inherit
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2007 David Halek
 *                                      All Rights Reserved.
 *      Source:                 06/28/07
 *      Notes:                  Inherited by player.c
 *      Change History:
 *        08/04/2016 Gnar - Updated for weekly login bonus.
 */

#include <security.h>
#include <ansi.h>

#include "/obj/player/nrpoints.h"

/* Global Variables */
       int nrpoints;       /* Their current nirvana reward points             */
       int totalpoints;    /* How many they've accumulated total              */
       int np_xlevel;      /* The highest xlevel player has achieved          */
       string nbday;       /* Their Nirvana birthday                          */
       string rlbday;      /* Their real birthday                             */
       int penalty_left;   /* In cases where they are penalized point-gaining */
       int np_age;         /* Their age for purposes of awarding points       */
/** Added for weekly login rewards **/
int lr_period_start;
int lr_required_exp;
int lr_exp;
int lr_top_exp;
int lr_streak;
int lr_top_streak;
int lr_flag;        /* Indicates if reward is earned already for the week */

static int is_bday;        /* Is it their RL or Nirvana bday today?           */
/* 
 * Function name:  Various query/add/set functions
 * Description:    
 */

void check_reward_period();

/*********************************************************
 * Added by Gnar for weekly login rewards
 ********************************************************/
int query_lr_period_start() { return lr_period_start; }

int query_lr_required_exp() { return lr_required_exp; }

int query_lr_exp() { return lr_exp; }

int query_lr_top_exp() { return lr_top_exp; }

int query_lr_streak() { return lr_streak; }

int query_lr_top_streak() { return lr_top_streak; }

int query_lr_flag() { return lr_flag; }

/*********************************************************/

int query_nrpoints() { return nrpoints; }

int query_is_bday() { return is_bday; }

int add_nrpoints(int amount) 
{
  if (object_name(previous_object()) != "obj/daemons/pointsd" && amount > 0)
  {
    string temp;
    string name;
  
    name = (string)this_object()->query_real_name();
    temp = ctime()+": "
      + (this_player() ? capitalize((string)this_player()->query_real_name())
        : object_name(previous_object())) + " attempted to add " + amount 
      + " points to " + name+".\n";
    log_file("NP_VIOLATIONS", temp);
    emit_channel("admin", "(admin) "+temp);
    return 0;
  }
  
  if (penalty_left)
  {
    if (penalty_left >= amount)
    {
      penalty_left -= amount;
      return nrpoints;
    }
    
    amount -= penalty_left;
    penalty_left = 0;
  }
  
  nrpoints += amount; 
  if( amount >  0 )
    totalpoints += amount;
  return nrpoints; 
}

int set_nrpoints(int amount)
{
  int np_change;

  if (object_name(previous_object()) != "obj/daemons/pointsd")
  {
    string name;
    string temp;

    name = (string)this_object()->query_real_name();
    temp = ctime()+": "
      + (this_player() ? capitalize((string)this_player()->query_real_name())
        : object_name(previous_object())) + " attempted to set " + name 
      + "'s points to " + amount+".\n";
    log_file("NP_VIOLATIONS", temp);
    emit_channel("admin", "(admin) "+temp);
    return 0;
  }
  
  np_change = amount - nrpoints;
  nrpoints = amount;
  if( np_change >  0 )
    totalpoints += np_change;
  return np_change;
}

void reset_login_rewards();

int query_totalpoints() { return totalpoints; }
int add_totalpoints(int amount) { totalpoints += amount; return totalpoints; }
void set_totalpoints(int amount) { totalpoints = amount; }

void set_rlbday(string bday) { rlbday = bday; }
void set_nbday(string bday) { nbday = bday; } 
string query_rlbday() { return rlbday; }
string query_nbday() { return nbday; }

int check_rlbday() 
{ 
  string today;
  
  today = (string)MISCD->get_date();
  return (today != rlbday && today[0..3] == rlbday[0..3]);
}

int check_nbday() 
{ 
  string today;
  
  today = (string)MISCD->get_date();
  return (today != nbday && today[0..3] == nbday[0..3]);
}

void set_penalty_left(int amount) { penalty_left = amount; }
void add_penalty_left(int amount) { penalty_left += amount; }
int query_penalty_left() { return penalty_left; }

/******************************************************************************
 * Function: login_checks
 *
 * Purpose: Called after the player logs in. Checks birthday and login rewards
 *          status.
 * Parameters:
 *
 * Returns: void
 * 
 * History:
 *         06/27/2007  - Earwax
 *            Created
 *          08/11/2016 - Dragnar
 *            Updated for login rewards system.
 ******************************************************************************/
void login_checks()
{
  string today;
  int xlevel;

  xlevel = (int)this_object()->query_extra_level();
  if (totalpoints < nrpoints) totalpoints = nrpoints;
  
  if ((int)this_object()->query_level() < 20 && xlevel > np_xlevel)
  {
    nrpoints += (xlevel - np_xlevel) * 10;
    totalpoints += (xlevel - np_xlevel) * 10;
    np_xlevel = xlevel;
  }
  
  today = (string)MISCD->get_date();
  
  if (!nbday) 
    nbday = today;
  else if( !MISCD->verify_bday( nbday ) )
    nbday = today;
  else
    is_bday = (today != nbday && today[0..3] == nbday[0..3] ? 1 : 0);
/** Real bday not set yet 
    is_bday = ((today != rlbday && today[0..3] == rlbday[0..3])
           ||  (today != nbday && today[0..3] == nbday[0..3]) ? 1 : 0);
**/
 
  if (is_bday)
  {
    write(HIR + BLINK + USCORE +
          "\n\n\nHappy birthday, " +
          capitalize((string)this_object()->query_real_name()) +
          "! Enjoy double XP all day!\n\n\n" + NORM);
  }

  /*********************************
   * Gnar - Login Rewards
   *********************************/
  if( (int) this_object()->query_level() < EXPLORE ) {
    /** Set start week for the first time **/
    if( !lr_period_start ) {
      reset_login_rewards();
    }

    check_reward_period();

  } 
  
  POINTSD->check_for_update((string)this_object()->query_real_name(), this_object()); 
}

void check_reward_period() {
  int week_start, diff;

  week_start = (int) this_object()->query_lr_period_start();
  diff = week_start + WEEK - time();

  /** Check to see if we are past the end of the week **/
  if( time() > lr_period_start + WEEK ) {
    /** Check to see if we met exp requirements or haven't logged in **/
    if( !lr_flag || time() > week_start + WEEK * 2 ) {
      write(HIW+"\nYour login streak has ended at "+ lr_streak +" weeks.\n\n"+NORM);
      lr_streak = 0;
    }
    else {
      write(HIW+"\nYou weekly rewards period has ended, continue your streak to earn more rewards!\n\n"+NORM);
    }
    reset_login_rewards();
  }

  /** Setup the callout to check period again **/
  if( diff < DAY ) {
    call_out( "check_reward_period", diff+1 );
  }

}

void give_login_reward() {
  int reward;

  lr_flag = 1;
  lr_streak += 1;
  if( lr_streak > lr_top_streak )
    lr_top_streak = lr_streak;

  reward = 5000 * lr_streak;
  /** Give a monthly bonus **/
  if( lr_streak % 4 == 0 )
    reward *= 2;
  write("You earned your login reward of "+comma_number(reward)+" points!\n");
  nrpoints += reward;
  totalpoints += reward;
  
}

void reset_login_rewards() {
  lr_period_start = time();
  lr_required_exp = (int) POINTSD->get_exp_required( this_object() );
  lr_exp = 0;
  lr_flag = 0;
}
