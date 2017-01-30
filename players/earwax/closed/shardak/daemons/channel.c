/*
* Shardak guild - (tm) Dragnar/John
* Channel daemon is (c) Balowski/Rasmus, April 30th 1995.
* Change log:
* Sept 17th:   Now maintaining a list of guild objects
*              This is more like a guild member daemon now
*/
#pragma strict_types
#include "/players/balowski/lib.h"
#include "/players/balowski/daemons.h"
#include "../include/ansi.h"

mapping Channels;
mapping Members;

/* ---------------------------------------------------------------
* Set things up
* ---------------------------------------------------------------*/
void
reset(status arg)
{
   if(arg) return;
   Members = ([ ]);
    Channels = ([ "[Servants]" : RED + "[Servants]" + NORM + " ",
                  "{Servants}" : RED + "{Servants}" + NORM + " " ]);
}

/* ---------------------------------------------------------------
* Make a new channel
* ---------------------------------------------------------------*/
/*
void
add_channel(string name, string prefix, mixed allow)
{
   Channels[name] = prefix;
}
*/

/* ---------------------------------------------------------------
* Add an item (player/whatever) to a channel
* ---------------------------------------------------------------*/
void
register(object mark, mixed chan)
{
   object  *marks;
   int     i;
   
   if (pointerp(chan)) {
      i = sizeof(chan);
      while (i--) register(mark, chan[i]);
      return;
   }
   
   if (!(marks = Members[chan])) {
      Members[chan] = ({ mark });
   }
   else {
      /* avoid duplicates and use empty slots */
      if (member_array(mark, marks) < 0) {
         if ((i = member_array(0, marks)) < 0)
            Members[chan] = marks + ({ mark });
         else
            marks[i] = mark;
      }
   }
}

/* ---------------------------------------------------------------
* Remove an object from one or more channels
* ---------------------------------------------------------------*/
void
deregister(object mark, mixed chan)
{
   object  *marks;
   int i;
   
   /*
   * To shrink the array or not, that is the question
   * I choose to shrink it, but setting entry to zero could suffice
   */
   if (pointerp(chan)) {
      i = sizeof(chan);
      while (i--) {
         if (marks = Members[chan[i]]) {
            Members[chan[i]] = marks - ({ mark }); }
       }
      return;
   }
   if (marks = Members[chan])
      Members[chan] = marks - ({ mark });
}

/* ---------------------------------------------------------------
* Export the members of a given channel
* ---------------------------------------------------------------*/
object *
users(string chan)
{
   /*
   * Can contain blanks. Could be avoided by using destructor(),
   * but that is specific to the DR driver (I can't use it at home)
      */
   return Members[chan];
}

/* ---------------------------------------------------------------
* Description:
*    Send a message to all the listeners (people with marks)
* Parameters:
*    msg      : text to be sent. ex: "Smurf goes hop hop hop.\n"
*    priority : not used yet. (for gc channel and overriding muffle)
* ---------------------------------------------------------------*/
void
broadcast(string msg, int priority, string chan)
{
   int i;
   object *men;
   string prefix;
   
   if (!(men = Members[chan])) return;
   
   
   msg = RED + chan + NORM + " " + msg;
   i = sizeof(men);
   while (i--)
   if(men[i]) {
   if ((string)men[i]->query_real_name() == "reflex")
      tell_object(men[i], msg);
  else tell_object(men[i], msg + "\n");
  }
  "/obj/user/chistory"->add_history(chan, "(" + ctime()[11..15] + ") " + msg);
}

status
feeling(string arg, string chan, string prefix)
{
   string verb, args;
   object *men;
   int i;
   
   if (!(men = Members[chan]))
      return 0;
   if (sscanf(arg, "%s %s", verb, args) <= 1)
      verb = arg;
   i = (int) call_other("players/earwax/closed/shardak/daemons/atmos",
      "do_cmd", verb, args,
      prefix, Members[chan]);
   if (!i) notify_fail("Unknown feeling.\n");
   return i;
}

varargs void
message(string prefix, string msg, mixed rec, mixed excl)
{
   if (prefix) msg = prefix + " " + msg;
   if (objectp(rec)) {
      tell_object(rec, msg);
   }
   else if (pointerp(rec)) {
      int i; string bwmsg;
      
      if (excl) rec -= excl;
      i = sizeof(rec);
      if (!i) return;
      else if (i == 1) return message(0, msg, rec[0]);
      
      while (i--)
      if (rec[i])
         tell_object(rec[i], msg);
   }
}

