/* DERVISH GUILD BOARD */

#include "../defs.h"

string nm;
string messages, new_hd, new_body;
int num_messages;
object who;

id(str) {
    return str == "sandstone" || str == "tablet" || str == "sandstone tablet";
}

long() {
    write("You can inscribe the sandstone tablet with the command 'inscribe <title>'.\n");
    write("Read an inscription with 'read <#>'.\n");
    if (num_messages == 0) {
	write("It is empty.\n");
	return;
    }
    write("The sandstone tablet contains " + num_messages);
    if (num_messages == 1)
	write(" inscription:\n\n");
    else
	write(" inscriptions:\n\n");
    if(TP->query_level() < 20) say(TP->query_name()+" studies the sandstone tablet.\n");
    headers();
}

short() {
    return (BOLD+"A sandstone tablet (" + num_messages + ")"+OFF);
}

get() {
    write("You cannot pick this up.\n");
    return 0;
}

init() {
    add_action("new"); add_verb("inscribe");
    add_action("read"); add_verb("read");
    add_action("remove"); add_verb("remove");
}

reset(arg) {
    if (arg)
	return;
     restore_object(BOARDPATH+"sandstone");
}

headers() {
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
    if (!hd)
	return 0;
    if (who && environment(who) == environment(this_object())) {
	write(call_other(who, "query_name") + " is busy inscribing.\n");
	return 1;
    }
    if (num_messages == 50) {
	write("An old inscription must be erased first.\n");
	return 1;
    }
    if (strlen(hd) > 50) {
	write("Too long header to fit the sandstone.\n");
	return 1;
    }
    new_hd = hd;
    input_to("get_body");
    write("Give message, and terminate with '**'.\n");
    write("]");
    new_body = "";
    return 1;
}

get_body(str) {
    if (str == "**") {
	new_hd = new_hd + "("+TP->query_real_name()+")";
	messages = messages + new_hd + ":\n**\n" + new_body + "\n**\n";
	num_messages += 1;
	new_body = 0;
	new_hd = 0;
      save_object(BOARDPATH+"sandstone");
	write("Ok.\n");
	who = 0;
	return;
    }
    new_body = new_body + str + "\n";
    write("]");
    input_to("get_body");
}

read(str) {
    string hd, body, rest;
    int i, tmp;

    if (str == 0 || (sscanf(str, "%d", i) != 1 &&
		     sscanf(str, "note %d", i) != 1))
	return 0;
    if (i > num_messages) {
	write("Not that number of inscriptions.\n");
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
		  " reads an inscription titled '" + hd + "'.\n");
	    write("The inscription is titled '" + hd + "':\n\n");
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
	write("Not that number of inscriptions.\n");
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
  if(!DERVWIZ(this_player()) && sscanf(lower_case(hd),"%s"+
   (string)this_player()->query_real_name()+"%s",nm,nm)!=2)
  {
   write("You cannot remove somebody else's inscription.\n");
   messages = jun2;
   return 1;
  }
	    write("Ok.\n");
            say(capitalize(this_player()->query_real_name())+" removed a note titled "+hd+".\n");
            messages = messages + rest;
	    num_messages -= 1;
            save_object(BOARDPATH+"sandstone");
	    return 1;
	}
	messages = messages + hd + ":\n**\n" + body + "\n**\n";
    }
    write("Hm. This should not happen.\n");
}
