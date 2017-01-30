/*
 *      File:                   /obj/objtracker.c
 *      Function:               Inherit for tracking passing of items between chars
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2006 Earwax (David Halek)
 *                                      All Rights Reserved.
 *      Source:                 07/04/2006
 *      Notes:                  
 *      Change History:
 */

#define OBJECT_VIOLATIONS_LOG "OBJECT_VIOLATIONS"

/* Global Variables */
static mapping  AllHostName; /* AllHostName[name] == ({ name1, name2, etc }) */

/* 
 * Function name: objtracker_init_check()
 * Description:   Called by init() in items to track item passing between chars
 */
                                                   
void objtracker_init_check()
{
  string hname, pname;
  int siz;
  
  /* Master object checks */
  if (!environment() || !environment(this_object()))
  {
    return;
  }
  
  /* Make sure the player is the environment and not a mob */
  if ( environment(this_object()) != this_player()
  || (status)this_player()->is_npc() )
  {
    return;
  }
  
  hname = (string)this_player()->query_hostname();
  pname = (string)this_player()->query_real_name();
  
  /* First char to pick up this item */
  if (!AllHostName)
  {
    AllHostName = ([ hname: ({ pname }) ]);
    return;
  }
  
  /* New player carrying this item, so add their host name */
  if ( !member(AllHostName, hname) )
  { 
    AllHostName += ([ hname: ({ pname }) ]);
    return;
  }
  
  siz = sizeof(AllHostName[hname]);
  
  /* Same char from this ip carrying this item */
  if ( siz == 1 && AllHostName[hname][0] == pname )
  {
    return;
  }
  
  /* Alternate character, from same ip, already logged */
  if ( member_array(pname, AllHostName[hname]) > -1 )
  {
    return;
  }
  
  /* Alternate character same IP, message them and log it */
  AllHostName[hname] += ({ pname });
  tell_object(this_player(), "Logging receipt of item from alternate character: "+AllHostName[hname][0]+".\n");
  log_file(OBJECT_VIOLATIONS_LOG, ctime()+": "+AllHostName[hname][0]+": "+file_name(this_object())+" now carried by "+pname+" ("+hname+").\n");
  
  /* It's a bag, log the value as well */
  if ( (int)this_object()->can_put_and_get() )
  {
    object *items;
    int i, totalval;
    
    siz = sizeof(items = all_inventory(this_object()));
    for (i = 0; i < siz; i++)
    {
      totalval += (int)items[i]->query_value();
    }
    
    log_file(OBJECT_VIOLATIONS_LOG, "Bag contained "+siz+" items with a value of "+totalval+".\n");
  }
}