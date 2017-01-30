/*
#include "board.h" */
string messages, new_hd, new_body, datafile, name;
int num_messages, seated;
object who;

set_datafile(str){
   messages = ""; new_hd=0; new_body=0; datafile=0;name=0;
   num_messages = 0;
   datafile = "players/francesco/letters/items/"+str;
   restore_object(datafile);
}
query_datafile(){ return datafile; }

set_name(str){ name = str; }
query_name(){ return name; }

id(str) {
    return str == "bulletin board" || str == "board" || str == "bulletinboard";
}

long() {
    write("  This "+name+" board is open to everyone to write their own notes\n"+
          "about the so called 'Nirvana Fiction'.  Everything can be posted,\n"+
          "provided it is not offensive, nor rude, nor scurrilous to anyone.\n"+
          "Of course, the content must be related to Nirvana environment.\n"+
          "You can set up a new note with the command 'note <header>'.\n"+
          "You can read a previous note with the command 'read #'.\n"+
          "You can remove your old notes with the command 'remove #'.\n");
    if (num_messages == 0) {
	write("It is empty.\n");
	return;
    }
    write("The bulletin board contains " + num_messages);
    if (num_messages == 1)
	write(" note:\n\n");
    else
	write(" notes:\n\n");
    say(call_other(this_player(), "query_name") +
	  " studies the bulletin board.\n");
    headers();
}

short() {
    return ("A bulletin board (" + num_messages + " messages)");
}

get() {
    write("It is secured to the ground.\n");
    return 0;
}

init() {
    add_action("new"); add_verb("note");
    add_action("read"); add_verb("read");
    add_action("remove"); add_verb("remove");
    add_action("sit");add_verb("sit");
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
    if(!seated) {notify_fail("It is better to sit on chair before writing a note.\n"); return 0; }
    if (!hd) { notify_fail("Syntax is: note <headline>\n"); return 0;}
    if (who && environment(who) == environment(this_object())) {
	write(call_other(who, "query_name") + " is busy writing.\n");
	return 1;
    }
    if (num_messages == 30) {
	write("There are too many messages on the board, it cant hold more.\n");
	return 1;
    }
    if (strlen(hd) > 50) {
	write("The max lenght for the header is fifty characters.\n");
	return 1;
    }
    new_hd = hd;
    input_to("get_body");
    write("Write your own message, and terminate with '**'.\n");
    write("]");
    new_body = "";
    return 1;
}

sit(str) {
  if(!str) { notify_fail("Sit where?\n"); return 0; }
  if(str=="on chair") {
   seated = 1;
   write("You sit on the confortable business chair, ready for writing a new note.\n");
  return 1;}
 notify_fail("Sit where?\n"); return 0; 
}

get_body(str) {
    if (str == "**") {
	new_hd = new_hd + " (" + capitalize(call_other(this_player(), "query_real_name")) +
	    ", " + extract(ctime(time()), 4, 9) + ")";
	messages = messages + new_hd + ":\n**\n" + new_body + "\n**\n";
	num_messages += 1;
	new_body = 0;
	new_hd = 0;
	save_object(datafile);
	write("After completing your new note, you get up out of the chair.\n");
        seated = 0;
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
            save_object(datafile);
	    return 1;
	}
	messages = messages + hd + ":\n**\n" + body + "\n**\n";
    }
    write("Hm. This should not happen.\n");
}


/* /players/francesco/letters/items/ */