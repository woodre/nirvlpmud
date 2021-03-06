#include "security.h"
string messages, new_hd, new_body;
int num_messages;
object who;

id(str) {
    return str == "ballot" || str == "board" || str == "noteboard" ||
           str == "voting board";
}

long() {
    write("This is the place to vote for players to put on the Most-\n");
    write("Wanted List.  To vote, look at the board, where you will see\n");
    write("nominations for players to be killed this week.  Then, vote\n");
    write("for the player(s) you would like to see on the list.  The pla-\n");
    write("yers with the most votes will be on the list.\n");
     write("To vote:\n");
    write("   vote <num> <vote> -- <comments>\n");
    write("where num is the number of the note on the board,\n");
    write("and -- <comments> are optional.\n");
    write("Read a notice with 'read num'.\n");
    if(call_other(this_player(),"query_level") >= 3) {
        write("You can set up new notices with the command 'note headline'.\n");
        write("You can remove notices with the command 'remove num'.\n");
    }
    if (num_messages == 0) {
	write("It is empty.\n");
	return;
    }
    write(num_messages);
    if (num_messages == 1)
	write(" issue is");
    else
	write(" issues are");
    write(" up for vote.\n\n");
    say(call_other(this_player(), "query_name") +
	  " studies the notice board.\n");
    headers();
}

short() {
    return ("A notice board containing issues up for vote");
}

get() {
    write("It is secured to the ground.\n");
    return 0;
}

init() {
    if(call_other(this_player(),"query_level") >= 3) {
        add_action("new"); add_verb("note");
        add_action("remove"); add_verb("remove");
    }
    add_action("read"); add_verb("read");
}

reset(arg) {
    if (arg)
	return;
    restore_object("players/deathmonger/ASSASSIN/ballot_save");
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
    if (num_messages == 10) {
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
	new_hd = new_hd + " (" + call_other(this_player(), "query_name") +
	    ")";
        if(!messages) messages = "";
	messages = messages + new_hd + ":\n**\n" + new_body + "\n**\n";
	num_messages += 1;
	new_body = 0;
	new_hd = 0;
        save_object("players/deathmonger/ASSASSIN/ballot_save");
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
    int i, tmp;

    if (str == 0 || (sscanf(str, "%d", i) != 1 &&
		     sscanf(str, "note %d", i) != 1))
	return 0;
    if (i > num_messages) {
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
	    say(call_other(this_player(), "query_name") +
		  " removed a note titled '" + hd + "'.\n");
	    write("Ok.\n");
	    messages = messages + rest;
	    num_messages -= 1;
            save_object("players/deathmonger/ASSASSIN/ballot_save");
	    return 1;
	}
	messages = messages + hd + ":\n**\n" + body + "\n**\n";
    }
    write("Hm. This should not happen.\n");
}
