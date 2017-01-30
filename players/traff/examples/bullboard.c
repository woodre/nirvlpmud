string messages, new_hd, new_body;
int num_messages;
object who;

id(str) { return str == "holograph" || str =="board"; }

long() {
  write("Hovering about, with no apparent lightsource, and wildly\n"+
  "flickering definition is a holograph with the defined shape of\n"+
  "a bulletin board. Reaching out to grab it, you realize that it is\n"+
  "almost real! (albeit translucent...)\n"+
  "You can set up new notes with the command 'note headline'.\n"+
  "Read a note with 'read num', and remove an old note with\n"+
  "'remove num'.\n");
    if (num_messages == 0) {
        write("It is empty.\n");
        return;
    }
    write("The holograph contains " + num_messages);
    if (num_messages == 1)
        write(" note:\n\n");
    else
        write(" notes:\n\n");
    say(call_other(this_player(), "query_name") +
          " studies the holograph.\n");
    headers();
}

short() {
    return ("A holograph of a bulletin board [" + num_messages + "]");
}

get() {
    write("How???\n");
    return 0;
}

init() {
    add_action("new","note");
    add_action("read","read");
    add_action("remove","remove");
    add_action("moveme","up");
}

reset(arg) {
    if(arg) return;
    restore_object("players/mizan/etheriel/BULLETINS");
}

moveme() {
  this_player()->move_player("up#room/wild1");
  return 1;
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
    if (who) {
        write((who->query_name()) + " is busy writing.\n");
        return 1;
    }
    if (num_messages == 100) {
        write("You have to remove an old message first.\n");
        return 1;
    }
    if (strlen(hd) > 50) {
        write("The header is too long.\n");
        return 1;
    }
    who=this_player();
    say(who->query_name())+" begins writing a note and disappears into the hologram.\n)";
    move_object(who, this_object());
    new_hd = hd;
    input_to("get_body");
    write("You are inside the hologram.\n"+
    "All environment noise has been muffled.\n"+
    "Give message, and terminate with '**'.\n");
    write("]");
    new_body = "";
    return 1;
}

get_body(str) {
    if (str == "**") {
        new_hd = new_hd + "[" + capitalize(this_player()->query_real_name()) + ", "
	+ extract(ctime(time()), 4, 9)+ "]";
        messages = messages + new_hd + ":\n**\n" + new_body + "\n**\n";
        num_messages += 1;
        new_body = 0;
        new_hd = 0;
        save_object("players/mizan/etheriel/BULLETINS");
        say((who->query_name())+" finishes writing a note and fades into view.\n");
        move_object(who, environment(this_object()));
        write("Done.\n");
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
            save_object("players/mizan/etheriel/BULLETINS");
            return 1;
        }
        messages = messages + hd + ":\n**\n" + body + "\n**\n";
    }
    write("Hm. This should not happen.\n");
}
