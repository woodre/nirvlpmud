/* **********************************************************************
 * File:                   ~/closed/SHARDAK/obj/gob.c                   *
 * Function:               Guild Object                                 *
 * Author(s):              Earwax@Nirvana                               *
 * Copyright:              Copyright (c) 2004 Earwax                    *
 *                                 All Rights Reserved.                 *
 * Source:                 06/14/04                                     *
 * Notes:                                                               *
 * Change History:                                                      *
 * *********************************************************************/

#include "defs.h"

#pragma weak_types

/* Global Variables */
static object  Cloner;  /* Who cloned this guild object.               */
static object  Owner;   /* Environment/owner of this gob.              */
static string  Name;    /* Name of Owner                               */
static status  Guest;   /* Guests don't have guild .o files.           */

       status  Muffle;  /* 0 - not muffled, 1 muffled                  */
       string *Tasks;   /* Array of all tasks done.                    */
       mixed  *GStats;  /* Guild stats: See std/gstats.h               */
   
/* ********************************************************************** 
 * Function name: load/save_info()
 * Description:   Load or save guild stats to DATADIR+"name.o"
 * Arguments:     None
 * Returns:       Void
 * *********************************************************************/
void load_info() { restore_object(DATADIR+Name); }  
void save_info() { if (!Guest) save_object(DATADIR+Name); }
/* ********************************************************************** 
 * Function name: Various query/set functions.
 * Description:   For setting guild stats/settings.
 * Arguments:     Various
 * Returns:       Various
 * *********************************************************************/
status query_muffle() { return Muffle; }
status set_muffle(status arg) { if (Muffle == arg) return 0; Muffle = arg; return arg; }

mixed *query_gstats() { return GStats; }
mixed query_gstat(int i) { return (i < STATS_SIZE ? GStats[i] : -666); }
void set_gstat(int i, mixed v) { if (i < STATS_SIZE) GStats[i] = v; }

string *query_tasks() { return Tasks; }

status 
query_task(string arg) 
{ 
  return (arg && sizeof(Tasks) && member_array(arg, Tasks) >= 0);
}

status
remove_task(string arg)
{
  if (arg && member_array(arg, Tasks) >= 0)
    Tasks -= ({ arg });
}

void
add_task(string arg) 
{ 
  if (arg && member_array(arg, Tasks) < 0) 
    Tasks += ({ arg }); 
}
/* ********************************************************************** 
 * Function name: Simple object set-up funs
 * Description:   Simple setup functions
 * Arguments:     Various
 * Returns:       Various
 * *********************************************************************/
string short() { return ""; }
status id(string arg) { return (arg == GOB_ID || arg == "mark"); }
status get() { return 1; }
status drop() { return 1; }

void
long()
{
  if (this_player() != environment(this_object()))
  {
    if ((string)this_player()->query_guild_name() != "shardak")
      return;
    
    write(RED+(string)this_player()->query_name() + " the "+GStats[GTITLE]
      + " has been marked by "
      + ((string)environment(this_object())->query_gender() == "male"
      ? "his" : "her") + " god Shardak.\n"+NORM+NORM);
    /* HAVE SAC HAPPINESS HERE 
     * 
     *
     */
    return;
  }    
  
  write(RED+"\
You have been marked by Shardak himself.  The deformities causing your left\n\
hand to have its claw-like appearance, the texture and coloring of your skin,\n\
and the tangible aura of evil you give off are all examples of this.\n"
+NORM+NORM);
  /*
   * Sac stuff here.
   */
  write(HIK+"You may type '"+HIW+"shardak"+HIK
    +"' for information about the guild.\n"+NORM+NORM);
}
/* ********************************************************************** 
 * Function name: command_hook
 * Description:   Call commands daemon to execute a guild command
 * Arguments:     string arg - what player typed after 'command'
 * Returns:       status - 0 for failure, 1 for success
 * *********************************************************************/
status
command_hook(string arg)
{
  return (status)COMMANDSD->command_hook(query_verb(), arg, GStats, Tasks, this_object());
}
/* ********************************************************************** 
 * Function name: init
 * Description:   Called on player/mob coming into contact with gob
 * Arguments:     None
 * Returns:       Void
 * *********************************************************************/
void
init()
{
  string *t; 
  int i, member;
  
  if (Owner || !this_player() || !environment(this_object())
  || environment(this_object()) != this_player())
    return;
 
  if (!(member = (int)MEMBERSD->check_member(this_player(), Cloner)))
  {
    destruct(this_object());
    return;
  }
  
  Owner = this_player();
  Name = (string)Owner->query_real_name();
    
  if (member == 1)
  {
    Guest = 1;
    GStats[GLEVEL] = GUEST_GLEVEL;
    GStats[GRANK] = GUEST_GRANK;
    GStats[GTITLE] = "Guest";
  }
  else
  {
    load_info();
    /* 
     * Put news checking, board checking here
     */
  }

  if (!Muffle)
    CHANNELD->register(Owner);
    
  CHANNELD->entrance_message(Owner, this_object());
  i = sizeof(t = (string *)COMMANDSD->get_commands());
  
  while(i--)
    add_action("command_hook", t[i]);
}
/* ********************************************************************** 
 * Function name: reset
 * Description:   Called on object creation and resets
 * Arguments:     Status arg - 0 for creation, 1 on resets
 * Returns:       Void
 * *********************************************************************/
void
reset(status arg)
{
  if (arg) 
    return;
    
  if (this_player()) 
    Cloner = this_player();
    
  Muffle = Guest = 0; Name = ""; 
  GStats = allocate(GSTATS_SIZE); 
  Tasks = ({ });
}
