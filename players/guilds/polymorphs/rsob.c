#include "definitions.h"

object room;
object owner;
object attacker;
string my_id;
int callouts;         /* The number of times we call the event */
int callout_freq;     /* The amount of heartbeats between each call */
int callout_current;  /* the number that we are on... */

id(str) { return str == RSPELL_ID || my_id == str; }
short() { return 0; }
get() { return 0; }

reset(arg)
{
   if(arg) return 0;
   
   callout_current = 0;
   
   remove_call_out("slow_reset");
   call_out("slow_reset", 1);
}

slow_reset()
{
   if(environment(this_object()) && !room) room = environment(this_object());
   if(!room) destruct(this_object());
   
   if(!callouts || !callout_freq) destruct(this_object());
   remove_call_out("do_event");
   call_out("do_event", callout_freq);
}

/* This is called on each event cycle */
do_event()
{
   object proom;
   object aroom;
   
   callout_current ++;
   
   /* Check if the player is still here */
   if(!owner) return do_event_finish();
   proom = environment(owner);
   if(!proom || proom != room) return do_event_finish();

   /* now check if the monster is still here */
   if(!attacker) return do_event_finish();

   aroom = environment(attacker);
   if(!aroom || aroom != room) return do_event_finish();
   
   if(callout_current >= callouts)  return do_event_finish();
   else
   {
      remove_call_out("do_event");
      call_out("do_event", callout_freq);
   }
}

/* This is called on the end of the cycle */
do_event_finish()
{
   destruct(this_object());
}

set_id(arg) { my_id = arg; }
set_owner(arg) { owner = arg; }
set_room(arg) { room = arg; }
set_attacker(arg) { attacker = arg; }
set_callouts(arg) { callouts = arg; }
set_callout_freq(arg) { callout_freq = arg; }

