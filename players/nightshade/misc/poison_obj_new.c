/* An object used when a target player is poisoned */

inherit "/obj/treasure";
#include <ansi.h>

/******************************************************************************
 * Program: poison_obj_new.c
 * Path: /players/nightshade/misc/
 * Type: Object
 * Created: October 2014 by Karash
 *
 * Purpose: This object is used when a mob poisons the attacker, which will 
 *          cause poison damage to target for a number of rounds.
 * 
 * History:
 *          
 ******************************************************************************/
 
int count;

reset(arg)  
{
   if(arg) return;
   SetMultipleIds( ({ "poison_me" }) );
   /** Count is 3-5 rounds **/
   count = 3+random(3);
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
  
  tell_object(environment(this_object()), HIG+"You cringe in "+NORM+HIM+"PAIN"+NORM+HIG+" as the POISON flows through you!\n"+NORM);  
  this_object()->hit_player(25, "other|poison");
   
  if(count <= 0)
    {
	tell_object(environment(this_object()), "\n\The "+HIG+"POISON"+NORM+" has run its course and you return to normal.\n"); 
    destruct(this_object());
    }
}

