#include "/players/dune/closed/guild/DEFS.h"
inherit "/players/snow/bull_board.c";


/*** Override the below functions when inheriting this object ****/
description() {}

short() {
    return ("A light board(" + num_messages + " msgs)");
}

restore_me() {}
save_me()    {}
/*****************************************************************/


status id(string str) { return str == "board" || str == "terminal"; }

long() {
    description();
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

reset(arg) {
    if (arg)
        return;
    restore_me();
}

get_body(str) {
  if(str == "~q"){
    new_body=0; new_hd=0; write("Message canceled.\n");  who = 0; return;
   }
    if (str == "**") {
        if(!new_hd) new_hd = "";
        new_hd = new_hd + "(" + call_other(this_player(), "query_real_name") +
            ")";
        messages = messages + new_hd + ":\n**\n" + new_body + "\n**\n";
        num_messages += 1;
        new_body = 0;
        new_hd = 0;
        save_me();
        write("Ok.\n");
        who = 0;
        return;
    }
    new_body = new_body + str + "\n";
    write("]");
    input_to("get_body");
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
            say(call_other(this_player(), "query_name") +
                  " removed a note titled '" + hd + "'.\n");
            write("Ok.\n");
            messages = messages + rest;
            num_messages -= 1;
            save_me();
            return 1;
        }
        messages = messages + hd + ":\n**\n" + body + "\n**\n";
    }
    write("Hm. This should not happen.\n");
}

new(str) {
  ::new(str);
  return 1; }

read(str) {
  ::read(str);
  return 1; }
