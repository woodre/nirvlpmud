string messages, new_hd, new_body;
int num_messages;
object who;

id(str) {
    return str == "bulletin board" || str == "board" || str == "bulletinboard";
}

long() {
    write("You can set up new notes with the command 'note headline'.\n");
    write("Read a note with 'read num', and remove an old note with\n");
    write("'remove num'.\n");
    if (num_messages == 0) {
	write("It is empty.\n");
	return;
    }
    write("The bulletine board contains " + num_messages);
    if (num_messages == 1)
	write(" note:\n\n");
    else
	write(" notes:\n\n");
    say(call_other(this_player(), "query_name") +
	  " studies the bulletin board.\n");
    headers();
}

short() {
    return ("A bulletin board(" + num_messages + " msgs)");
}

get() {
    write("It is secured to the ground.\n");
    return 0;
}

init() {
#if 0 /* Rumplemintz */
    add_action("new"); add_verb("note");
    add_action("read"); add_verb("read");
    add_action("remove"); add_verb("remove");
#else
  add_action("new", "note");
  add_action("read", "read");
  add_action("remove", "remove");
#endif
}

reset(arg) {
    if (arg)
	return;
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
    if (num_messages == 50) {
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
  string timestamp; /* Rumplemintz */

  timestamp = ctime();
    if (str == "**") {
    say(this_player()->query_name()+ " has completed a note : " +
        new_hd + "\n");
    new_hd = new_hd + "(" + this_player()->query_name() + ", " +
             timestamp[4..9] + ", " + timestamp[20..24] + ")";
	messages = messages + new_hd + ":\n**\n" + new_body + "\n**\n";
	num_messages += 1;
	new_body = 0;
	new_hd = 0;
	save_object("bulletin");
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
    string myname,jun2,jun;
    int i, tmp;

    if (str == 0 || (sscanf(str, "%d", i) != 1 &&
		     sscanf(str, "note %d", i) != 1))
	return 0;
    if (i > num_messages) {
	write("Not that number of messages.\n");
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
/*
        if(sscanf(hd, "%sboltar", jun) == 1 && this_player()->query_real_name() !="boltar") {
*/
         myname=this_player()->query_real_name();
         if(sscanf(hd, "%s"+myname, jun) != 1 && this_player()->query_level() <21) {
         write("You cannot remove this message.\n");
         messages=jun2;
         return 1;
        }
	    say(call_other(this_player(), "query_name") +
		  " removed a note titled '" + hd + "'.\n");
	    write("Ok.\n");
	    messages = messages + rest;
	    num_messages -= 1;
	    save_object("bulletin");
	    return 1;
	}
	messages = messages + hd + ":\n**\n" + body + "\n**\n";
    }
    write("Hm. This should not happen.\n");
}
