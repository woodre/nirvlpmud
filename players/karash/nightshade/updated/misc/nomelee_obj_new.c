/* An object to prevent weapon attacks - used when mob flies out of melee range */

inherit "/obj/treasure";
#include <ansi.h>

/******************************************************************************
 * Program: nomelee_obj_new.c
 * Path: /players/nightshade/misc/
 * Type: Object
 * Created: October 2014 by Karash
 *
 * Purpose: This object is used when a mob is still in room, but moves out of melee
 *          range, so this object will prevent weapon attacks (at least that's the plan)
 * 
 * History:
 *          
 ******************************************************************************/
 
int count;

reset(arg)  
{
   if(arg) return;
   SetMultipleIds( ({ "no_melee", "no_weapon_attack" }) );
   count = 15;
   set_weight(0);
   set_heart_beat(1);
}


long(){ return 0; }

short() { return 0; }


drop()  { return 1; }
get()   { return 1; }


heart_beat() 
{
   count--;
   tell_object(environment(this_object()), CYAN+"Your target is not in range of your weapon attack.\n"+NORM);
   if(count <= 0)
      {
	  destruct(this_object());
      }
}

