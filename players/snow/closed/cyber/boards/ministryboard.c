#define ERROR_LOG "players/snow/closed/cyber/log/BOARDERRORS"
#define BOARD_NAME "players/snow/closed/cyber/boards/ministryboard"

string new_head, new_text, tmp_head, tmp_text;
int msg_num;

static string  messages, headers;
static int line, looked_at;
static object curr_writer;

id(str) {
  return str == "terminal" || str == "term";
}

long() {
  int ind;
  if(!present("implants", this_player())) {
    write("You can't read a single word.  Your language has\n"+
          "become too archaic.  Computer language has taken over.\n");
    return 1; }
  write("This is the Ministry Terminal.\n");
  write("Usage: input <title>, output <entry>\n");
  if(present("implants", this_player())->guild_lev() >= 7)
  write("     : erase <entry>\n");
  if (!msg_num) {
     write("The Terminal is empty.\n");
     return;
     }
  write("The Terminal contains " + msg_num);
  if (msg_num == 1) write(" note :\n\n");
  else write(" notes :\n\n");
  /*
  say(this_player()->query_name() + " accesses the Terminal.\n");
  */
  ind = 0;
  while (ind < msg_num) {
      write(ind + 1 + ":\t" + headers[ind] + "\n");
      ind++;
      }
  return 1;
}

short() {
  return "The Ministry Terminal ("+msg_num+" entries)";
}

get() {
  write("It embedded within the walls.\n");
  return 0;
}

init() {
  add_action("long", "msgs");
  add_action("new_msg", "input");
  add_action("read_msg", "output");
  add_action("new_msg", "post");
  add_action("new_msg", "note");
  add_action("read_msg", "read");
  add_action("remove_msg", "erase");
  if (!looked_at) {
     int i;
     string arr;
     messages = allocate(30);
     headers = allocate(30);
     looked_at = 1;
     if (!restore_object(BOARD_NAME)) return;
     arr = explode(tmp_head, "\n**\n");
     i = 0;
     while(i < sizeof(arr)) {
         headers[i] = arr[i];
         i++;}
     arr = explode(tmp_text, "\n**\n");
     i = 0;
     while(i < sizeof(arr)) {
         messages[i] = arr[i];
         i++;}
     tmp_text = "";
     tmp_head = "";
     }
}

reset(arg) {
   if (arg)
      if (!random(5)) {
         say("The Terminal screen changes colors.\n");
         }
}

new_msg(msg_head) {
  line = 1;
  if (!msg_head) return 0;
  if (curr_writer && environment(curr_writer) ==
      environment(this_object())) {
      write(this_player()->query_name() + " is busy downloading data.\n");
      return 1;}
  if (msg_num == 30) {
      write("You have to erase an old entry first.\n");
      return 1;}
  if (strlen(msg_head) > 50) {
      write("Entry title too long. Try again.\n");
      return 1;}
  curr_writer = this_player();
  say(curr_writer->query_name() + " begins inputting data.\n");
  new_head = msg_head;
  new_text = "";
  input_to("get_msg");
  write("Enter data. End with '**', abort with '~q'.\n");
  write("___________________________________________________\n");
  return 1;
}

get_msg(str) {
  if (str == "~q") {
      say(curr_writer->query_name() + " aborts input.\n");
      write("Entry aborted.\n");
      curr_writer = 0;
      new_head = "";
      new_text = "";
      return;}
  if (str == "**") {
      if (line == 1) {
         write("No data entered. Entry cleared.\n");
         say(curr_writer->query_name() + " terminates input.\n");
         curr_writer = 0;
         new_head = "";
         new_text = "";
         return;}
       say(curr_writer->query_name() + " has completed input : " +
       new_head + "\n");
       headers[msg_num] = new_head + "(" + this_player()->query_real_name() +
            ", " + extract(ctime(time()), 4, 9) +
            ", " + this_player()->query_level() + ")";
            messages[msg_num] = new_text + "\n";
       msg_num++;
       save_board();
       write("Ok.\n");
       curr_writer = 0;
       return;}
  new_text = new_text + str + "\n";
  line++;
  input_to("get_msg");
}

read_msg(what_msg) {
    int note;
    if(!what_msg) { return; }
    if (!sscanf(what_msg, "%d", note))
       if (!sscanf(what_msg, "entry %d", note)) return 0;
    if (note < 1 || note > msg_num) {
       write("Not that many entries.\n");
       return 1;}
    note -= 1;
    /*
    say(this_player()->query_name() + " reads an entry titled '" +
        headers[note] + "'.\n");
    */
    write("The entry is titled '" + headers[note] + "':\n\n");
    write(messages[note]);
    return 1;
}

remove_msg(what_msg) {
   string player, title, date;
   object impob;
   int note, ind;
   if(!present("implants", this_player())) return 0;
   impob = present("implants",this_player());
   if(impob->guild_lev() <= 6) {
     write("Only guild elders may erase data from the Terminal.\n");
     return 1; }
   if (!sscanf(what_msg, "%d", note))
       if (!sscanf(what_msg, "note %d", note)) return 0;
   if (note < 1 || note > msg_num) {
       write("That entry does not exist.\n");
       return 1;}
   note -= 1;
   if (sscanf(headers[note], "%s(%s,%s", title, player, date) != 3) {
       error_log("Header error");
       write("Terminal : error - header corrupt.\n");
       return 1;}
   say(this_player()->query_name() + " erases an entry titled '" +
       headers[note] + "'.\n");
   ind = note;
   while (ind < msg_num - 1) {
         messages[ind] = messages[ind + 1];
         headers[ind] = headers[ind + 1];
         ind++;}
   messages[ind] = 0;
   headers[ind] = 0;
   msg_num -= 1;
   save_board();
   write("Ok.\n");
   return 1;
}

save_board() {
   int ind;
   ind = 1;
   tmp_head = implode(headers, "\n**\n") + "\n**\n";
   tmp_text = implode(messages, "\n**\n") + "\n**\n";
   save_object(BOARD_NAME);
   tmp_head = "";
   tmp_text = "";
   return 1;
}

error_log(str) {
   tell_room(environment(this_object()), "Terminal says '" + str + "'.\n");
   log_file(ERROR_LOG, "Terminal : " + str);
   return;
}
