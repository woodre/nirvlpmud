/* An ability to stun a player when Wulfgar throws his hammer */

inherit "/obj/treasure";
#include <ansi.h>

/******************************************************************************
 * Program: stun_obj_new.c
 * Path: /players/nightshade/misc/
 * Type: Object
 * Created: October 2014 by Karash
 *
 * Purpose: This object is used when a mob stuns the attacker, which prevents
 *          any actions or weapon attacks by the attacker while in possession of
 *          this object for 2-4 rounds.
 * 
 * History:
 *          
 ******************************************************************************/
 
int count;

reset(arg)  
{
   if(arg) return;
   SetMultipleIds( ({ "stun_me", "no_weapon_attack" }) );
   count = 2+random(3);
   set_weight(0);
   set_heart_beat(1);
}


long(){ return 0; }

short() { return 0; }


init() 
{
#ifndef __LDMUD__
  add_action("stunned"); add_xverb("");
#else
  add_action("stunned", "", 3);
#endif
}


init_arg(str)  {  sscanf(str, "%d", count);  }

stunned()  
{
   if(count > 0){
      write(CYAN+"You are STUNNED!\n"+NORM);

      return 1;  }
   else  {
      destruct(this_object());
      return 1;
      /* This cannot happen or heartbeat error if command is called from heartbeat - like wimpy
         return 0;
      */
   }
}

drop()  { return 1; }
get()   { return 1; }


heart_beat() 
{
   count--;
   tell_object(environment(this_object()), GRY+"You are STUNNED and trying to catch your breath.\n"+NORM);
   if(count <= 0)
      {
	  tell_object(environment(this_object()), CYAN+"\n\Your catch your breath and return to action.\n\n"+NORM);
      destruct(this_object());
      }
}

