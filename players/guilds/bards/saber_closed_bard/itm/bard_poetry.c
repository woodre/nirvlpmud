
#define ERROR_LOG "/players/saber/closed/bard/log/BOARD"
#define BOARD_NAME "players/saber/closed/bard/log/bardpoetry"

string tmp_head, tmp_text;
int msg_num;

static string new_head, new_text; 
static string messages, headers;
static int line, looked_at;
static object curr_writer;

id(str) { return str == "journal" || str == "bound journal"; }

long() {
   int ind;
  write("This is a journal, bound with runes of silver.\n");
   write("Usage: poetry <headline>, skim/delete <message number>\n");
   if(this_player()->query_level() > 20)
     write("        store <message number> <file name>\n");
   if(!msg_num) {
     write("The journal is empty.\n");
     return;
   }
   write("The large journal contains "+msg_num);
   if(msg_num == 1)
     write(" poetry:\n\n");
   else 
     write(" poetrys:\n\n");
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
   return "A journal with silver runes ("+msg+")"; 
}

get() {
  write("It is firmly secured to the table.\n");
  return 0;
}

init() {
   add_action("new_msg", "poetry");
   add_action("skim_msg", "skim");
   add_action("delete_msg", "delete");
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
       say("Tuyen wanders in and looks at the journal.\n");
       say("Whistling softly, Tuyen leaves east.\n");
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
   if(msg_num == 30) {
     write("You have to delete an old message first.\n");
     return 1;
   }
   if(strlen(msg_head) > 50) {
     write("Message header too long. Try again.\n");
     return 1;
   }
   curr_writer = this_player();
   say(capitalize(curr_writer->query_name())+" starts writing a poetry in the book.\n");
   new_head = msg_head;
   new_text = "";
   input_to("get_msg");
   write("Enter message text. End with '**', abort with '~q'.\n");
   write("1>>");
   return 1;
}

get_msg(str) {
   if(str == "~q") {
     say(capitalize(curr_writer->query_name())+" aborts writing a poetry.\n");
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
     say(capitalize(curr_writer->query_name())+" has completed a poetry: "+
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

skim_msg(what_msg) {
   int poetry;
   if(!what_msg)
     return 0;
   if(!sscanf(what_msg, "%d", poetry))
     if(!sscanf(what_msg, "poetry %d", poetry))
       return 0;
   if(poetry < 1 || poetry > msg_num) {
     write("Not that many messages.\n");
     return 1;
   }
   poetry -= 1;
   write("The poetry is titled '"+headers[poetry]+"':\n\n");
   write(messages[poetry]);
   return 1;
}

delete_msg(what_msg) {
   string player, title, date;
   int poetry, ind;
   if(!what_msg)
     return 0;
   if(!sscanf(what_msg, "%d", poetry)) 
     if(!sscanf(what_msg, "poetry %d", poetry))
       return 0;
   if(poetry < 1 || poetry > msg_num) {
     write("That message doesn't exist.\n");
     return 1;
   }
   poetry -= 1;
   if(sscanf(headers[poetry], "%s(%s,%s", title, player, date) != 3) {
     error_log("Header error");
     write("Board : error - header corrupt.\n");
     return 1;
   }
   if((this_player()->query_real_name() != lower_case(player) &&
     this_player()->query_level() < 24) || !query_ip_number(this_player())) {
     write("Only Archwizards may delete other player's poetrys.\n");
     say(capitalize(this_player()->query_name())+
                                   " failed to delete a poetry.\n");
     return 1;
   }
   say(capitalize(this_player()->query_name())+" deletes a poetry titled '"+
       headers[poetry]+"'.\n");
   ind = poetry;
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
   int poetry;
   string file;
   if(!str) 
     return 0;
   if(sscanf(str, "%d %s", poetry, file) != 2)
     if(sscanf(str, "poetry %d %s", poetry, file) != 2)
       return 0;
   if(poetry < 1 || poetry > msg_num) {
     write("That message doesn't exist.\n");
     return 1;
   }
   poetry -= 1;
   file = file+".poetry";
   write_file(file, headers[poetry]+"\n"+messages[poetry]+"\n");
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

