/** Jaraxle's Poem Board - Adjust Templar board for this. */
#include "/players/maledicta/ansi.h"
#define ERROR_LOG "/log/BOARD"
#define BOARD_NAME "players/guilds/bards/boards/storyboard"
#define TP this_player()
int chapter;
string new_head, new_text, tmp_head, tmp_text;
int msg_num;
int dates;

static string  messages, headers;
static int line, looked_at;
static object curr_writer;

id(str) {
   return str == "book" || str == "book_board";
}

short(){ return "Book of Stories"; }

chapter(str){
   int numero;
   if(sscanf(str, "%d", numero) != 1){
      write("Chapter 1-50\n");
      return 1;
   }
   if(numero > 50){
      write("Chapter 1-50\n");
      return 1;
   }
   if(numero < 1){
      write("Chapter 1-50\n");
      return 1;
   }
   if(numero == chapter){
      write("You are already on that page.\n");
      return 1;
   }
   write("You turn through the pages of the book...\n");
   say(TP->query_name()+" turns through the pages of the book.\n");
   save_board();
   chapter = numero;
   new_head = 0; 
   new_text = 0;
   tmp_head = 0;
   tmp_text = 0;
   msg_num = 0;
   dates = 0;

   messages = 0; 
   headers = 0;
   line = 0;
   looked_at = 0;
   curr_writer = 0;

   restore_object(BOARD_NAME+chapter);
   save_board();
   return 1;
}

long() {
   int ind;
   write(HIM+"              CHAPTER "+chapter+"\n"+NORM);
   write("In this book a Bard may write down their greatest stories.\n");
   write("You have the full use of each chapter, allowing for up to\n"+
      "70 pages.  To write your work, find a chapter that has no\n"+
      "writing in it, then begin writing each page.\n\n");
   write("write <story title> \n");
   write("read <page number>\n");
   write("chapter <chapter number>\n");
   if(TP->query_level() > 19){
      write("As a wizard, you may remove <page number> and \n"+
         "store <page number> <filepath>.\n");
   }
   if (!msg_num) {
      write("This chapter is empty.\n");
      return;
   }
   write("The book contains " + msg_num);
   if (msg_num == 1)
      write(" story :\n\n");
   else 
      write(" stories :\n\n");
   
   say(this_player()->query_name() + " studies the book.\n");
   
   ind = 0;
   while (ind < msg_num) {
      write("["+ (ind + 1) + "]\t" + headers[ind] + "\n");
      ind++;
   }
   return 1;
}

get() {
   write("It is attached to the floor!\n");
   return 0;
}

init() {
   if(!environment()) return;
   if(!this_player()) return; /* verte */
   if(!present("bard_obj", this_player())) return;
   add_action("long", "msgs");
   add_action("chapter", "chapter");
   if(present("bard_obj", this_player())->query_bard_level() >= 8)
      add_action("new_msg", "write");
   add_action("read_msg", "read");
   if(TP->query_level() > 19){
      add_action("remove_msg", "remove");
      add_action("move_msg", "move");
      add_action("store_msg", "store");
   }
   if (!looked_at) {
      int i;
      string arr;
      messages = allocate(50);
      headers = allocate(50);
      dates = allocate(50);
      looked_at = 1;
      if (!restore_object(BOARD_NAME+chapter))
         return;
      arr = explode(tmp_head, "\n**\n");
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
   if (arg) return;
   chapter = 1;
}

new_msg(msg_head) {
   string title, player, date;
   line = 1;
   if (!msg_head)
      return (notify_fail("What do you want the title to be?\n"), 0);
   if (curr_writer && environment(curr_writer) ==
         environment(this_object())) {
      write(this_player()->query_name() + " is busy writing a masterpiece.\n");
      return 1;
   }
   if (msg_num == 70) {
      write("This chapter is full.\n");
      return 1;
   }
   if (strlen(msg_head) > 30) {
      write("Story title is too long. 30 characters max.\n");
      return 1;
   }
   curr_writer = this_player();
   say(curr_writer->query_name() + " starts writing a story.\n");
   new_head = msg_head;
   new_text = "";
   input_to("get_msg");
   write("Enter story text. End with '**', abort with '~q'.\n");
   write("1>>");
   return 1;
}

get_msg(str) {
   if (str == "~q") {
      say(curr_writer->query_name() + " aborts writing a story.\n");
      write("Note aborted.\n");
      curr_writer = 0;
      new_head = "";
      new_text = "";
      return;
   }
   if (str == "**") {
      if (line == 1) {
         write("No text entered. story discarded.\n");
         say(curr_writer->query_name() + " quits writing.\n");
         curr_writer = 0;
         new_head = "";
         new_text = "";
         return;
       }
      say(curr_writer->query_name() + " has completed a story titled,\"" +
         new_head + "\"\n");
      headers[msg_num] = new_head + "(" + this_player()->query_real_name() +
      ", " + extract(ctime(time()), 4, 9) +
      ", " + this_player()->query_level() + ")";
      messages[msg_num] = new_text + "\n";
      dates[msg_num] = time();
      msg_num++;
      save_board();
      write("Ok.\n");
      curr_writer = 0;
      return;
   }
   new_text = new_text + str + "\n";
   line++;
   write(line + ">>");
   input_to("get_msg");
}

read_msg(what_msg) {
   int note;
   if(!what_msg) return 0;
   if (!sscanf(what_msg, "%d", note))
      if (!sscanf(what_msg, "note %d", note))
      return 0;
   if (note < 1 || note > msg_num) {
      write("Not that many stories.\n");
      return 1;
   }
   note -= 1;
   
   say(this_player()->query_name() + " reads a story entitled, '" +
      headers[note] + "'.\n");
   
   write("The story is entitled, '" + headers[note] + "':\n\n");
   write(messages[note]);
   return 1;
}

remove_msg(what_msg) {
   string player, title, date;
   int note, ind,tim;
   if (!sscanf(what_msg, "%d", note)) 
      if (!sscanf(what_msg, "note %d", note))
      return 0;
   if (note < 1 || note > msg_num) {
      write("That story doesn't exist.\n");
      return 1;
   }
   note -= 1;
   if (sscanf(headers[note], "%s(%s,%s", title, player, date) != 3) {
      error_log("Header error");
      write("Book : error - header corrupt.\n");
      return 1;
   }
   if ((this_player()->query_real_name() != player &&
            this_player()->query_level() < 20) ||
      !query_ip_number(this_player())) {
      write("Only GCs may remove other people's notes.\n");
      say(this_player()->query_name() + " failed to remove " +
         "a story.\n");
      return 1;
   }
   
   say(this_player()->query_name() + " removes a story entitled '" +
      headers[note] + "'.\n");
   ind = note;
   while (ind < msg_num - 1) {
      messages[ind] = messages[ind + 1];
      headers[ind] = headers[ind + 1];
      dates[ind] = dates[ind + 1];
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
   if (!str) 
      return 0;
   if (sscanf(str, "%d %s", note, file) != 2)
      if (sscanf(str, "note %d %s", note, file) != 2)
      return 0;
   if (note < 1 || note > msg_num) {
      write("That message doesn't exist.\n");
      return 1;
   }
   note -= 1;
   file = file + ".note";
   write_file(file, headers[note] + "\n" + messages[note] + "\n");
   return 1;
}

save_board() {
   int ind;
   ind = 1;
   tmp_head = implode(headers, "\n**\n") + "\n**\n";
   tmp_text = implode(messages, "\n**\n") + "\n**\n";
   save_object(BOARD_NAME+chapter);
   tmp_head = "";
   tmp_text = "";
   return 1;
}


error_log(str) {
   tell_room(environment(this_object()), "Book says '" + str + "'.\n");
   log_file(ERROR_LOG, "Board : " + str);
   return;
}

move_msg(what_msg) {
   string player, title, date, movemesg;
   object oboard;
   int note, ind;
   if (!sscanf(what_msg, "%d", note)) 
      if (!sscanf(what_msg, "note %d", note))
      return 0;
   if (note < 1 || note > msg_num) {
      write("That message doesn't exist.\n");
      return 1;
   }
   note -= 1;
   if (sscanf(headers[note], "%s(%s,%s", title, player, date) != 3) {
      error_log("Header error");
      write("Board : error - header corrupt.\n");
      return 1;
   }
   if ((this_player()->query_name() != player &&
            this_player()->query_level() < 24) ||
      !query_ip_number(this_player())) {
      write("Only Archwizards may move other wizard's notes.\n");
      say(this_player()->query_name() + " failed to move " +
         "a note.\n");
      return 1;
   }
   say(this_player()->query_name() + " moved a note titled '" +
      headers[note] + "'.\n");
   ind = note;
   movemesg = headers[ind] + "\n**\n"  + messages[ind] + "\n**\n";
   while (ind < msg_num - 1) {
      messages[ind] = messages[ind + 1];
      headers[ind] = headers[ind + 1];
      ind++;
   }
   messages[ind] = 0;
   headers[ind] = 0;
   msg_num -= 1;
   save_board();
   write("Ok.\n");
   return 1;
}
