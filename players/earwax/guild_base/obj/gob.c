/*
 *      File:                   /path/filename.c
 *                              Based off the generic guild object:
 *                                /players/earwax/guild_base/obj/gob.c
 *
 *      Function:               Guild object
 *                              Based off the generic guild object
 *                                code for use by developers to quickly
 *                                setup a core for their guilds.
 *
 *      Author(s):              YourName@Nirvana
 *                              Generic guild code by Earwax@Nirvana
 *
 *      Copyright:              Copyright (c) 2005 YourName
 *                                      All Rights Reserved
 *                              Generic guild code
 *                              Copyright (c) 2005 Earwax
 *                                      All Rights Reserved.
 *
 *      Source:                 Date
 *                              Generic guild code: 10/05/05
 *
 *      Notes:
 *                  
 *      Change History:
 *
 * *********************************************************************
*/

/* Color defs, Dev-Level defs, and defs pertinant to guild */
#include <ansi.h>
#include <security.h>
#include "../defs.h"

/* Global Variables */

/* Static variables don't save */
static object  Cloner;  /* Who cloned this guild object.               */
static object  Owner;   /* Environment/owner of this gob.              */
static string  Name;    /* Name of Owner                               */
static status  Guest;   /* Guests don't have guild .o files.           */

       status  Muffle;  /* 0 - not muffled, 1 muffled                  */
       int     GLevel;  /* Guild Level */
       int     GRank;   /* Guild Rank */
       string  GTitle;  /* Guild Title */

/* 
 * Function name:  load_info(), safe_info()
 * Description:    load or save guild data
 * Arguments:      None
 * Returns:        Void
 */
 
void load_info() { restore_object(DATA+Name); }  
void save_info() { if (!Guest) save_object(DATA+Name); }

/* 
 * Function name:  Various query/set funs
 * Description:    These are called from outside the guild object
 * Arguments:      Various
 * Returns:        Various
 */

status query_muffle() { return Muffle; }
status set_muffle(status arg) { if (Muffle == arg) return 0; Muffle = arg; return arg; }

/* 
 * Function name:  Object setup funs
 * Description:    These setup the object's basic necessities
 * Arguments:      Various
 * Returns:        Various
 */

string short() { return "Generic Guild Object"; }

status 
id(string arg) 
{ 
	return (arg == GOB_ID 
	     || arg == "object"
	     || arg == "generic guild object"
	     || arg == "guild object"
	     || arg == "guild_object"
	     /*
	      * You can use various other ID's here, to perform equally various tasks.
	      * For example, you can use an id of "dark_sight_object" to allow the
	      * player to see in the dark.
	     */
	     || arg == "generic_guild_object"); 
}

/* Can't pick this up, can't drop it. */
status get() { return 1; }  
status drop() { return 1; }

void
long()
{
	/*If the person looking at this (ie, via the display command) is not the owner
	 * and not in our guild, show this information. */
  if (this_player() != environment(this_object())
    && (string)this_player()->query_guild_name() != GUILD_NAME)
    {
	    write("This would be the public guild object description.\n");
      return;
    }
   
  /* Show their guild level, or whatever information you wish */      
  write("Generic guild object's description as the guildmember would see it,\n");
  write("use 'guild_help_command' for information.\n");
  return;
}

 /* 
 * Function name:  command_hook
 * Description:    execute commands
 * Arguments:      arg - argument passed by the player
 * Returns:        0 for failure, 1 for success
 */
 
status
command_hook(string arg)
{
	return (BIN+query_verb()->main(arg, this_object()));
} 

/* 
 * Function name:  load_commands
 * Description:    Load the commands that player can use
 * Arguments:      None
 * Returns:        Void
 */

void
load_commands()
{
  int i;
  string *t;
	
  i = sizeof(t = (string *)COMMANDSD->get_commands(GLevel));
  
  while(i--)
    add_action("command_hook", t[i]);
}

/* 
 * Function name:  init
 * Description:    Called when gob comes into contact with player
 * Arguments:      None
 * Returns:        Void
 */
 
 void
init()
{
  string *t; 
  int i, member;
  
  /* If it's not the owner of this object, don't do anything */
  if (Owner || !this_player() || !environment(this_object())
  || environment(this_object()) != this_player())
    return;
 
  /*
   * Cloner will usually be the player logging on, but sometimes will
   * be a wizard cloning it.  Find out if they are a guild member 
   * either way.
   * If the cloner isn't a guild wiz, log it
   */
  if (!(member = (int)MEMBERSD->check_member(this_player(), Cloner)))
  {
    log_file(LOG+"clone", ctime()+": Gob cloned by: "
      + capitalize((string)Cloner->query_real_name())+"\n");
    return;
  }
  
  Owner = this_player();
  Name = (string)Owner->query_real_name();

  /* The cloner is not a a member of the guild. */    
  if (member == 1)
  {
    Guest = 1;
    GLevel = GUEST_GLEVEL;
    GRank  = GUEST_GRANK;
    GTitle = "Guest";
  }
  else
  {
    load_info();
    /* 
     * Put news checking, board checking here, whatever
     */
  }

  /* If they don't have the channel muffled, add them */
  if (!Muffle)
    CHANNELD->register(Owner);

  /* Have the channel daemon announce their entrance. */    
  CHANNELD->entrance_message(Owner, this_object());
  /* Load up the commands they can use. */
  load_commands();
}

/* 
 * Function name:  reset
 * Description:    Called when object is created or reset
 * Arguments:      0 on creation, 1 on reset
 * Returns:        void
 */
 
void
reset(status arg)
{
  if (arg) 
    return;
    
  if (this_player()) 
    Cloner = this_player();
    
  Muffle = Guest = GLevel = GRank = 0;
  Name = ""; 
}


/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */
/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */
