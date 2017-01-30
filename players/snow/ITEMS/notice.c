string datestring; /* Rumplemintz */
string messages, new_hd, new_body;
int num_messages;
object who;

id(str) {
    return str == "bulletin board" || str == "board" || str == "announceboard";
}

long() {
  write("This is a board for wizzes to make announcements of changes.\n");
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
    if(this_player()->query_level() < 21)
    say(call_other(this_player(), "query_name") +
	  " studies the bulletin board.\n");
    headers();
}

short() {
    return ("Announcement bulletin board(" + num_messages + " msgs)");
}

get() {
    write("It is secured to the ground.\n");
    return 0;
}

init() {
    add_action("new", "note");
    add_action("read", "read");
    add_action("remove", "remove");
}

reset(arg) {
    if (arg)
	return;
    restore_object("players/snow/ITEMS/notice");
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
  if(this_player()->query_level() < 21) {
    write("You cannot write on this board.\n"); return 1; }
    if (who && environment(who) == environment(this_object())) {
	write(call_other(who, "query_name") + " is busy writing.\n");
	return 1;
    }
    if (num_messages == 60) {
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
#if 1 /* Rumplemintz */
    new_hd = new_hd + "(" + ctime()[4..9] + ", " + ctime()[20..23] + " " +
             capitalize(this_player()->query_real_name()) + ")";
#else
    new_hd = new_hd + "(" + call_other(this_player(), "query_real_name") + ")";
#endif
	messages = messages + new_hd + ":\n**\n" + new_body + "\n**\n";
	num_messages += 1;
	new_body = 0;
	new_hd = 0;
      save_object("players/snow/ITEMS/notice");
      if(!this_player()->query_invis())  /* verte */
        emit_channel("announce", "(announce) A new announcement has been posted on the Village Green board!\n");
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
      if(this_player()->query_level() < 21)
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
        if(!sscanf(hd, "%s" + (string)this_player()->query_real_name(), jun) && ((int)this_player()->query_level() < 100))
        {
         write("You cannot remove this message.\n");
         messages=jun2;
         return 1;
        }
  if(this_player()->query_level() < 21) {
    write_file("/players/snow/log/BOARD",
      ctime(time())+" "+this_player()->query_real_name()+" "+
      query_ip_number(this_player())+"\n");
    write("You cannot remove notes.\n"); return 1; }
    if(this_player()->query_level() < 21)
	    say(call_other(this_player(), "query_name") +
		  " removed a note titled '" + hd + "'.\n");
	    write("Ok.\n");
	    messages = messages + rest;
	    num_messages -= 1;
      save_object("players/snow/ITEMS/notice");
	    return 1;
	}
	messages = messages + hd + ":\n**\n" + body + "\n**\n";
    }
    write("Hm. This should not happen.\n");
}
