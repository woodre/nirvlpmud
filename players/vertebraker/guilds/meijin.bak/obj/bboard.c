#include "/players/pavlik/guild/defs.h";
#define NOTES "players/pavlik/guild/log/bboard_notes"

string messages;
string new_hd;
string new_body;
int num_messages;
object who;

id(str) {
  return str == "bboard" || str == "board";
}

short() {
  return "The Message Board ["+num_messages+"]";
}

long() {
  write(
  "A small message board is present here for members of the guild to\n"+
  "write notes.  The messages are tacked neatly onto the board with\n"+
  "little tacks.  If you would like to post a note on this board, use\n"+
  "'note <subject>'.  Please be considerate with the contents of your\n"+
  "messages.  Only wizards can remove notes from this board.\n");
  if (num_messages == 0) {
	write("There are no notes at this time.\n");
	return;
  }
  if(num_messages == 1)
	write("There is 1 message.\n");
  else
	write("There are "+num_messages+" notes at this time.\n");
  headers();
}

get() {
    return 0;
}

init() {
    add_action("new"); add_verb("note");
    add_action("read"); add_verb("read");
    add_action("remove"); add_verb("remove");
}

reset(arg) {
  if(arg) return;
  restore_object(NOTES);
}

headers() {
  string hd, body, rest;
  int i, tmp;

  if(this_player()->query_guild_name() != "meijin") {
	write("You cannot make any sense of it.\n");
	return 1;
  }
  i = 1;
  rest = messages;
  while(rest != 0 && rest != "") {
        tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
        if (tmp != 2 && tmp != 3) {
            write("Corrupt.\n");
            return;
        }
	write("["+i+"]   "+hd+"\n");
        i += 1;
  }
}

new(hd) {
  if(!hd)
	return 0;
  if(who && environment(who) == environment(this_object())) {
	write(call_other(who, "query_name") + " is busy writing.\n");
        return 1;
  }
  if (strlen(hd) > 50) {
        write("Too long header to fit the paper.\n");
        return 1;
  }
  new_hd = hd;
  input_to("get_body");
  write("Sciribing new note.  End note with '**'.\n");
  write("]");
  new_body = "";
  return 1;
}

get_body(str) {
  if(str == "**") {
        string wday,surplus,month,day;
        int number;
        sscanf(ctime(time()),"%s %s %s %d:%s",wday,month,day,number,surplus);
        new_hd = wday+" "+month+" "+day+"\t | "+new_hd+
        " ("+capitalize(this_player()->query_real_name()) +")";
        messages = messages + new_hd + ":\n**\n" + new_body + "\n**\n";
        num_messages += 1;
        new_body = 0;
        new_hd = 0;
        save_object(NOTES);
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

    if(str == 0 || (sscanf(str, "%d", i) != 1 &&
                     sscanf(str, "note %d", i) != 1))
        return 0;
    if(i > num_messages) {
        write("There are not that many messages on the board.\n");
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
                  " reads an entry titled '" + hd + "'.\n");
            write("The entry is titled '" + hd + "':\n\n");
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
    if(this_player()->query_level() < 21) 
    {
       write("You cannot remove a notice from this board.\n");
       return 1;
     }   

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
        save_object(NOTES);
            return 1;
        }
        messages = messages + hd + ":\n**\n" + body + "\n**\n";
    }
    write("Hm. This should not happen.\n");
}
