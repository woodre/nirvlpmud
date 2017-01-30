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
static int ww,kk,jj;
static mess, subject;

id(str) {  return str == "swiz_board" || 
                  str == "board"; }

short() { if(check(tp)) return 0; 
          return "Senior Wiz Board"; }

drop() { return 0; }

get() { return 0; }

reset(arg) {
  if(arg)return;
  if(!restore_object(SAVE)) {
    active = ({"boltar","mythos","arrina","wizardchild",
               "pain"});
    who = ({"n_n_n_n_n"});
    msg = ({0});
    sub = ({0});
   
    save_object(SAVE);
  }
  mess = 0;
  subject = 0;
  ww = 0;
  kk = 0;
}

long() {
  if(check(tp)) write("");
  else 
  write("Senior Wiz Board\n"+
        "The commands for this wizboard are the following:\n"+
        "read #, note <subject>, addmem <name>, list\n"+
        "Only Boltar may 'erase #' and remove_mem <name>\n"+
        "So type carefully.\n"+
        "Note: This board has no limit as to number of msgs\n");
}

init() {
  if(check(tp)) {
   if(eo == tp) destruct(to);
  return 1; }
  add_action("note","note");
  add_action("read","read");
  add_action("list","list");
  if(tpn == "boltar") {
    add_action("erase","erase");
    add_action("remmem","remove_mem");
  }
}

list() {
int h,mm;
if(check(tp)) return 0;
  write("Senior Wiz Board: "+sizeof(sub)+" notes:\n");
  h = 0;
  kk = sizeof(sub)/20;
  if(kk < 1) mm = sizeof(sub);
  else mm = 20;
  while(h< mm) {
    write((h+1)+ "]  "+sub[h]+"\n");
    h++;
  }
  jj = 1;
  if(kk > 0) { write("MORE:\n"); call_out("lister",5); }
return 1; }

lister() {
int mm;
int h;
  h = 0;
  kk = kk - 1;
  if(kk < 1) mm = (sizeof(sub) - jj*20);
  else mm = 20;
  while(h < mm) {
    write((h + jj*20 + 1)+"]  "+sub[h]+"\n");
    h++; 
  }
  jj = jj + 1;
  if(kk > 0) { write("MORE:\n"); call_out("lister",5); }
return 1; }
  
erase(int q) {
if(check(tp)) return 0;
  if(tpn != "boltar") return 0;
  if(q < 1 || q > sizeof(sub) + 1) {
    write("There is no messege of that number.\n");
  return 1; }
  ww = q - 1;
  write("You sure you wish to erase:\n"+
        sub[ww]+"\n[Y/N]  ?  ");
  input_to("eraseok");
return 1; }

static eraseok(str) {
   if(!str) { write("Erase aborted.\n"); return 1; }
   if(str == "n" || str == "N") { write("Erase Aborted\n"); return 1; }
   if(str == "Y" || str == "y") { 
     sub -= ({sub[ww]});
     msg -= ({msg[ww]});
     who -= ({who[ww]});
     ww = 0;
     save_object(SAVE);
     write("Erasure Done.\n");
   return 1;}
  write("You sure you wish to erase:\n"+
  sub[ww]+"\n[Y/N]  ?  ");
  input_to("eraseok");
return 1; }

remmem(str) {
if(check(tp)) return 0;
  if(tpn != "boltar") return 0;
  if(!str) return;
  ww = member_array(str,active);
  if(ww == -1) { write("That is already not a member.\n");
  return 1; }
  write("Are you sure you wish to remove "+str+"? [y/n] :");
  input_to("remok");
return 1; }

static remok(str) { 
string mo;
int h;
   if(!str) { write("Removal aborted.\n"); return 1; }
   if(str == "n" || str == "N") { write("Removal Aborted\n"); return 1; }
   if(str == "Y" || str == "y") { 
     active -= ({active[ww]});
     h = 0;
     while(h<sizeof(sub)) {
     mo = explode(who[h],"_");
     mo -= mo[ww];
     who[h] = implode(mo,"_");
     h++;
     }
     ww = 0;
     save_object(SAVE);
     write("Removal Done.\n");
   return 1;}
  write("Are you sure you wish to remove "+str+"? [y/n] :");
  input_to("remok");
return 1; }


check(ob) { 
  if(member_array(ob->query_real_name(),active) == -1 ||
     member_array(ob,users()) == -1 ||
     !ob->is_player() || ob->query_level() < 100) return 1;
return 0; }

add_mem(str) {
int h;
string j;
  if(check(tp)) return 0;
  if(!find_player(str)) {
   write("That person is not on.\n");
   return 1; }
  if(find_player(str)->query_level() < 100) {
    write("That player is not level 100.\n");
  return 1; }
  active += ({lower_case(str)});
  h = 0;
  while(h<sizeof(who)) { 
    j = explode(who[h],"_");
    j += ({"n"});
    who[h] = implode(j,"_");
  h++; }
  save_object(SAVE);
  write(str+" may now access the senior board.\n");
return 1; }

read(str) {
int n,k;
string j;
  if(!str) return 0;
  if(check(tp)) return 0;
  k = member_array(tpn,active);
  sscanf(str,"%d",n);
  if(n < 1 || n > sizeof(sub)) {
   write("Not that many messeges.\n");
  return 1; }
  write(sub[n - 1]);
  write("\n");
  write(msg[n - 1]);
  write("\n");
  j = explode(who[n - 1],"_");
  j[k] = "y";
  who[n-1] = implode(j,"_");
return 1; }

note(str) { 
if(!str) return 0;
if(check(tp)) return 0;
subject = str + "["+tpn+"] <"+ctime(time())+">";
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
int h;
string me;
  if(msg[0]) {
  msg += ({mess});
  sub += ({subject}); }
  else {
  msg = ({mess});
  sub = ({subject});
  }
  h = 0;
  me = "";
  while(h<sizeof(active)) {
   if(find_player(active[h])) {
     tell_object(find_player(active[h]),
      "    SWIZ BOARD: new msg\n"+
      "                "+subject+"\n");
   } else { 
     mailing(active[h]); 
     }
   me += "n";
   if(h<(sizeof(active) - 1)) me += "_";
   h++;
  }
  who += ({me});
  save_object(SAVE);
write("\nNote Done.\n");
return 1; }

mailing(string dest) {
string mss;
int h;
  mss = "You have the following messeges unread:\n\n";
  while(h<sizeof(sub)) {
    if(retrieve(dest,h) == "n") mss += "  "+ (h+1);
  h++; }
  mss += "\n\n                          - SWIZ Paging\n";
  call_other("/obj/mail_reader.c","send_mail",
              dest,"SWIZ Paging System   ",mss,"");
}

retrieve(string ah,int z) {
int m;
string k;
 m = member_array(ah,active);
 if(m == -1) return;
 k = explode(who[z],"_");
return k[m]; }
