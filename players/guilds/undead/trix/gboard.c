string messages, new_hd, new_body,current;
int num_messages,number,flag;
object who;

id(str) {
    return str == "bulletin board" || str == "board" || str == "bulletinboard";
}

long() {
    write("This is the Undead Guild Board, where you can post your critics, suggestions,\n");
    write("announces or any kind of thought regarding the guild by typing 'note headline'.\n");
    write("To read a note type 'read num'.\n");
    write("Gorgan, Hurtbrain and Trix thank you in advance for your collaboration.\n");
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
    return ("Undead Guild Bulletin Board[" + num_messages + " msgs]");
}

get() {
    write("It is secured to the ground.\n");
    return 0;
}

init() {
    add_action("new"); add_verb("note");
    add_action("read"); add_verb("read");
    add_action("remove"); add_verb("remove");
}

reset(arg) {
    if (arg)
        return;
    restore_object("players/trix/closed/guild/bull");
}

headers() {
    number = 1;
    current = messages;
    flag=1;
    list();
    return 1;
}    

list() {
    string hd, body, rest;
    int i, tmp;

    i=(number-1)/20;
    while((current != 0 && current!= "" &&number!=i*20+1) || flag) {
        flag=0;
        tmp = sscanf(current, "%s:\n**\n%s\n**\n%s", hd, body, current);
        if (tmp != 2 && tmp != 3) {
            write("Corrupt.\n");
            return;
        }
        write(number+ ":\t\b\b\b\b\b" + hd + "\n");
        number+= 1;
        i=(number-1)/20;
    }
    if(number==i*20+1&&!flag) {
		write("More (q or Q to exit):");
                flag=1;
		input_to("more");
    }
}

more(arg)  {
        if(arg=="q" || arg=="Q")
         {
                write("\n");
                        }
        else  {
                list();
                }
        return 1;
}

new(hd) {
    if (!hd)
        return 0;
    if (who && environment(who) == environment(this_object())) {
        write(call_other(who, "query_name") + " is busy writing.\n");
        return 1;
    }
    if (num_messages == 30) {
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
        new_hd = ctime(time())+" | " + "[" +capitalize(this_player()->query_real_name()) +
            "]: "+new_hd;
        messages = messages + new_hd + ":\n**\n" + new_body + "\n**\n";
        num_messages += 1;
        new_body = 0;
        new_hd = 0;
        save_object("players/trix/closed/guild/bull");
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
    string hd, body, rest,contname;
    int i, tmp;
    contname=this_player()->query_real_name();
/*
    if(contname!="hurtbrain"&&contname!="trix"&&contname!="gorgan")
     { write("Only guild-wizes can remove notes they didn't write.\n");
       return 1;
     }   
 */

    if (!str || (sscanf(str, "%d", i) != 1 &&
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
        save_object("players/trix/closed/guild/bull");
            return 1;
        }
        messages = messages + hd + ":\n**\n" + body + "\n**\n";
    }
    write("Hm. This should not happen.\n");
}
