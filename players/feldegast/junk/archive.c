#define BOARD_DIR "players/feldegast/junk/"
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
    return str == "archive" || str == "book" ||
           str == name || str == "tome";
}

long() {
    write("This is the "+name+" archive, a neatly arranged tome with tons\n"+
          "of old notes bound between a thick leather cover.\n");
    write("You may read an old note with 'read #'.\n");
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
  return "The "+name+" Archive("+num_messages+" messages)";
}


init() {
    add_action("read"); add_verb("read");
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

