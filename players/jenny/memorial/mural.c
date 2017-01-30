/*  /players/snow/ITEMS/notice.c used as an example for how to do this.  */
#include "/players/jenny/define.h"
string messages, new_hd, new_body;
int num_messages;
object who;

id(str) {
    return str == "mural" || str == "large mural" || str == "the mural";
}

long() {
  write(
"This large mural covers the walls and ceiling.  It is a compilation\n"+
"of the thoughts and actions of the lady Dreamspeakr, as perceived\n"+
"by her fellow Nirvana adventurers.  Some of the contributions are\n"+
"prose of how players felt about her, others are paintings of how\n"+
"they saw her, and what she meant to them.  To start writing a\n"+
"contribution to the mural, type 'contribute <header>'.  To read a\n"+
"contribution, type 'read #'.\n");
if(TPL > 39) { write("You can remove an inappripiate contribution with 'remove #'\n");}
    if (num_messages == 0) {
        write("The mural does not have any contributions yet.\n");
        return;
    }
    write("The mural has " + num_messages+" contributions.\n");
    if(this_player()->query_level() < 21)
    say(call_other(this_player(), "query_name") +
          " looks at the mural.\n");
    headers();
}

short();

get() {
    write("You cannot take the mural.\n");
    return 0;
}

init() {
    add_action("new","contribute");
    add_action("read","read");
    add_action("remove","remove");
}

reset(arg) {
    if (arg)
        return;
    restore_object("players/jenny/memorial/mural");
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
  if(this_player()->query_level() < 2) {
    write("Thank you for your interest in contributing "+TPN+"\n"+
          "This mural will be happy to recieve your contribution once you\n"+
          "reach level 2.\n"); return 1; }
    if (who && environment(who) == environment(this_object())) {
        write(call_other(who, "query_name") + " is busy writing.\n");
        return 1;
    }
    if (num_messages == 100) {
        write("The mural is full, some room with have to be made for your contribution.\n");
        return 1;
    }
    if (strlen(hd) > 50) {
       write("Your header is too long.\n");
        return 1;
    }
    new_hd = hd;
    input_to("get_body");
    write("Write your contribution, abort with '~q', and terminate with '**'.\n");
    write("]");
    new_body = "";
    return 1;
}

get_body(str) {
        if (str == "~q") {
                write("Contribution aborted.\n");
                num_messages += 0;
                new_hd = "";
                new_body = "";
                return;
        }

    if (str == "**") {
        new_hd = new_hd + "(" + call_other(this_player(), "query_real_name") +
            ")";
        messages = messages + new_hd + ":\n**\n" + new_body + "\n**\n";
        num_messages += 1;
        new_body = 0;
        new_hd = 0;
      save_object("players/jenny/memorial/mural");
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
        write("There  are not that many contributions.\n");
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
                  " reads a contribution titled '" + hd + "'.\n");
            write("The contribution is titled '" + hd + "':\n\n");
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
        write("Not that many contributions.\n");
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
        if(sscanf(hd, "%sboltar", jun) == 1 && this_player()->query_real_name() !="boltar") {
         write("You cannot remove this contribution.\n");
         messages=jun2;
         return 1;
        }
  if(this_player()->query_level() < 40) {
    write("You cannot remove contributions.\n"); return 1; }
    if(this_player()->query_level() < 40)
            say(call_other(this_player(), "query_name") +
                  " removed a contribution titled '" + hd + "'.\n");
            write("Ok.\n");
            messages = messages + rest;
            num_messages -= 1;
      save_object("players/jenny/memorial/mural"); 
          return 1;
        }
        messages = messages + hd + ":\n**\n" + body + "\n**\n";
    }
    write("Hm. This should not happen.\n");
}
