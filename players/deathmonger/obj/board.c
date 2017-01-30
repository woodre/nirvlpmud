
#include "board.h"
string messages, new_hd, new_body, datafile, name;
int num_messages;
object who;

set_datafile(str){
   messages = 0; new_hd=0; new_body=0; datafile=0;name=0;
   num_messages = 0;
   datafile = BOARD_DIR+str;
   restore_object(datafile);
}
query_datafile(){ return datafile; }

set_name(str){ name = str; }
query_name(){ return name; }

id(str) {
    return str == "bulletin board" || str == "board" ||
           str == name || str == "bulletinboard";
}

long() {
    write("This is the "+name+" board.\n");
    write("You can set up new notes with the command 'note headline'.\n");
    write("Read a note with 'read num', and remove an old note with\n");
    write("'remove num'.\n");
    if (num_messages == 0) {
	write("It is empty.\n");
	return;
    }
    write("The bulletin board contains " + num_messages);
    if (num_messages == 1)
	write(" note:\n\n");
    else
	write(" notes:\n\n");
	headers();
}

short() {
  return "A bulletin board ("+name+") ("+num_messages+" messages)";
}

get() {
    write("It is secured to the ground.\n");
    return 0;
}

init() {
    add_action("new","note");
    add_action("read","read");
    add_action("remove","remove");
}

reset(arg) {
    if (arg)
	return;
    name = "bulletin";
    restore_object("bulletin");
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
	write(call_other(who, "query_name") + " is busy writing.\n");
	return 1;
    }
    if (num_messages == 40) {
	write("You have to remove an old message first.\n");
	return 1;
    }
    if (strlen(hd) > 50) {
	write("Too long header to fit the paper.\n");
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
       if(this_player()->query_real_name() != "guest")
	new_hd = new_hd + "(" + call_other(this_player(), "query_name") +
	    ", " + extract(ctime(time()), 4, 9) + ")";
        else
        new_hd = new_hd + "(" + call_other(this_player(), "query_name") +
            ", " + extract(ctime(time()), 4, 9) + ")"+
         "[ "+query_ip_name(this_player())+" ]";
	messages = messages + new_hd + ":\n**\n" + new_body + "\n**\n";
	num_messages += 1;
	new_body = 0;
	new_hd = 0;
	save_object(datafile);
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
    if (i < 1 || i > num_messages) {
	write("Not that number of messages.\n");
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
        write("The note is titled '" + hd + "':\n\n");
	    write(body);
	    return 1;
	}
    }
    write("Hm. This should not happen.\n");
}

remove(str) {
    string hd, body, rest;
    int i, tmp;
    string name;
    if (str == 0 || (sscanf(str, "%d", i) != 1 &&
		     sscanf(str, "note %d", i) != 1))
	return 0;
    if (i < 1 || i > num_messages) {
	write("Not that number of messages.\n");
	return 1;
    }
    rest = messages;
    messages = "";
    while(rest != 0 && rest != "") {
	i -= 1;
	tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
	if (tmp != 2 && tmp != 3) {
	    write("Corrupt.\n");
	    return;
	}
	if (i == 0) {
           if(this_player()->query_level() < 20 && sscanf(lower_case(hd), "%s"+this_player()->query_real_name()+"%s", name, name) != 2) {
             write("You cannot remove somebody else's note.\n");
            messages = messages + hd + ":\n**\n" + body + "\n**\n";
             return 1;
           }
	    say(call_other(this_player(), "query_name") +
		  " removed a note titled '" + hd + "'.\n");
	    write("Ok.\n");
	    messages = messages + rest;
	    num_messages -= 1;
		save_object(datafile);
	    return 1;
	}
	messages = messages + hd + ":\n**\n" + body + "\n**\n";
    }
    write("Hm. This should not happen.\n");
}
