/* ***************************************************************************
 * File:           /players/earwax/housing/land.c    
 * Function:       It's what defines a room as being 'land' and developable.
 * Author:         Earwax
 * Copyright:      Copyright (c) 2004 Earwax.  All rights reserved.
 * Source:         5/22/04
 * Notes:          Using Vital's header style for consistency :)
 * Change History:
 * **************************************************************************/

#include "defs.h"

inherit "/room/room.c";

/* Global Variables */

status Flag_Registered; /* Flag for bug-proofing.  Successful LANDD use.    */
int    Lot_Size;        /* Maximum number of rooms for a house on it.       */
int    HouseSize;       /* Current number of rooms in housing structure.    */
string Realm_Name;      /* Area name                                        */
int    Cost;            /* Initial cost of the land.                        */
string Owner;           /* Name of player that owns the land.               */
string House_Filename;  /* Path and Filename for housing object.            */
int    Light;           /* So I can set the light level back.               */
/* ***************************************************************************
 * Function Name: reset
 * Description:   Called when land is created or upon resets.
 * Arguements:    status arg: 0 if it's creation, 1 if it's a reset
 * Returns:       void
 * **************************************************************************/

void
reset(status arg)
{
  ::reset(arg);

  if (!arg) 
  {
    Light = set_light(0);
    if (!Light)
      set_light(1-Light);
  }
  if (!find_object(LANDD))
    LANDD->reset(0);

  if ("/"+file_name(this_object())+".c" == LAND)
    return;

  if (!arg)
    LANDD->register(this_object());

  if (!Flag_Registered && "/"+file_name(this_object())+".c" != LAND)
  {
    write_file(REGISTER, ctime() + ": "+file_name(this_object())+" Did not register.\n");
    return;
  }

  if (!present(HOUSING_OBJECT_ID, this_object()))
  {
    object ob;

    ob = clone_object(HOUSE_OB);

    if (ob)
      ob->load_info(House_Filename);

    if (ob)
      move_object(ob, this_object());
    else
      write_file(BUG, "DID NOT LOAD HOUSE: "+House_Filename+"\n");
  }
  if (!Light)
    set_light(-1 + Light);
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
