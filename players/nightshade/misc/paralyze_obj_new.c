/* A spell to paralyze a player turned to stone */

inherit "/obj/treasure";
#include <ansi.h>

/******************************************************************************
 * Program: paralyze_obj_new.c
 * Path: /players/nightshade/misc/
 * Type: Object
 * Created: September 2014 by Karash
 *
 * Purpose: This object is used when a mob paralyzes the attacker, which prevents
 *          any actions or weapon attacks by the attacker while in possession of this object.
 * 
 * History:
 *          
 ******************************************************************************/
 
int count;

reset(arg)  
{
   if(arg) return;
   SetMultipleIds( ({ "freeze_me", "no_weapon_attack" }) );
   count = 1+random(3);
   set_weight(0);
   set_heart_beat(1);
}


long(){ return 0; }

short() { return 0; }


init() 
{
#ifndef __LDMUD__
  add_action("iced"); add_xverb("");
#else
  add_action("iced", "", 3);
#endif
}


init_arg(str)  {  sscanf(str, "%d", count);  }

iced()  
{
   if(count > 0){
      write(HIC+"You are petrified in "+NORM+GRY+"stone"+NORM+HIC+"!\n"+NORM);

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
   tell_object(environment(this_object()), GRY+"You are made of stone.\n"+NORM);
   if(count <= 0)
      {
	  tell_object(environment(this_object()), CYAN+"\n\Your "+NORM+YEL+"flesh"+NORM+CYAN+" returns to "+NORM+YEL+"normal.\n\n"+NORM);
      destruct(this_object());
      }
}

