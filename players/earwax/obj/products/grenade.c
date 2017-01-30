/*
 *      File:                   ~earwax/obj/products/grenade.c
 *      Function:               Obscures room short, long
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2007 David Halek
 *                                      All Rights Reserved.
 *      Source:                 07/13/2007
 *      Notes:                  Can be purchased in my dispenser.
 *      Change History:
 */

#include <ansi.h>
#include <security.h>
#include "../defs.h"

inherit "/obj/treasure.c";

/* 
 * Dispenser setup
 */
 
string query_cost() { return "1000"; }
string query_desc() { return "Green Smoke Grenade"; }
string query_my_name() { return "grenade"; }

/*
 *
 */
 
void reset(status arg) 
{
  
  if (arg)
    return;
    
  return;
}

int id(string arg)
{
  return (arg == "green smoke grenade" || arg == "smoke grenade" || arg == "grenade");
}

varargs void long(string arg)
{
  if (arg && !id(arg)) return 0;
  
  write("\
This is an Earwaxian Green Smoke Grenade.  Its purpose is to obfuscate the\n\
location of people in its area of effect.  The smoke is non-toxic, and merely\n\
disguises the location of an individual or group.  Use 'lob grenade' to\n\
activate it.  Not liable for injuries due to smoke inhalation.\n");
}

string short()
{
  return GRN+"Green"+HIK+" Smoke "+NORM+"Grenade";
}

int query_weight() { return 1; }
int query_value()  { return 1000; }

int lob_grenade(string arg)
{    
  object smoke;
 
  if (!arg || !id(arg))
  {
    notify_fail("Lob what?\n");
    return 0;
  }
   
  write("You pull the pin in the grenade and drop it on the ground.\n");
  say((string)this_player()->query_name()
    +" pulls the pin on a green smoke grenade and tosses it on the ground!\n");
        
  smoke = clone_object(SUPPORT+"smoke");
  smoke->start_smoke(environment(this_player()));
  move_object(this_object(), "/room/void");
  destruct(this_object());
  return 1;
}

void init()
{
  add_action("lob_grenade", "lob");
}

/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */
