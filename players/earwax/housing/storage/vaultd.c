/*
 *      File:                   /players/earwax/housing/storage/vaultd.c
 *      Function:               Controls saving/restoring of players' items
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2005 Earwax/David Halek
 *                                      All Rights Reserved.
 *      Source:                 11/09/05
 *      Approved by:            Earwax (by admin consensus)
 *      Notes:                  
 *      Change History:
 */

#include <ansi.h>
#include <security.h>
#include "defs.h"

/* Global Variables */

/* 
 * Function name:  
 * Description:    
 * Arguments:      
 * Returns:        
 */

  
  
/* 
 * Function name:  check_storage_type
 * Description:    Returns what type of storage an object requires
 * Arguments:      object ob - item to attempt to store
 * Returns:        0 - Not storable
 *                 1 - Basic storage (locker-style)
 *                 2 - Comprehensive storage (hotel style)
 *
 * Notes:          This doesn't really need to be daemonized, but I'm
 *                 anticipating special cases in the future, and other
 *                 issues where this might grow to be a significant 
 *                 chunk of code, and I'd rather have this in a daemon
 *                 to begin with.
 */

int check_storage_type(object ob)
{
  int flag;
  
  flag = (int)ob->query_save_flag();
  
  switch(flag)
  {
    case 0:  return 1;  /* Storable either way */
    case 1:  return 0;  /* Not storable  */
    case 2:  return 2;  /* Hotel-style only */
    case 3:  return 1;  /* Locker-style only */
    default: return 1;  /* Everything savable by default? */
  }
}

/* 
 * Function name:  storage_info
 * Description:    Info to store in vault master file
 * Arguments:      object ob    - item to store
 *                 int type     - storage method to use
 *                 string fname - storage filename
 * Returns:        mixed * - The information to store for item
 *                 ({ Short desc,
 *                    Storage type (1 locker-style, 2 hotel),
 *                    Filename,
 *                    Info, (locker_arg$hits@misses) or .o filename
 *                    Type, (armor, weapon, item)
 *                    Subtype, (cloak, ring, sword, or none)
 *                  })
 */

varargs mixed *storage_info(object ob, int type)
{
  mixed *t;
  string ack;
  int ugh;
  
  if (!(ob) || living(ob) || !(type)) 
    return 0;

  /* Put a define for this? */
  t = allocate(6);  
  
  /* Construct short */  
  t[SHORT] = (string)ob->short();
  
  /* Basic storage flag */
  t[STYPE] = type;
  
  /* Parse and set filename of object */
  if (type == 1)
  {
    ack = "/"+file_name(ob);
    sscanf(ack, "%s#%d", ack, ugh);
    t[FNAME] = ack;
  }
  
  /* If there's special info to save, put it here */
  if (type == 2) /* Hotel style */
    t[OINFO] = path;
  else /* Locker style */
    t[OINFO] = (function_exists("locker_arg", ob) 
             ? (string)ob->locker_arg() : "");

  /* Construct Weapon info */
  if ((status)ob->query_weapon)
  {
    if (type == 1)
      t[OINFO] += "$"+(int)ob->query_hits()
               +  "@"+(int)ob->query_misses());
                 
    t[OTYPE] = "Weapon";
    t[OSTYP] = (string)ob->query_type();
  }
  /* Construct Armor Info */
  else if ((status)ob->query_armor())
  {
    string *bleh;
    
    t[OTYPE] = "Armor";
    bleh = (string *)ob->query_types();
    
    if (!(bleh) || sizeof(bleh) < 2)
      t[OSTYP] = (string)ob->query_type();
    else
      t[OSTYP] = "multislot";
  } 
  /* Basic Item */
  else
  {
    t[OTYPE] = "Item"
    t[OSTYP] = (int)ob->query_value();
  }
  
  transfer(ob, "/room/void");
  destruct(ob);
  return t;
}
         
/* 
 * Function name:  create_voucher
 * Description:    Create a voucher for reimbursement purposes
 * Arguments:      mixed *t - The info line from master file
 *                  string msg - the error message from cloning
 * Returns:        object - The voucher, which autoloads to player
 */

object create_voucher(mixed *t, string msg)
{
  object ob;
  
  ob = clone_object(VOUCHER);
  ob->set_info(t);
  ob->set_msg(msg);
  return ob;
}

/* 
 * Function name:  restore_item
 * Description:    Restore an item
 * Arguments:      mixed * - The info line from master file
 * Returns:         object - The object itself.
 *                  If the clone hoses, a voucher will be created with
 *                  the information readable to wizards, that will 
 *                  autoload on the player until removed, so a
 *                  reimbursement can be performed in full confidence.
 */
              
object restore_item(mixed *t);
{
  string msg;
  object ob;
  
  msg = catch(ob = clone_object(t[FNAME]));

  if (msg)
    return create_voucher(t, msg);
    
  if (t[STYPE] == 2)
    ob->restore_thing(t[OINFO]);
  else
    ob->locker_init((string)ob->locker_arg());
    
  return ob;
}


