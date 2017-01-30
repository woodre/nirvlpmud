/*
 *      File:                   /players/khrell/weapons/poison2.c
 *      Function:               Poison object for weeping blade
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2005 Earwax/David Halek
 *                                      All Rights Reserved.
 *      Source:                 11/17/05
 *      Approved by:            
 *      Notes:                  Weeping blade checks for this poison object
 *                              on player, if not, it clones this file, calls
 *                              begin_poison().  If object already on there, 
 *                              it calls add_poison().  File is done this way
 *                              to eliminate need for multiple poison objects
 *                              and callouts.
 *      Change History:
 *
 * 06/25/06 Earwax:  hopefully fixed a bug where if the poison killed
 * a mob it could hose the death sequence.
 */

#include "defs.h"

/* 3 to 5 minute duration - avg 4 */
#define DURATION (180+random(61)+random(61))

/* 30 to 60 seconds, average 45 */
#define INTERVAL (30+random(31))

/* 8 to 12 damage */
#define POISON_DAM (8 + random(5))

/* Global Variables */
object  Victim;      /* 'Owner' of this object                 */
int    *Intervals;   /* Array of the intervals for counters    */
int    *Durations;   /* Array of the durations for counters    */
int     TotalDamage; /* Use this for logging purposes          */
int     TotalHits;   /* For Logging                            */
string  WhoDidMe;    /* Who reamed me real bad with this stuff */

void log_info()
{
  log_file(POISON_LOG, ctime()+": "
    + ((status)Victim->is_player() 
      ? (string)Victim->query_real_name() 
      : file_name(Victim)) 
    +" received "+TotalHits+" poisonings for "
    +TotalDamage + " damage, by: "+WhoDidMe+".\n");
}

/* 
 * Function name:  begin_poison, add_poison
 * Description:    Called by weepingblade to either initiate poisoning
 *                 or add more poison counters.
 * Arguments:      object victim
 * Returns:        void
 */

void begin_poison(object victim)
{
  object ob;
  
  Victim = victim;
  ob = (object)Victim->query_attack();
  TotalHits++;
  Intervals = ({ (time()+INTERVAL) });
  Durations = ({ (time()+DURATION) });
  WhoDidMe = ((status)ob->is_player() 
    ? capitalize((string)ob->query_real_name())
    : (string)ob->query_name());
  call_out("poison_player", INTERVAL);
}

void add_poison()
{
  TotalHits++;
  Intervals += ({ (time()+INTERVAL) });
  Durations += ({ (time()+DURATION) });
}

/* 
 * Function name:  poison_player
 * Description:    The fun stuff.  Performs actual damaging of the 
 *                 player, as well as ending the poison.
 * Arguments:      
 * Returns:        
 */

void poison_player()
{
  int i, interval, duration;
  object room;

  if (!Victim || Victim != environment(this_object()))
  {
    destruct(this_object());
    return;
  }
    
  i = sizeof(Intervals) - 1;
  room = environment(Victim);
  interval = Intervals[0]; /* Get initial information and then remove */
  duration = Durations[0]; /* array element */
  if (i)
  {
    Intervals = Intervals[1..i];
    Durations = Durations[1..i];
  }
  else
  {
    Intervals = ({ });
    Durations = ({ });
  }
  
  /* Before anything else, see if we should damage the player */
  if (interval <= duration)
  {
    int ack, ugh;
    
    tell_object(Victim, "You feel burning agony surging through your being!\n");
    tell_room(room, (string)Victim->query_name()+" contorts in agony!\n",
      ({ Victim }));
    ack = POISON_DAM;
    ugh = (int)Victim->query_hp();
    TotalDamage += ack;
    if (ack >= ugh)
    {
      log_info();
      Victim->hit_player(ack, "other|poison");
      destruct(this_object());
      return;
    }
    Victim->hit_player(ack,"other|poison");
  }
  
  /* Time is up for this particular poison counter */
  if (interval >= duration)
  {
    /* There's other poison counters */
    if (i)
    {
      tell_object(Victim, "The burning agony in your veins abates somewhat.\n");
    }
    else /* This is the last poison counter */
    {
      tell_object(Victim, "The burning agony in your being finally comes to an end.\n");
      tell_room(room, (string)Victim->query_name()
        + " shudders with relief.\n", ({ Victim }));
      log_info();
      destruct(this_object());
      return;
    }
  }
  else /* Add another counter at the end to replace this one */
  {
    Intervals += ({ (time()+INTERVAL) });
    Durations += ({ duration });
  }

  /* Call_out() for the next poison hit */
  call_out("poison_player", (Intervals[0] - time()));
}

status id(string arg) { return arg == POIS_ID || arg == "toxin"; }
status get() { return 0; }
int can_put_and_get() { return 0; }

status drop() {
  if ((status)environment()->is_dieing())
  {
    log_info();
    destruct(this_object());
  }
    
  return 1; 
}

string extra_look()
{
  return (string)Victim->query_name()+ " is in agony";
}

void reset(status arg)
{ 
  Intervals = ({ });
  Durations = ({ });
  TotalDamage = TotalHits = 0;
}
