#include "/players/hippo/bs.h"
#define BOARD_NAME "players/hippo/objects/bull_board"
string messages, new_hd, new_body;
int num_messages;
object who;
 
id(str) {
   return str == "board" || str == "idea board";
}
 
long() {
  write("On this board you can write comments, complains and other"+BS+
      "stuff you wanna tell the creator of this body."+BS);
write ("Possible commands for you are:  note <name> and read <num>."+BS);
    if (num_messages == 0) {
        write("It is empty.\n");
        return;
    }
    write("The board contains " + num_messages);
    if (num_messages == 1)
        write(" note:\n\n");
    else
        write(" notes:\n\n");
    say(call_other(this_player(), "query_name") +
          " studies the board.\n");
    headers();
}
 
short() {
   return ("The idea board");
 
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
    restore_object(BOARD_NAME);
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
    write("=}>");
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
      save_object(BOARD_NAME);
        write("Ok.\n");
        who = 0;
        return;
    }
    new_body = new_body + str + "\n";
    write("=}>");
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
 
/*  changed to allow wizzes to remove notes... 4/8/97  -Eurale
   if(this_player()->query_real_name() != "hippo") {
write("Heya? Your name is Hippo? --> Only HE can do this!"+BS);
      return 1;
    }
*/
if(this_player()->query_level() < 50) {
  write("You're not high enough level, sorry!\n"); return 1; }
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
      save_object(BOARD_NAME);
            return 1;
        }
        messages = messages + hd + ":\n**\n" + body + "\n**\n";
    }
    write("Hm. This should not happen.\n");
}
