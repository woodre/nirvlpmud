/*
	mob_talk.c - Monster talking made eZ.  Hooray!
	
	functions: mob_say(), mob_write()  [both analagous to say() & write()]
	           mob_talk(), mob_emote() [formatted say and emote]
	
	author: Quicksilver @ Nirvana
	
	history: v1.0 - 11-June-2004
*/

#include "/players/quicksilver/std/std.h"
#include STRING_FUNS

void mob_say(string message, object *exception_list) {
	object *obs_not_receiving_msg;
	
	if(exception_list) {
		if(pointerp(exception_list)) {
			obs_not_receiving_msg = exception_list + ({ this_object() });
		}
		else {
			obs_not_receiving_msg = ({ exception_list, this_object() });
		}
	} else obs_not_receiving_msg = ({ this_object() });
	
	tell_room(environment(this_object()), message, obs_not_receiving_msg);
}

void mob_write(string message) { tell_object(this_object(), message); }

void mob_talk(string message, object *exception_list) {
	/* type casting is req'd for some silly reason...  used in mob_emote()
	   as well */
	mob_say((string)(line_wrap(this_object()->query_name() + " says: " +
	                 message) + "\n"), exception_list);
	mob_write(line_wrap("You say: " + message) + "\n");
}

void mob_emote(string message, object *exception_list) {
	mob_say((string)line_wrap(this_object()->query_name() + " " + message) +
	                          "\n", exception_list);
	mob_write((string)line_wrap(this_object()->query_name() + " " + message) +
	                            "\n");
}