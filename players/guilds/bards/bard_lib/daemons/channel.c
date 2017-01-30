/*
 * New channel daemon
 * Based on the one used in guild
 * Balowski@Nirvana '97
 */
#pragma strict_types
#include "/players/guilds/bards/bard_lib/lib.h"
inherit BASE;
inherit COLOUR;

mapping Channels;
mapping Members;

void
create()
{
    colour::create();
    base::create();
    Members = ([ ]);
    Channels = ([ ]);
}

/* ---------------------------------------------------------------
 * Make a new channel
 * ---------------------------------------------------------------*/
void
add_channel(string name, string prefix, mixed allow)
{
    string str;
    
    str = terminal_colour(prefix, "unknown");
    str = pad("", strlen(str));
    
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

    bwmsg = terminal_colour(msg, "unknown") + "\n";
    cmsg = terminal_colour(msg, "ansi") + "\n";

    i = sizeof(men);
    while (i--) {
	if (men[i]) {
	    tell_object(men[i], query_attribute("ansi", men[i]) ? cmsg : bwmsg);
	}
    }
}
