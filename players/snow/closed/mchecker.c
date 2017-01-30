#define NAME "post_dir/"

string nom;
string messages;/* The big string of all messages. */
string thingone,thingtwo;
int new_mail;/* Flag if there is any new mail. */
   
static string arr_messages;/* the result of explode on 'messages' */
static int loaded;/* Flag if this users mailbox is loaded */
   static int curr_mess;/* Current message number */
static string new_message, new_subject, new_dest, new_cc;

static int is_reading;

id(str) {
   return str == "mailread";
}


get() {
   return 1;
}

init() {
  add_action("mchecker_help","mchecker");
   add_action("read", "read");
   add_action("setfi", "sf");
   add_action("mail_to", "mail");
   add_action("headers", "from");
   add_action("dm","dm");
}

mchecker_help() {
  write("This is a player mail checker.  Use the following commands:\n"+
        "   sf <name>  -  to get into a players mailbox\n"+
        "   read       -  to read mail like normal\n"+
        "   x          -  to exit the mail reader\n"+
        "   dm         -  to destruct the mail reader\n");
  return 1; }

dm() {
  write("Okay, destructing the mail checker!\n");
  destruct(this_object());
  return 1; }

read() {
   is_reading = 1;
   if (!loaded) {
      load_player();
      if (arr_messages == 0) {
         write("No mail.\n");
         return 1;
       }
   }
   loop();
   return 1;
}

load_player() {
   loaded = 1;
   if(!restore_object(NAME + nom) ||
         messages == "" || messages == 0) {
      arr_messages = 0;
      messages = "";
      return;
   }
   if (new_mail) {
      new_mail = 0;
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
      is_reading = 0;
      return;
   }
   if (curr_mess < 1 || curr_mess > sizeof(arr_messages)/2)
      tmp = " (no current) ";
   else
      tmp = " (current: " + curr_mess + ") ";
   write("[1 - " + (sizeof(arr_messages)/2) + " h l d r x q ?]" + tmp);
   input_to("get_cmd");
}

get_cmd(str) {
   int n, new_has_arrived;
   string tmp;
   
   /*
   * First, test all nondestructive commands. The destructive commands
   * will be tested after check if new mail has arrived.
      */
   if (!loaded) {
      load_player();
      new_has_arrived = 1;
   }
   if (str == "r") { reply_to_message(); return; }
   if (sscanf(str, "r %d", curr_mess) == 1) { reply_to_message(); return; }
   if (str == "h") { headers(); loop(); return; }
   if (str == "n") { curr_mess++; print_message(); loop(); return; }
   if (str == ".") { print_message(); loop(); return; }
   if (str == "l") { save_message(); loop(); return; }
   if (sscanf(str, "m %s", tmp) == 1) { mail_to(tmp); return; }
   if (str == "?") { help_msg(); loop(); return; }
   if (str == "p" || str == "-") {
      curr_mess--; print_message(); loop(); return;
   }
   if (sscanf(str, "%d", n) == 1) {
      curr_mess = n; print_message(); loop(); return;
   }
   if (new_has_arrived) {
      write("New mail has arrived. Command ignored\n");
      loop();
      return;
   }
   if (str == "x") { is_reading = 0; return; }
   if (str == "d") { delete(); loop(); return; }
   if (str == "q") { check_delete_all(); return; }
   if (sscanf(str, "d %d", curr_mess) == 1) { delete(); loop(); return; }
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

save_message() {
   string name;
   
   if (curr_mess > sizeof(arr_messages)/2 || curr_mess < 1) {
      write("Illegal message number " + curr_mess + "\n");
      return;
   }
   name = this_player()->query_real_name() + ".mbox";
   log_file(name, "From: " + arr_messages[curr_mess*2-2] + "\n");
   log_file(name, arr_messages[curr_mess*2-1] + "\n");
}

delete() {
   if (curr_mess > sizeof(arr_messages)/2 || curr_mess < 1) {
      write("Illegal message number " + curr_mess + "\n");
      return;
   }
   arr_messages = remove_element(arr_messages, curr_mess*2 - 2);
   arr_messages = remove_element(arr_messages, curr_mess * 2 - 2);
   if (sizeof(arr_messages) < 2)
      messages = "";
   else
      messages = implode(arr_messages, "\n**\n") + "\n**\n";
   new_mail = 0;
   if (messages == "")
      arr_messages = 0;
   else
      arr_messages = explode(messages, "\n**\n");
}

mail_to(str) {
   if (!str || str == "") {
      write("No destination.\n");
      if (is_reading)
         loop();
      return 1;
   }
   new_subject = 0;
   new_cc = "";
   mail_to_continue(str);
   return 1;
}

mail_to_continue(str) {
   str = lower_case(str);
   if (!restore_object("players/" + str)) {
      write("No such player.\n");
      if (is_reading)
         loop();
      return 1;
   }
   new_dest = str;
   new_message = "";
   if (new_subject)
      write("Return to get '" + new_subject + "'\n");
   write("Subject: ");
   input_to("get_subject");
   return 1;
}

get_subject(str) {
   if (str && str != "")
      new_subject = "Subj: " + str + "\n";
   if (new_subject == 0) {
      write("No subject.\n");
      if (is_reading)
         loop();
      return;
   }
   write("Give message.  Finish message with '**', or '~q' to cancel\n");
   write("]");
   input_to("more_mail");
   return;
}

more_mail(str) {
   if (str == "~q") {
      write("Aborted.\n");
      if (is_reading)
         loop();
      return;
   }
   if (str == "**") {
      write("Cc:");
      input_to("get_cc");
      return;
   }
   new_message += str + "\n";
   write("]");
   input_to("more_mail");
}

get_cc(cc) {
   int n;
   object ob;
   string cc2, next_pern;
   
  if (sscanf(cc, "%s/%s", thingone,thingtwo) == 2) {
        write("Not a legal name, no carbon copy sent.\n");
log_file("BAD_PLAYER", ctime(time()) + " " + this_player()->query_real_name() + " with mail_reader, file " + cc + "\n");
        cc = "";
        }
   send_mail(new_dest, new_subject + "\n", new_message, cc);
   if (cc && cc != "") {
      cc2 = cc;
      cc = lower_case(cc2);
      cc2 = "(To: " + new_dest + ") " + cc;
      while (cc != "") {
         n = sscanf(cc,"%s,%s",next_pern,cc);
         if (n == 0) {
            next_pern = cc; /* cc held remaining line; do last person. */
            cc = "";         /* set cc to "" to leave loop after this    */
         }
         send_mail(next_pern, new_subject + "\n", new_message, cc2);
       }
   }
   if (is_reading)
      loop();
}

/*
* Send a complete mail. If the receiver is reading mail, be sure to
* tell his mail reader that new mail has arrived.
*/
send_mail(dest, subj, mess, cc) {
   if (cc != "")
      cc = "Cc: " + cc + "\n";
   notify_new_mail(dest, subj, this_player()->query_real_name());
   messages = "";
   restore_object(NAME + dest);
   if (messages == 0)
      messages = "";
   messages += this_player()->query_real_name() + "\n**\n" + subj + cc +
   "Date: " + extract(ctime(time()), 4, 9) + "\n\n" + mess + "\n**\n";
   new_mail = 1;
   save_object(NAME + dest);
}

notify_new_mail(dest, subj, name) {
   object ob;
   if (ob = find_player(dest)) {
      tell_object(ob,"You have new mail from " +
         name + ", " + subj + "\n");
      ob = present("mailread", ob);
      if (ob)
         ob->invalidate();
   }
   write("Sending mail to " + capitalize(dest) + ".\n");
}

invalidate() {
   loaded = 0;
}

drop() {
   return 1;
}

reply_to_message() {
   int n;
   string tmp_str, tmp_str2, rest_of_mess;
   string name;
   
   name = lower_case(arr_messages[curr_mess*2-2]);
   n = sscanf(arr_messages[curr_mess*2-1],"%sRe:   %s\n%s",
      tmp_str,tmp_str2,rest_of_mess);
   new_subject = " Re:   " + tmp_str2;
   n = sscanf(arr_messages[curr_mess*2-1],"%sSubj: %s\n%s",
      tmp_str,tmp_str2,rest_of_mess);
   new_subject = " Re:   " + tmp_str2;
   new_cc = "";
   mail_to_continue(name);
}

help_msg() {
   write("x	Exit from mail reading mode.\n");
   write("d	Delete current message.\n");
   write("d <num>	Delete message number 'num'.\n");
   write("?	This help message.\n");
   write("r	Reply to current message.\n");
   write("r <num>	Reply to message number 'num'.\n");
   write("m <name> Mail a message to player 'name'.\n");
   write("h	Print all headers.\n");
   write("p	Print previous message.\n");
   write("n	Print next message.\n");
   write("l	Append current message to /log/name.mbox\n");
   write("q   Quit and ask if messages should be erased.\n");
   return 1;
}

check_delete_all() {
   write("Okay to delete all mail? ");
   input_to("check_delete_all2");
}

check_delete_all2(str) {
   if (str == "y" || str == "Y") {
      messages = 0;
      arr_messages = 0;
   }
   return 1;
}

remove_element(old_array, element) {
   string new_array;
   int index;
   
   new_array = allocate(sizeof(old_array) - 1);
   index = 0;
   while (index < element) {
      new_array[index] = old_array[index];
      index++;
   }
   index = element + 1;
   while (index < sizeof(old_array)) {
      new_array[index - 1] = old_array[index];
      index++;
   }
   return new_array;
}
/*
    fix for deleteing messages while running 3.0 from shadowhawk
    fix to stop blanking out of files from boltar.
*/
setfi(str){
    nom = str;
    load_player();
    write("Now set to " + NAME + nom + "\n");
    return 1;
   }
