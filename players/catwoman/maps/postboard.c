/*
  nooneelse_bull_board.c - new version of bull_board that allows setting the
                           file name and directory of the saved file
*/

string board_message_file, messages, new_hd, new_body;
int num_messages;
object who;

id(str) {
  return str == "map board" || str == "board" || str == "bulletinboard";
}

long() {
  write("You can set up new maps with the command 'note headline'.\n");
  write("Read a note with 'read num', and remove an old maps with\n");
  write("'remove num'.\n");
  if (num_messages == 0) {
    write("It is empty.\n");
    return;
  }
  write("The map board contains "+num_messages);
  if (num_messages == 1)
      write(" map:\n\n");
  else
      write(" maps:\n\n");
  say(this_player()->query_name()+" studies the map board.\n");
  headers();
}

short() { return ("A map board"); }


get() {
  write("It is secured to the ground.\n");
  return;
}

init() {
  add_action("new",    "note");
  add_action("read",   "read");
  add_action("remove", "remove");
}

reset(arg) {
  if (arg) return;

   board_message_file = "players/catwoman/maps/map_board_save";
  restore_object(board_message_file);
 
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
  if (who && environment(who) == environment(this_object())) {
    write(who->query_name()+" is busy writing.\n");
    return 1;
  }
  if (num_messages == 20) {
    write("You have to remove an old map first.\n");
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
    new_hd = new_hd+"("+this_player()->query_real_name()+")";
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

  if (str == 0 || (sscanf(str, "%d", i) != 1 && sscanf(str, "note %d", i) != 1))
    return;
 
  if (i > num_messages) {
    write("Not that number of maps.\n");
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
      say(this_player()->query_name()+" reads a map titled '"+hd+"'.\n");
      write("The map is titled '"+hd+"':\n\n");
      write(body);

      return 1;
    }
  }
  write("Hm. This should not happen.\n");
}

remove(str) {
  string hd, body, rest;
  int i, tmp;

  if (str == 0 || (sscanf(str, "%d", i) != 1 && sscanf(str, "note %d", i) != 1))
    return;
  if (i > num_messages) {
    write("Not that number of maps.\n");
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
      say(this_player()->query_name()+" removed a map titled '"+hd+"'.\n");
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

