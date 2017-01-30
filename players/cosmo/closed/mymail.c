#define NAME "post_dir/"

string messages; /* The big string of all messages. */
static string arr_messages; /* the result of explode on 'messages' */
static int loaded; /* Flag if this users mailbox is loaded */
static int curr_mess; /* Current message number */
static string plyr; /* Name of character */

id(str) { return str == "reader"; }
get() { return 1; }
drop() { return 1; }

init() {
   add_action("read", "read");
   add_action("headers", "from");
}

read(string plyr) {
   if (!loaded) {
      load_player(plyr);
      if (arr_messages == 0) {
         write("No mail.\n");
         loaded = 0;
         return 1;
       }
   }
   loop();
   return 1;
}

load_player(string plyr) {
   loaded = 1;
   if (!restore_object(NAME + plyr) ||
         messages == "" || messages == 0) {
      arr_messages = 0;
      messages = "";
      return;
   }
   arr_messages = explode(messages, "\n**\n");
}

headers() {
   int i, n;
   string tmp_str, tmp_str2, rest_of_mess;
   string name;
   
   if (!loaded)
      load_player();
   if (arr_messages == 0) {
      write("No mail.\n");
      loaded = 0;
      return 1;
   }
   for (i=0; i<sizeof(arr_messages); i+=2) {
      name = i/2+1 + " " + arr_messages[i];
      if (strlen(name) < 8)
         name += "\t";
      write(name + "\t");
      n = sscanf(arr_messages[i+1],"%sRe:   %s\n%s",
         tmp_str,tmp_str2,rest_of_mess);
      if (n == 3) write(" Re:   " + tmp_str2);
      n = sscanf(arr_messages[i+1],"%sSubj: %s\n%s",
         tmp_str,tmp_str2,rest_of_mess);
      if (n == 3) write(" Subj: " + tmp_str2);
      n = sscanf(arr_messages[i+1],"%sDate: %s\n%s",
         tmp_str,tmp_str2, rest_of_mess);
      if (n == 3) write(" Date: " + tmp_str2);
      write("\n");
   }
   return 1;
}

loop() {
   string tmp;
   
   if (!loaded)
      load_player();
   if (arr_messages == 0) {
      write("No messages.\n");
      loaded = 0;
      return;
   }
   if (curr_mess < 1 || curr_mess > sizeof(arr_messages)/2)
      tmp = " (no current) ";
   else
      tmp = " (current: " + curr_mess + ") ";
   write("[1 - " + (sizeof(arr_messages)/2) + " h n p x . ?]" + tmp);
   input_to("get_cmd");
}

get_cmd(str) {
   int n;
   string tmp;
   
   if (!loaded) {
      load_player();
   }
   if (str == "h") { headers(); loop(); return; }
   if (str == "n") { curr_mess++; print_message(); loop(); return; }
   if (str == ".") { print_message(); loop(); return; }
   if (str == "?") { help_msg(); loop(); return; }
   if (str == "p" || str == "-") {
      curr_mess--; print_message(); loop(); return;
   }
   if (sscanf(str, "%d", n) == 1) {
      curr_mess = n; print_message(); loop(); return;
   }
   if (str == "x") { loaded = 0; return; }
   loop();
}

print_message() {
   if (curr_mess > sizeof(arr_messages)/2 || curr_mess < 1) {
      write("Illegal message number " + curr_mess + "\n");
      return;
   }
   write("Message " + curr_mess + ":\n");
   write("From: " + arr_messages[curr_mess*2-2] + "\n");
   write(arr_messages[curr_mess*2-1] + "\n");
}

help_msg() {
   write("x     Exit from mail reading mode.\n");
   write("?     This help message.\n");
   write("h     Print all headers.\n");
   write("p     Print previous message.\n");
   write("n     Print next message.\n");
   return 1;
}
