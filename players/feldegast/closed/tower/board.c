#include "/players/feldegast/closed/shortcut.h"
inherit "obj/bull_board";
string *members;
reset(arg) {
  if (arg) return;
  restore_object("players/feldegast/closed/tower/notes");
  members=({
    "feldegast",
    "snow",
    "zeus",
    "maledicta",
    "wocket",
  });
}
read(str) {
  if(!(member_array(this_player()->query_real_name(),members)>-1))
  {
    write_file("/players/feldegast/closed/tower/ALERT",
      ctime(time())+"  "+this_player()->query_name()+
      " attempted to read the board in the meeting room.\n"
    );
    return 1;
  }
  else
    return ::read(str);
} 

get_body(str) {
    if (str == "**") {
	new_hd = new_hd + "(" + call_other(this_player(), "query_real_name") +
	    ")";
	messages = messages + new_hd + ":\n**\n" + new_body + "\n**\n";
	num_messages += 1;
	new_body = 0;
	new_hd = 0;
	save_object("players/feldegast/closed/tower/notes");
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

  if(member_array(this_player()->query_real_name(), members) >=0) {
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
	    save_object("players/feldegast/closed/tower/notes");
	    return 1;
	}
	messages = messages + hd + ":\n**\n" + body + "\n**\n";
    }
    write("Hm. This should not happen.\n");
  }
}
