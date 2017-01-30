/* 
   This is a wiz board with a paging system
   The paging system utilizes the mailing system
   by simply mailing the player whether they have
   any unread msgs on this board.
   Once any of the 'unread' msgs are read by the 
   player, next boot (i.e. next clone) the paging 
   system mails the player and informs of any 
   unread msgs.
   - Mythos <12-6-96>
*/

/* yeah yeah, so im a tad redundant - mythos */

#define tp this_player()
#define tpn tp->query_real_name()
#define tl tp->query_level()
#define to this_object()
#define eo environment(to)
#define SAVE "closed/swizmsg"
string active;
string msg,sub,who;
static mess, subject;

id(str) {  return str == "swiz_board" || 
                  str == "board"; }

short() { if(check(tp)) return 0; 
          return "Senior Wiz Board"; }

drop() { return 0; }

get() { return 0; }

reset(arg) {
  if(arg)return;
  if(!restore(SAVE)) {
    active = ({"boltar","mythos","arrina","wizardchild",
               "pain"});
    save_object(SAVE);
  }
  mess = 0;
  subject = 0;
}

long() {
  if(check(tp)) write("");
  else 
  write("Senior Wiz Board\n"+
        "");
}

init() {
  if(check(tp)) {
   if(eo == tp) destruct(to);
  return 1; }
  add_action("note","note");
  add_action("read","read");
  add_action("erase","erase");
}

check(ob) { 
  if(member_array(ob->query_real_name(),active) == -1 ||
     member_array(ob,users()) == -1 ||
     !ob->is_player() || ob->query_level() < 100) return 1;
return 0; }

add_mem(str) {
int h;
  if(check(tp)) return 0;
  if(!find_player(str)) {
   write("That person is not on.\n");
   return 1; }
  if(find_player(str)->query_level() < 100) {
    write("That player is not level 100.\n");
  return 1; }
  active += ({lower_case(str)});
  h =0;
  while(h<sizeof(who)) { who[h] = who[h] * 10; h++; }
  save_object(SAVE);
  write(str+" may now access the senior board.\n");
return 1; }

read(str) {
int n;
  if(!str) return 0;
  if(check(tp)) return 0;
  sscanf(str,"%d",n);
  if(n < 1 || n > sizeof(sub)) {
   write("Not that many messeges.\n");
  return 1; }
  write(sub[n - 1]);
  write("\n");
  write(msg[n - 1]);
  write("\n");
return 1; }

note(str) { 
if(!str) return 0;
if(check(tp)) return 0;
subject = str + " <"+ctime(time())+">";
mess = "";
write("Start note:\n>< ");
input_to("writeto");
return 1; }

writeto(str) {
  if(check(tp)) return 0;
  if(str == "**") {
      write("Note End.\n"+
            "Do you wish to review the note? <y/n>\n");
  input_to("rev");
  return 1; }
  if(str == "~q") {
    write("Note Aborted.\n");
  return 1; }
  if(str == "") mess += "\n";
  mess += str;
  write(">< ");
input_to("writeto");
return 1; }

rev(str) {
  if(!str) {
    write("Do you wish to review the note? <y/n>\n");
    input_to("rev");
  return 1; }
  if(str == "y" || str == "Y" || str == "yes" || 
     str == "YES") {
     write(mess);
   write("\nIs this ok?\n"+
         "note: to format the msg cleanly type Y\n"+
         "otherwise 'y' for ok 'n' for abort\nresponse: ");
    input_to("res");
  return 1; }
  if(str == "N" || str == "n" || str == "no" ||
     str == "NO") {
    complete();
  return 1; }
}

res(str) {
  if(!str) {
    write("\nIs this ok?\n"+
         "note: to format the msg cleanly type 'Y'\n"+
         "otherwise 'y' for ok 'n' for abort\nresponse: ");
    input_to("res");
  return 1; }
  if(str == "n") { write("Note aborted.\n"); return 1; }
  if(str == "y" || str == "Y") {
    if(str == "Y") mess = format(mess,60);
    complete();
  return 1; }
}

complete() {
int h,i;
  msg += ({mess});
  sub += ({subject});
  i = 9;
  h = 0;
  while(h<sizeof(active)) {
   i = i * 10;
   if(find_player(active[h])) {
     tell_object(find_player(active[h]),
      "    SWIZ BOARD: new msg\n"+
      "                "+sub+"\n");
   } else { 
     mailing(active[h]); 
     }
   h++;
  }
  who += ({i});
  save_object(SAVE);
write("\nNote Done.\n");
return 1; }

mailing(string dest) {
string mss;
  
  mss = "You have the following messeges unread:\n";
  
  call_other("/obj/mail_reader.c","send_mail",
              dest,"SWIZBOARD",mss,"");
}


