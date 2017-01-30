#include <ansi.h>
#pragma strict_types

#define MAP "players/dragnar/daemons/mapping"

mapping Channels;

/*****************************************************************
* Create a new channel
******************************************************************/
void
add_channel(string name)
{
  if(!Channels) Channels = ([ ]);
  if(!Channels[name]) Channels[name] = ({ });
}

/*****************************************************************
* Add an item (player/whatever) to a channel
*****************************************************************/
void
register(object who, string chan)
{
  object* list;

  if(!Channels) add_channel(chan);
  if(!Channels[chan]) add_channel(chan);
  list = Channels[chan];
  if (member_array(who, list) < 0)
    Channels[chan] += ({ who });
}


/*****************************************************************
* Remove an object from one or more channels
*****************************************************************/
void
deregister(object who, string chan)
{
  int i;
  object  *list;

  if(!Channels) return;
  list = Channels[chan];
  ;
  if((i = member_array(who, list)) >= 0)
    Channels[chan] -= ({ who });
}

/*****************************************************************
* Export the members of a given channel
*****************************************************************/
object *
users(string chan)
{
    return Channels[chan];
}

/*****************************************************************
* Description:
*    Send a message to all the listeners (people with marks)
* Parameters:
*    msg      : text to be sent. ex: "Smurf goes hop hop hop.\n"
*    priority : not used yet. (for gc channel and overriding muffle)
*****************************************************************/
void
broadcast(string msg, int priority, string chan)
{
    int i;
    string cmsg, bwmsg;         /* in colour or b/w */
    object *men;

    if (!Channels || !(men = Channels[chan])) return;
	
    bwmsg = "<<"+chan+">> " + msg;
    cmsg = CYN+"<<"+RED+chan+CYN+">> "+NORM+msg;

    i = sizeof(men);
    if (chan == "Blood") {	/* yet another patchy solution */
	/*
	 * The receive_message() function in the mark sends the message
	 * to bearer of the mark. It also checks for muffled and color
	 */
	while (i--)
	  if (men[i])
	    men[i]->receive_message(priority, bwmsg, cmsg);
    }
    else {
	while (i--)
	  if (men[i])
	    tell_object(men[i], query_attribute("ansi", men[i]) ? cmsg : bwmsg);
      else
	    deregister(men[i], chan);
    }
}

int
debug()
{
  int i, j;
  string *chans;
  object *who;
  
  if (!Channels) {
    write("No channels created.\n");
	return 1;
  }
  
  chans = keys(Channels);
  for(i = 0; i < sizeof(chans); i++) {
    write(chans[i]+": ");
	who = Channels[chans[i]];
	for( j=0; j < sizeof(who); j++) {
	  if(who[j]) write(who[j]->query_name()+",");
	  else write("GONE,");
	}
	write("\n");
  }
  return 1;
}  