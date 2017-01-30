/* ***************************************************************************
 * File:           /players/earwax/housing/land.c    
 * Function:       It's what defines a room as being 'land' and developable.
 * Author:         Earwax
 * Copyright:      Copyright (c) 2004 Earwax.  All rights reserved.
 * Source:         5/22/04
 * Notes:          Using Vital's header style for consistency :)
 * Change History:
 16 May 2005 (by Illarion)
   moved the setup of the room into the init() function so that the setup calls
   don't have to go before the ::reset() call in reset().  Disabled the set_light
   code as it doesn't appear to do anything.
 23 Sep 2005 (Earwax)
   Recoded room to remove inheritance of /room/room.c, removed the
   set_light code because it was there for unrelated reasons.
 12 Oct 2005 (Earwax)
   Recoded parts of this, stabilized it.  Data integrity was the big issue.
 * **************************************************************************/

#include "defs.h"

/* Global Variables */

status Flag_Registered; /* Flag for bug-proofing.  Successful LANDD use.    */
int    Lot_Size;        /* Maximum number of rooms for a house on it.       */
int    HouseSize;       /* Current number of rooms in housing structure.    */
string Realm_Name;      /* Area name                                        */
int    Cost;            /* Initial cost of the land.                        */
status replaceArg;      /* replaces functionality of arg in reset - illarion */
string Owner;           /* Name of player that owns the land.               */
string House_Filename;  /* Path and Filename for housing object.            */
int    Light;           /* So I can set the light level back.               */

void twax (string arg) {
	object ob;
	ob = find_player("earwax");
	if (ob)
	  tell_object(ob, HIG+arg+NORM+"\n");
}
/* ***************************************************************************
 * Function Name: setup_land
 * Description:   Called to register the land
 * Arguements:    none
 * Returns:       void
 * **************************************************************************/

void setup_land()
{
	string fname;
	
	fname = "/"+file_name(this_object())+".c";
	
  if (!find_object(LANDD))
    LANDD->reset(0);

  if (fname == LAND)
  {
    LANDD->log_this(BUG, "Boggle, this_object() == LAND: "+House_Filename+"/n");
    return;
  }

  LANDD->register(this_object());

  if (!Flag_Registered)
  {
    LANDD->log_this(REGISTER, ctime() + ": "+fname+" Did not register.\n");
    return;
  }

  if (!present(HOUSING_OBJECT_ID, this_object()))
  {
    object ob;
    if (!find_object(HOUSE_OB))
      HOUSE_OB->load_me();
    ob = clone_object(HOUSE_OB);

    if (ob)
    {
	    string t;
	    /*( t = House_Filename[1..(strlen(House_Filename)-1)]; */
	    t = House_Filename;
      ob->load_info(t);
    }

    if (ob)
      move_object(ob, this_object());
    else
      LANDD->log_this(BUG, "DID NOT LOAD HOUSE: "+House_Filename+"\n");
  }
}  
/* ***************************************************************************
 * Function Name: Various query/set functions.
 * Description:   Used by land daemon, housing system.
 * Arguements:    Various
 * Returns:       Various
 * **************************************************************************/

void set_registered(status arg) { Flag_Registered = arg; }
void set_lot_size(int arg) { Lot_Size = arg; }
void set_realm_name(string arg) { Realm_Name = arg; }
void set_cost(int arg) { Cost = arg; }
void set_owner(string arg) { Owner = arg; }
void set_house_filename(string arg) { House_Filename = arg; }

status query_registered() { return Flag_Registered; }
int query_lot_size() { return Lot_Size; }
string query_realm_name() { return Realm_Name; }
int query_cost() { return Cost; }
string query_owner() { return Owner; }
string query_house_filename() { return House_Filename; }

status query_is_land() { return 1; }
object get_house_object() { return present(HOUSING_OBJECT_ID, this_object()); }
