/*
 * New channel daemon
 * Based on the one used in guild
 * Balowski@Nirvana '97
 */
#pragma strict_types

inherit "/players/balowski/std/base";
inherit "/players/balowski/std/colour";
#include "/players/balowski/lib.h"
#include "/players/feldegast/std/add_array.h"

mapping Channels;
mapping Members;
mapping History; /* -Feld */

void
create()
{
    colour::create();
    base::create();
    Members = ([ ]);
    Channels = ([ ]);
    History=([ ]);
}

/* ---------------------------------------------------------------
 * Make a new channel
 * ---------------------------------------------------------------*/
void
add_channel(string name, string prefix, int allow)
{
    string str;    
    str = pad("", allow);
    
    Channels[name] = ({ prefix, str, allow });
}

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
/* This is Feldegast's teensy weensy contribution to this file. */
void add_history(string chan,string msg) {
  if(!(History[chan]))
    History[chan]=({ msg });
  else
  if(sizeof(History[chan]) < 10)
    History[chan]+=({ msg });
  else {
    History[chan]=add_array(msg,History[chan][1..sizeof(History[chan])]);
  }
}
string *query_history(string chan) {
  return History[chan];
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
		Members[chan[i]] = marks - ({ mark });
	    }
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
broadcast(string chan, string msg)
{
    int i;
    string cmsg, bwmsg;         /* in colour or b/w */
    object *men;
    mixed  *cdata;
    string prefix, seperator;

    if (!(men = Members[chan])) return;
    if (cdata = Channels[chan]) {
	prefix = cdata[0];
	seperator = cdata[1];
	
	msg = prefix +
	  implode(explode(format(msg, 70 - strlen(seperator)), "\n"),
		  "\n" + seperator);
    }

    i = sizeof(men);

/* More of Feldegast's hackwork */
    msg+="\n";
    add_history(chan,msg);

    while (i--) {
	if (men[i]) {
	    tell_object(men[i], msg);
	}
    }
}

  
