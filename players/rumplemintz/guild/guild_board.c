#define BOARD_NAME "players/rumplemintz/guild/bull_board2"

string messages, new_hd, new_body;
int num_messages;
object who;

int id(string str) {
  return str == "bulletin board" || str == "board" || str == "bulletinboard";
}

string headers() {
  string hd, body, rest;
  string result;
  int i, tmp;

  i = 1;
  result = "";
  rest = messages;
  while (rest!=0 && rest!="") {
    tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
    if (tmp != 2 && tmp != 3)
      return "Corrupt.\n";
    result += i + ":\t" + hd + "\n";
  }
  return result;
}

void long() {
  write("This is the bulletin board that only Druids can see.\n"+
	"Please leave any information concerning the guild; ideas, thoughts,\n"+
	"or just random sayings, on this board. Thanks,   ---Rump.\n");
  write("You can leave notes with the command 'note <headline>'.\n");
  write("Read a note with 'read <num>', and remove and old note with\n");
  write("'remove <num>'.\n");
  if (num_messages == 0) {
    write("There are no messages.\n");
    return;
  }
  write("The board contains " + num_messages);
    if (num_messages == 1)
      write(" note:\n\n");
    else
      write(" notes:\n\n");
  say(this_player()->query_name() + " studies the bulletin board.\n");
  headers();
}

string short() {
  return ("The Guild Bulletin Board");
}

int get() {
  write("It is secured to the ground.\n");
  return 1;
}

void init() {
  add_action("new",    "note");
  add_action("read",   "read");
  add_action("remove", "remove");
}

void reset(int arg) {
  if (arg)
    return;
  restore_object(BOARD_NAME);
}

int new(string hd) {
  if (!hd)
    return 0;
  if (who && environment(who) == environment(this_object())) {
    write(who->query_name() + " is busy writing.\n");
    return 1;
  }
  if (num_messages == 20) {
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

void get_body(string str) {
  if (str == "**") {
    new_hd = new_hd + "(" + this_player()->query_real_name() + ")";
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
 write("]");
 input_to("get_body");
}

int read(string str) {
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
      return 1;
    }
    if (i == 0) {
      say(this_player()->query_name() +  " reads a note titled '" +
          hd + "'.\n");
      write("The note is titled '" + hd + "':\n\n");
      write(body);
      return 1;
    }
  }
  write("Hm. This should not happen.\n");
  return 0;
}

int remove(string str) {
  string hd, body, rest;
  int i, tmp;

  if (this_player()->query_real_name() != "rumplemintz" &&
      this_player()->query_real_name() != "dersharp") {
    write("Only Guild Wizards can remove messages.\n");
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
      return 1;
    }
    if (i == 0) {
      say(this_player()->query_name() + " removed a note titled '" +
          hd + "'.\n");
      write("Ok.\n");
      messages = messages + rest;
      num_messages -= 1;
      save_object(BOARD_NAME);
      return 1;
    }
    messages = messages + hd + ":\n**\n" + body + "\n**\n";
  }
  write("Hm. This should not happen.\n");
  return 0;
}

