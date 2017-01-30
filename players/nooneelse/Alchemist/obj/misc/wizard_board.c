/*
  alchemist_wiz_board.c - allow only wizard Alchemists to write a note
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

#define BOARD_NAME "players/nooneelse/Alchemist/board/wizard_board_save"

string board_message_file, messages, new_hd, new_body;
int num_messages;
object who;

id(str) {
  return str=="bulletin board" || str=="board" || str=="bulletinboard";
}

long() {
  if (this_player()->query_level()<21 || !present("Alchemist Robes", this_player())) {
    write("You can read a note with 'read #'.\n");
  }
  if (this_player()->query_level()>20 && present("Alchemist Robes", this_player())) {
    write("You can set up new notes with the command 'note <headline>'.\n"+
          "Read a note with 'read <#>', and remove an old note with\n"+
          "'remove <#>'.\n");
  }
  if (num_messages==0) {
    write("It is empty.\n");
    return;
  }
  write("The bulletin board contains "+num_messages);
  if (num_messages==1)
      write(" note:\n\n");
  else
      write(" notes:\n\n");
  say(this_player()->query_name()+" studies the bulletin board.\n");
  headers();
}

short() { return ("A bulletin board"); }

get() {
  write("It is secured to the ground.\n");
  return;
}

init() {
  add_action("new",    "note");
  add_action("read",   "read");
  add_action("reply",  "reply");
  add_action("remove", "remove");
}

reset(arg) {
  if (arg) return;

  board_message_file = BOARD_NAME;
  restore_object(board_message_file);
  board_message_file = BOARD_NAME;
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
    write(i+":\t"+hd+"\n");
    i += 1;
  }
}

new(hd) {
  if (!hd) return;
  if (this_player()->query_level()<21 || !present("Alchemist Robes", this_player())) {
    write("You cannot add notes to this board.\n");
  }
  if (who && environment(who)==environment(this_object())) {
    write(who->query_name()+" is busy writing.\n");
    return 1;
  }
  if (num_messages==25) {
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
  if (str=="**") {
    new_hd = new_hd+"("+this_player()->query_real_name()+", "+
             extract(ctime(time()), 4, 9)+", "+this_player()->query_level()+")";
    messages = messages+new_hd+":\n**\n"+new_body+"\n**\n";
    num_messages+= 1;
    new_body = 0;
    new_hd = 0;
    save_object(board_message_file);
    write("Ok.\n");
    who = 0;
    return;
  }
  new_body = new_body+str+"\n";
  write("]");
  input_to("get_body");
}

read(str) {
  string hd, body, rest;
  int i, tmp;

  if (str==0 || (sscanf(str, "%d", i) != 1 && sscanf(str, "note %d", i) != 1))
    return;
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
    if (i==0) {
      say(this_player()->query_name()+" reads a note titled '"+hd+"'.\n");
      write("The note is titled '"+hd+"':\n\n");
      write(body);
      return 1;
    }
  }
  write("Hmm. This should not happen.\n");
}

reply(str) {
  string hd, body, rest;
  int i, tmp;

  if (this_player()->query_level()<21 || !present("Alchemist Robes", this_player())) {
    write("You cannot add notes to this board.\n");
  }
  if (str==0 || (sscanf(str, "%d", i) != 1 && sscanf(str, "note %d", i) != 1))
    return;
  if (i > num_messages) {
    write("Not that number of messages.\n");
    return 1;
  }
  rest = messages;
  while(rest != 0 && rest != "") {
    i -= 1;
    tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
    if (tmp != 2 && tmp != 3) {
      write("This bulletin board is Corrupt! Mail the wizard that\n"+
            "is in charge of it.\n");
      return 1;
    }
    if (i==0) {
      say(this_player()->query_name()+" reads a note titled '"+hd+"'.\n");
      write("The note is titled '"+hd+"':\n\n");
      write(body);
      new_hd = hd;
      input_to("get_body2");
      write("\n\nNow, enter your reply, and terminate with '**'.\n");
      write("]");
      new_body = body;
      return 1;
    }
  }
}

get_body2(str) {
  if (str=="**") {
    new_hd = new_hd+"("+this_player()->query_real_name()+", "+
             extract(ctime(time()), 4, 9)+", "+this_player()->query_level()+")";
    messages = messages+new_hd+":\n**\n"+new_body+"\n**\n";
    num_messages+= 1;
    new_body = 0;
    new_hd = 0;
    save_object(board_message_file);
    write("Ok.\n");
    who = 0;
    return;
  }
  new_body = new_body+str+"\n";
  write("]");
  input_to("get_body2");
}

remove(str) {
  string hd, body, rest;
  int i, tmp;

  if (this_player()->query_level()<21 || !present("Alchemist Robes", this_player())) {
    write("You cannot remove notes to this board.\n");
  }
  if (str==0 || (sscanf(str, "%d", i) != 1 && sscanf(str, "note %d", i) != 1))
    return;
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
    if (i==0) {
      say(this_player()->query_name()+" removed a note titled '"+hd+"'.\n");
      write("Ok.\n");
      messages = messages+rest;
      num_messages -= 1;
      save_object(board_message_file);
      return 1;
    }
    messages = messages+hd+":\n**\n"+body+"\n**\n";
  }
  write("Hm. This should not happen.\n");
}
