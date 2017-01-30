string messages, new_hd, new_body;
int num_messages;
object who;

long() {
    write("You can set up new files with the command 'edit filename'.\n");
    write("Read a file with 'see num', and remove an old file with\n");
    write("'rem num'. Just type 'dest_ed' to get rid of this object.\n");
    if (num_messages == 0) {
        write("No files.\n");
        return 1;
    }
    write("There are " + num_messages);
    if (num_messages == 1)
        write(" file:\n\n");
    else
        write(" files:\n\n");
    headers();
    return 1;
}

id(str) { return (str == "editor"); }

short() { return("Undead's editor"); }

init()  {
    add_action("new"); add_verb("edit");
    add_action("read"); add_verb("see");
    add_action("remove"); add_verb("rem");
    add_action("dest_ed"); add_verb("dest_ed");
}

dest_ed()  {
        save_object("players/hurtbrain/helpdir/guildfiles");
        write("Ok.\n");
        destruct(this_object());
	return 1;
}	

reset(arg) {
	if(arg) return;
	restore_object("players/hurtbrain/helpdir/guildfiles");
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
    if (num_messages == 30) {
        write("You have to remove an old file first.\n");
        return 1;
    }
    if (strlen(hd) > 50) {
        write("Too long header to fit the paper.\n");
        return 1;
    }
    new_hd = hd;
    input_to("get_body");
    write("Give file, and terminate with '**'.\n");
    write("]");
    new_body = "";
    return 1;
}

get_body(str) {
    if (str == "**") {
        new_hd = new_hd + "(" + call_other(this_player(), "query_real_name") +
            ")";
        messages = messages + new_hd + ":\n**\n" + new_body + "\n**\n";
        num_messages += 1;
        new_body = 0;
        new_hd = 0;
        save_object("players/hurtbrain/helpdir/guildfiles");
        write("Ok.\n");
        who = 0;
        return 1;
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
        write("Not that number of files.\n");
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
            write("The file is titled '" + hd + "':\n\n");
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
        write("Not that number of files.\n");
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
            write("Ok.\n");
            messages = messages + rest;
            num_messages -= 1;
            save_object("players/hurtbrain/helpdir/guildfiles");
            return 1;
        }
        messages = messages + hd + ":\n**\n" + body + "\n**\n";
    }
    write("Hm. This should not happen.\n");
}

drop() { return 1; }

get() { return 1; }
