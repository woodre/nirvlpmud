
#define ERROR_LOG "/players/saber/closed/bard/log/BOARD"
#define BOARD_NAME "players/saber/closed/bard/log/bardnotes"

string tmp_head, tmp_text;
int msg_num;

static string new_head, new_text; 
static string messages, headers;
static int line, looked_at;
static object curr_writer;

id(str) { return str == "book" || str == "large book"; }

long() {
   int ind;
   write("This is a large book with many pages full of notes.\n");
   write("Usage: note <headline>, read/remove <message number>\n");
   if(this_player()->query_level() > 20)
     write("        store <message number> <file name>\n");
   if(!msg_num) {
     write("The book is empty.\n");
     return;
   }
   write("The large book contains "+msg_num);
   if(msg_num == 1)
     write(" note:\n\n");
   else 
     write(" notes:\n\n");
   ind = 0;
   while(ind < msg_num) {
     write(ind+1+":\t"+headers[ind]+"\n");
     ind++;
   }
   return 1;
}

short() { 
   string msg;
   if(msg_num == 0) msg = "No messages";
   if(msg_num == 1) msg = "1 message";
   if(msg_num > 1)  msg = msg_num+" messages";
   return "A large silver bound book ("+msg+")"; 
}

get() {
  write("It is firmly secured to the table.\n");
  return 0;
}

init() {
   add_action("new_msg", "note");
   add_action("read_msg", "read");
   add_action("remove_msg", "remove");
   add_action("store_msg", "store");
   if(!looked_at) {
     int i;
     string arr;
     messages = allocate(30);
     headers = allocate(30);
     looked_at = 1;
     if(!restore_object(BOARD_NAME))
       return;
     arr = explode(tmp_head, "\n**\n");
     if(!arr)
       return 1;
     i = 0;
     while(i < sizeof(arr)) {
       headers[i] = arr[i];
       i++;
     }
     arr = explode(tmp_text, "\n**\n");
     i = 0;
     while(i < sizeof(arr)) {
       messages[i] = arr[i];
       i++;
     }
     tmp_text = "";
     tmp_head = "";
   }
}

reset(arg) {
   if(arg)
     if(!random(4)) {
       say("Laura wanders in and opens the silver bound book.\n");
       say("Smiling to herself, Laura leaves west.\n");
     }
}

new_msg(msg_head) {
   line = 1;
   if(!msg_head)
     return 0;
   if(curr_writer && environment(curr_writer) == environment(this_object())){
     write(capitalize(this_player()->query_name())+" is busy writing.\n");
     return 1;
   }
   if(msg_num == 32) {
     write("You have to remove an old message first.\n");
     return 1;
   }
   if(strlen(msg_head) > 50) {
     write("Message header too long. Try again.\n");
     return 1;
   }
   curr_writer = this_player();
   say(capitalize(curr_writer->query_name())+" starts writing a note in the book.\n");
   new_head = msg_head;
   new_text = "";
   input_to("get_msg");
   write("Enter message text. End with '**', abort with '~q'.\n");
   write("1>>");
   return 1;
}

get_msg(str) {
   if(str == "~q") {
     say(capitalize(curr_writer->query_name())+" aborts writing a note.\n");
     write("Note aborted.\n");
     curr_writer = 0;
     new_head = "";
     new_text = "";
     return;
   }
   if(str == "**") {
     if(line == 1) {
       write("No text entered. Message discarded.\n");
       say(capitalize(curr_writer->query_name())+" quits writing.\n");
       curr_writer = 0;
       new_head = "";
       new_text = "";
       return;
     }
     say(capitalize(curr_writer->query_name())+" has completed a note: "+
                        new_head+"\n");
     headers[msg_num] = new_head+"("+
            capitalize(this_player()->query_real_name())+", "+
            extract(ctime(time()), 4, 9)+")";
     messages[msg_num] = new_text+"\n";
     msg_num++;
     save_board();
     write("Ok.\n");
     curr_writer = 0;
     return;
   }
   new_text = new_text+str+"\n";
   line++;
   write(line+">>");
   input_to("get_msg");
}

read_msg(what_msg) {
   int note;
   if(!what_msg)
     return 0;
   if(!sscanf(what_msg, "%d", note))
     if(!sscanf(what_msg, "note %d", note))
       return 0;
   if(note < 1 || note > msg_num) {
     write("Not that many messages.\n");
     return 1;
   }
   note -= 1;
   write("The note is titled '"+headers[note]+"':\n\n");
   write(messages[note]);
   return 1;
}

remove_msg(what_msg) {
   string player, title, date;
   int note, ind;
   if(!what_msg)
     return 0;
   if(!sscanf(what_msg, "%d", note)) 
     if(!sscanf(what_msg, "note %d", note))
       return 0;
   if(note < 1 || note > msg_num) {
     write("That message doesn't exist.\n");
     return 1;
   }
   note -= 1;
   if(sscanf(headers[note], "%s(%s,%s", title, player, date) != 3) {
     error_log("Header error");
     write("Board : error - header corrupt.\n");
     return 1;
   }
   if((this_player()->query_real_name() != lower_case(player) &&
     this_player()->query_level() < 24) || !query_ip_number(this_player())) {
     write("Only Archwizards may remove other player's notes.\n");
     say(capitalize(this_player()->query_name())+
                                   " failed to remove a note.\n");
     return 1;
   }
   say(capitalize(this_player()->query_name())+" removes a note titled '"+
       headers[note]+"'.\n");
   ind = note;
   while(ind < msg_num - 1) {
     messages[ind] = messages[ind+1];
     headers[ind] = headers[ind+1];
     ind++;
   }
   messages[ind] = 0;
   headers[ind] = 0;
   msg_num -= 1;
   save_board();
   write("Ok.\n");
   return 1;
}

store_msg(str) {
   int note;
   string file;
   if(!str) 
     return 0;
   if(sscanf(str, "%d %s", note, file) != 2)
     if(sscanf(str, "note %d %s", note, file) != 2)
       return 0;
   if(note < 1 || note > msg_num) {
     write("That message doesn't exist.\n");
     return 1;
   }
   note -= 1;
   file = file+".note";
   write_file(file, headers[note]+"\n"+messages[note]+"\n");
   write("Ok.\n");
   return 1;
}

save_board() {
   int ind;
   ind = 1;
   tmp_head = implode(headers, "\n**\n")+"\n**\n";
   tmp_text = implode(messages, "\n**\n")+"\n**\n";
   save_object(BOARD_NAME);
   tmp_head = "";
   tmp_text = "";
   return 1;
}


error_log(str) {
   tell_room(environment(this_object()), "Board says '"+str+"'.\n");
   log_file(ERROR_LOG, "Board: "+str);
   return;
}

