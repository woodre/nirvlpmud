/*
 *      File:                   /obj/rewards/nrpoints.c
 *      Function:               Nirvana Reward Points Inherit
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2007 David Halek
 *                                      All Rights Reserved.
 *      Source:                 06/28/07
 *      Notes:                  Inherited by player.c
 *      Change History:
 */

#include <security.h>
#include <ansi.h>

/* Global Variables */
       int nrpoints;       /* Their current nirvana reward points             */
       int totalpoints;    /* How many they've accumulated total              */
       int np_xlevel;      /* The highest xlevel player has achieved          */
       string nbday;       /* Their Nirvana birthday                          */
       string rlbday;      /* Their real birthday                             */
       int penalty_left;   /* In cases where they are penalized point-gaining */
       int np_age;         /* Their age for purposes of awarding points       */
static int is_bday;        /* Is it their RL or Nirvana bday today?           */
/* 
 * Function name:  Various query/add/set functions
 * Description:    
 */

int query_nrpoints() { return nrpoints; }

int add_nrpoints(int amount) 
{
#ifndef __LDMUD__
  if (file_name(previous_object()) != "obj/daemons/npoints")
#else
  if (object_name(previous_object()) != "obj/daemons/npoints")
#endif
  {
    string temp;
    string name;
  
    name = (string)this_object()->query_real_name();
    temp = ctime()+": "
      + (this_player() ? capitalize((string)this_player()->query_real_name())
#ifndef __LDMUD__
        : file_name(previous_object())) + " attempted to add " + amount 
#else
        : object_name(previous_object())) + " attempted to add " + amount
#endif
      + " points to " + name+".\n";
#ifndef __LDMUD__
    log_file("NP_VIOLATIONS", temp);
#else
    funcall(symbol_function('log_file), "NP_VIOLATIONS", temp);
#endif
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
  totalpoints += amount;
  return nrpoints; 
}

int set_nrpoints(int amount)
{
  int np_change;

#ifndef __LDMUD__  
  if (file_name(previous_object()) != "obj/daemons/npoints")
#else
  if (object_name(previous_object()) != "obj/daemons/npoints")
#endif
  {
    string name;
    string temp;

    name = (string)this_object()->query_real_name();
    temp = ctime()+": "
      + (this_player() ? capitalize((string)this_player()->query_real_name())
#ifndef __LDMUD__
        : file_name(previous_object())) + " attempted to set " + name 
#else
        : object_name(previous_object())) + " attempted to set " + name
#endif
      + "'s points to " + amount+".\n";
#ifndef __LDMUD__
    log_file("NP_VIOLATIONS", temp);
#else
    funcall(symbol_function('log_file), "NP_VIOLATIONS", temp);
#endif
    emit_channel("admin", "(admin) "+temp);
    return 0;
  }
  
  np_change = amount - nrpoints;
  nrpoints = amount;
  totalpoints += np_change;
  return np_change;
}

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

/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */

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
  else
    is_bday = (today != nbday && today[0..3] == nbday[0..3] ? 1 : 0);
/* can't do this yet
    is_bday = ((today != rlbday && today[0..3] == rlbday[0..3])
           ||  (today != nbday && today[0..3] == nbday[0..3]) ? 1 : 0);
*/
 
  if (is_bday)
  {
    /* Add the double xp stuff later? */
    write(HIR+BLINK+U+"\n\n\nHappy birthday, "+capitalize((string)this_object()->query_real_name())+"!\n\n\n"+NORM);
  }
  
  POINTSD->check_for_update((string)this_object()->query_real_name(), this_object()); 
}
