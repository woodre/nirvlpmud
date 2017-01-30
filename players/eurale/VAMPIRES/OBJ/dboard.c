#include <ansi.h>
#include "/obj/user/dt_stamp.h"

string messages, new_hd, new_body;
string nm;
int num_messages;
object who;

id(str){ return str == "board" || str == "vamp board" || str == "discussion board"; }

long(){
  write(
"This bulletin board is attached to the northern wall of the room.  It\n"+
"is here so that important messages can be saved for everyone to 'read'.\n");
  if(num_messages == 0)
  {
    write("Right now the board is empty.\n");
    return;
  }
  write("The bulletin board contains "+num_messages);
  if(num_messages == 1)
    write(" messages:\n\n");
  else
    write(" messages:\n\n");
  say(this_player()->query_name()+" studies the bulletin board.\n");
  headers();
}

short(){
  if(num_messages)
    return HIR+"Vampire Discussion Board"+NORM;
  else
    return HIR+"Vampire Discussion Board"+NORM;
}

drop(){              return 1; } 
get(){               return 0; }
can_put_and_get(){   return 0; }

init(){
#ifndef __LDMUD__
  add_action("new");    add_verb("note");
  add_action("read");   add_verb("read");
  add_action("remove"); add_verb("remove");
#else
  add_action("new", "note");
  add_action("read", "read");
  add_action("remove", "remove");
#endif
}

reset(arg){
  if(arg) return;
  
  restore_object("players/eurale/VAMPIRES/OBJ/dboard");
}

headers(){
    string hd, body, rest;
    int i, tmp;

    i = 1;
    rest = messages;
    while(rest != 0 && rest != "") {
	tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
	if (tmp != 2 && tmp != 3) {
	    write("Corrupt.\n");
	    return;
	}
	write(i + ":\t" + hd + "\n");
	i += 1;
    }
}

new(hd) {
  if(this_player()->query_guild_name() != "vampire"
    && this_player()->query_level() < 80) return 0;
    if (!hd)
	return 0;
    if (who && environment(who) == environment(this_object())) {
	write(call_other(who, "query_name") + " is busy writing.\n");
	return 1;
    }
    if (num_messages == 50) {
	write("An old note must be erased first.\n");
	return 1;
    }
    if (strlen(hd) > 50) {
	write("Too long header to fit the board.\n");
	return 1;
    }
    new_hd = "";
    new_hd = hd;
    input_to("get_body");
    write("Give message, and terminate with '**'.\n");
    write(">");
    new_body = "";
    return 1;
}

get_body(str) {
    if (str == "**") {
	new_hd = new_hd + " ("+capitalize(this_player()->query_real_name())+" "+this_player()->query_title()+")";
	new_body = new_body + "\n"+"[" + DT + "]\n";
        messages = messages + new_hd + ":\n**\n" + new_body + "\n**\n";
	num_messages += 1;
	new_body = 0;
	new_hd = 0;
	save_object("players/eurale/VAMPIRES/OBJ/dboard");
	write("Ok.\n");
	who = 0;
	return;
    }
    new_body = new_body + str + "\n";
    write(">");
    input_to("get_body");
}

read(str) {
    string hd, body, rest;
    int i, tmp;

    if(this_player()->query_guild_name() != "vampire"
      && this_player()->query_level() < 80) return 0;

    if (str == 0 || (sscanf(str, "%d", i) != 1 &&
		     sscanf(str, "note %d", i) != 1))
	return 0;
    if (i > num_messages) {
	write("Not that number of notes.\n");
	return 1;
    }
    rest = messages;
    while(rest != 0 && rest != "") {
	i -= 1;
	tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
	if (tmp != 2 && tmp != 3) {
	    write("Corrupt.\n");
	    return;
	}
	if (i == 0) {
	    say(call_other(this_player(), "query_name") +
		  " reads a note titled '" + hd + "'.\n");
	    write("The note is titled '" + hd + "':\n\n");
	    write(body);
	    return 1;
	}
    }
    write("Hm. This should not happen.\n");
}

remove(str) {
    string hd, body, rest;
    string jun2,jun;
    int i, tmp;
    if (str == 0 || (sscanf(str, "%d", i) != 1 &&
		     sscanf(str, "note %d", i) != 1))
	return 0;
    if (i > num_messages) {
	write("Not that number of notes.\n");
	return 1;
    }
    rest = messages;
    jun2 = messages;
    messages = "";
    while(rest != 0 && rest != "") {
	i -= 1;
	tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
	if (tmp != 2 && tmp != 3) {
	    write("Corrupt.\n");
	    return;
	}
	if (i == 0) {
        nm = this_player()->query_real_name();
        if(sscanf(lower_case(hd),"%s"+nm, jun) != 1 && nm != "fred" && nm != "khrell")
        {
          /* senior wizards can update this code, so blocking them is pointless */
          if(this_player()->query_level() < 5000)
          {
            write("You cannot remove somebody else's note.\n");
            messages = jun2;
            return 1;
          }
        }
            write("Ok.\n");
            say(capitalize(nm)+" removed a note titled "+hd+".\n");
      	    messages = messages + rest;
	    num_messages -= 1;
            save_object("players/eurale/VAMPIRES/OBJ/dboard");
	    return 1;
	}
	messages = messages + hd + ":\n**\n" + body + "\n**\n";
    }
    write("Hm. This should not happen.\n");
}
