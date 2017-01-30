/*
 *      File:                   /players/earwax/closed/azorn/lib/room.c
 *      Function:               Inherit for Azorn quest area rooms
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2005 Earwax/David Halek
 *                                      All Rights Reserved.
 *      Source:                 10/21/2005
 *      Notes:                  
 *      Change History:
 */

#include "../defs.h"
inherit "/room/room.c";

/* Global Variables */
string KeyID;        /* Key ID if there's a door        */
string DDest;        /* Where the door leads to         */
string DDir;         /* Direction of the door           */
status Open;         /* Is the door open                */
status Locked;       /* Is it locked                    */
status StartsOpen;   /* Creation and reset open state   */
status StartsLocked; /* Creation and reset locked state */
status DoorFlag;     /* Is there a door here            */

/* Lazy way of doing notify_fail() */
status lazy(string t) { notify_fail(t); return 0; }

/* Automatically color the short description since I'm lazy */
void set_short(string arg) { short_desc = HIK+arg+" "+NORM; }

/* Add door information to the long description if necessary. */
void long(string arg)
{
	string p;
 
  if (KeyID) /* There's a door here. */
  {
    p = long_desc;
    long_desc += ("There is a"+(Open ? "n open" : " closed")
      + " door to the "+DDir+".\n");
    ::long(arg);
    long_desc = p;
    return;
  }
  ::long(arg);
}

/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */
status do_open(string arg)
{
	/* It would be nifty to do opening and closing with same fun, but why bother. */
	if (arg != "door") /* Must be opening something else. */
	  return lazy("You don't see anything like that that you can open here.\n");
	if (Open) /* It's already open. */
		return lazy("The door is already open.\n");
	if (Locked) /* Can't open a locked door. */
		return lazy("The door must be unlocked first.\n");

  Open = 1;
  add_exit(DDest, DDir);
  write("You open the door.\n");
  say((string)this_player()->query_name()+" opens the door.\n", this_player());
  DDest->set_open(1);
  return 1;
}
  	
status do_close(string arg)
{
	/* It would be nifty to do opening and closing with same fun, but why bother. */
	if (arg != "door") /* Must be closing something else. */
	  return lazy("You don't see anything like that that you can close here.\n");
	if (!Open) /* It's already closed. */
		return lazy("The door is already closed.\n");

  Open = 0;
  remove_exit(DDir);
  write("You close the door.\n");
  say((string)this_player()->query_name()+" closes the door.\n", this_player());
  DDest->set_open(0);
  return 1;
}

status do_unlock(string arg)
{
	object key;
	
	if (arg != "door")
	  return lazy("What is it you want to unlock?\n");
	if (!Locked)
	  return lazy("The door is already unlocked.\n");
	if (!KeyID)
	  return lazy("This door doesn't have a keyhole.\n");
	if (!(key = present(KeyID, this_player())))
	  return lazy("You don't have the proper key for this door.\n");
	  
	Locked = 0;
	DDest->set_locked(0);
	write("You unlock the door with your "+(string)key->short()+".\n");
	say((string)this_player()->query_name()+" unlocks the door.\n", this_player());
	return 1;
}

status do_lock(string arg)
{
	object key;
	
	if (arg != "door")
	  return lazy("What is it you want to lock?\n");
	if (Locked)
	  return lazy("The door is already locked.\n");
	if (!KeyID)
	  return lazy("This door doesn't have a keyhole.\n");
	if (!(key = present(KeyID, this_player())))
	  return lazy("You don't have the proper key for this door.\n");
	  
	Locked = 1;
	DDest->set_locked(1);
	write("You lock the door with your "+(string)key->short()+".\n");
	say((string)this_player()->query_name()+" locks the door.\n", this_player());
	return 1;
}
	
/* 
 * Function name:  Setup funs
 * Description:    Basic room setup stuff
 * Arguments:      Various
 * Returns:        Various
 */
 
status move(string arg)
{
	string verb;
	
  if (Open) 
    return ::move(arg);
    
  verb = query_verb();
  
  if (verb != DDir && convert_dir(verb) != DDir)
    return ::move(arg);
    
  return lazy("Even "+BOLD+"you"+NORM+" can't walk through a closed door.\n");
}

void reset(status arg)
{
	if (arg)
	{
		if (DoorFlag)
		{
			object room;
			
			room = find_object(DDest);
  		if (present(PLAYERID) || (room && present(PLAYERID, room)))
		  	return; /* Don't reset the door if there are players present. */
		  
	  	Locked = StartsLocked;
	  	if (Open != StartsOpen)
	  	{
   		  Open = StartsOpen;
  		  if (!Open) remove_exit(DDir);
  		  else add_exit(DDest, DDir);
		  }
		  if (room) /* Ensure other room resets */
		  {
			  room->set_open(Open);
			  room->set_locked(Locked); 
		  }
	  }
	  return;
  }
	
	add_property("fight_area"); /* PK Area */
	
	Locked = StartsLocked;
	Open = StartsOpen;
  return;
}

string realm() { return "NT"; } /* No-teleport area */

status okay_follow() {
	/* They can follow if they are an npc or over 18 */
	if (this_player() && !((status)this_player()->is_npc())
	&& (int)this_player()->query_level() < 19)
	{
		write("You are too inexperienced to follow into that area.\n");
		return 0;
	}
	return 1;
}

status do_search(string arg) { return 0; } /* Meant to be overridden */

void init() {
	string shortdir;
	
	::init();
	add_action("on_search", "search");
	
	if (!DoorFlag) /* Nothing special to do if no door */
	  return; 

	/* Door actions */  
	add_action("do_open", "open");
	add_action("do_close", "close");
  add_action("do_unlock", "unlock");
  add_action("do_lock", "lock");
  
  if (!Open)
  {
	  string t;
	  
    add_action("move", DDir);
    t = translate_exit(DDir);
    if (t != DDir)
      add_action("move", t);
  }
}
	  
/* 
 * Function name:  Door functions
 * Description:    Miscellaneous door support funs
 * Arguments:      Various
 * Returns:        Various
 */
void set_open(status arg) 
{ 
	tell_room(this_object(), "The door "+(arg ? "opens" : "closes")+".\n"); 
	
	if (Open == arg) return;
	
	Open = arg; 
	if (Open) add_exit(DDest, DDir);
	else remove_exit(DDir);
}
	
void set_locked(status arg) 
{ 
	tell_room(this_object(), "The door suddenly clicks.\n"); 
	Locked = arg; 
}

void set_key_id(string arg) { KeyID = arg; }

void 
add_door(string path, string dir, string key, status open, status locked)
{
	DDir = dir;
	KeyID = key;
	DDest = path;
	Open = StartsOpen = open;
	Locked = StartsLocked = locked;
	DoorFlag = 1;
	if (Open)
  	add_exit(path, dir);
}

status 
search_results(string what)
{
	write("You don't find anything worthy of notice.\n");
}