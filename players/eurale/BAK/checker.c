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

id(str) { return str == "checker"; }

get() { return 1; }

init() {
  add_action("Mcheck","mchecker");
  add_action("read", "read");
  add_action("setfi", "sf");
  add_action("headers", "from");
  add_action("Gone","dm");
}

Mcheck() { write(
  "  MCHECKER:\n\n"+
  "  sf <name>  -  set mail to <name>\n"+
  "  read       -  read mail of <name>\n"+
  "  from       -  lists messages by title\n"+
  "  x          -  exit from mail checker\n"+
  "  dm         -  destruct the mail checker\n");
  return 1; }

Gone() {
  write("Destructing mail checker.....\n");
  destruct(this_object());
  return 1; }

read() {
 is_reading = 1;
 if(!loaded) {
   load_player();
   if(arr_messages == 0) { write("No mail.\n"); return 1; }
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
  if(!loaded) load_player();
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
   if (!loaded) {
      load_player();
      new_has_arrived = 1;
   }
   if (str == "n") { curr_mess++; print_message(); loop(); return; }
   if (sscanf(str, "%d", n) == 1) {
      curr_mess = n; print_message(); loop(); return;
   }
   if (str == "x") { is_reading = 0; return; }
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


setfi(str){
    nom = str;
    load_player();
    write("Now set to " + NAME + nom + "\n");
    return 1;
   }
