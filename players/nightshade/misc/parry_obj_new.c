/* A spell to prevent weapon attack for 1 round when parried */

inherit "/obj/treasure";
#include <ansi.h>

/******************************************************************************
 * Program: parry_obj_new.c
 * Path: /players/nightshade/misc/
 * Type: Object
 * Created: October 2014 by Karash
 *
 * Purpose: This object is used when a mob parries the attacker, which prevents
 *          weapon attacks by the attacker while in possession of this object.
 * 
 * History:
 *          
 ******************************************************************************/
 
int count;

reset(arg)  
{
   if(arg) return;
   SetMultipleIds( ({ "parry_me", "no_weapon_attack" }) );
   count = 1;
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
   /* tell_object(environment(this_object()), GRY+"You have been PARRIED!\n"+NORM); */
   if(count <= 0)
      {
	  /* tell_object(environment(this_object()), ""); */
      destruct(this_object());
      }
}

