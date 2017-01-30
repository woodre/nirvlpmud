#include "/players/quicksilver/closed/color.h"


string myself, spouse, short_descr, long_descr, entrance_msg, exit_msg,
       inscription;

static string msgs;

init()
{

  if(this_player()->query_real_name()!=myself&&this_player()->query_real_name()!=spouse) 
     destruct(this_object());
  add_action("chat","ring");
  add_action("add_message","note");
  add_action("view_messages","view");
  add_action("q","quit");
  chat(":"+entrance_msg,1);
  if(find_player(spouse)) write(BOLD+BLU+"{ring}: "+NOSTYLE+capitalize(spouse)+" is logged in!\n");
  else write(BOLD+BLU+"{ring}: "+NOSTYLE+capitalize(spouse)+" is not logged in.\n");
}

reset(arg) {
   if(arg) return;
   if(file_size("players/quicksilver/closed/etc/rings/"+this_player()->query_real_name()))
     restore_object("players/quicksilver/closed/etc/rings/"+this_player()->query_real_name());
   else {
     myself="someone";
     spouse="someone";
     short_descr="A wedding band";
     long_descr="A non-descript wedding band.\n";
     entrance_msg="joins you in the game.";
     exit_msg="left the game.";
   }
   if(file_size("players/quicksilver/closed/etc/rings/"+myself+".messages")<=0)
     msgs=read_file("players/quicksilver/closed/etc/rings/"+myself+".messages");
}

query_auto_load() {
  return "/players/quicksilver/closed/wedding_band.c:";
}

get() { return 1; }
drop() { return 1; }
id(str) { return str=="ring"||str=="wedding ring"||str=="wedding band"; }
short() { return short_descr+" "+BOLD+BLU+"{"+capitalize(spouse)+"}"+NOSTYLE; }
long() { write(long_descr); if(inscription) write("\nThere is an inscription on the ring.\n");
                            else write("\n");}

set_spouse(str) {
   spouse=str;
   save_object("players/quicksilver/closed/etc/rings/"+myself);
}

set_myself(str) {
   myself=str;
   save_object("players/quicksilver/closed/etc/rings/"+myself);
}

set_inscription(str) {
   inscription=str;
   save_object("players/quicksilver/closed/etc/rings/"+myself);
}

set_short(str) {
   short_descr=str;
   save_object("players/quicksilver/closed/etc/rings/"+myself);
}

set_long(str) {
   long_descr=str;
   save_object("players/quicksilver/closed/etc/rings/"+myself);
}

set_entrance(str) {
   entrance_msg=str;
   save_object("players/quicksilver/closed/etc/rings/"+myself);
}

set_exit(str) {
   exit_msg=str;
   save_object("players/quicksilver/closed/etc/rings/"+myself);
}

read_inscription(str) {
   if(str!="inscription") return 0;
   write(BOLD+BLU+"The inscription reads:"+NOSTYLE+"\n"+inscription);
   return 1;
}

view_messages() {
   write(BOLD+BLU+"The messages between you and your loved one read:"+NOSTYLE+"\n"+msgs);
   return 1;
}

add_message(str) {
   string msgarr, temp;
   int i;
   
   if(!str) {
      notify_fail("You must specify a message to add.\nUsage: note [message]\n");
      return 0;
   }
   if(!msgs) {
      msgs=str+"\n";
   } else {
      msgarr=explode(msgs, "\n");
      if((sizeof(msgarr)+1)>14) {
         for(i=1; i>sizeof(msgarr); i++) temp[i] = msgarr[i];
         msgarr=temp;
      }
      msgarr += ({ str+"\n" });
      msgs=implode(msgs, "\n");
   }
   if(file_size("players/quicksilver/closed/etc/rings/"+myself+".messages")<=0) 
     rm("players/quicksilver/closed/etc/rings/"+myself+".messages");  
   if(file_size("players/quicksilver/closed/etc/rings/"+spouse+".messages")<=0)
     rm("players/quicksilver/closed/etc/rings/"+spouse+".messages");  
   write_file("players/quicksilver/closed/etc/rings/"+myself+".messages",msgs);
   write_file("players/quicksilver/closed/etc/rings/"+spouse+".messages",msgs);
   chat("@Your ring radiates warmly for a brief second.");
   return 1;
}

chat(str,quiet) {
	if(find_player(spouse)) tell_object(find_player(spouse),BOLD+BLU+(((str[0]==58)||(str[0]==64)) ? "{ring}" : (capitalize(this_player()->query_real_name())+" {ring}"))+
	": "+NOSTYLE+((str[0]==58) ? (capitalize(this_player()->query_real_name())+" ") : "")+(((str[0]==58)||(str[0]==64)) ? str[1..strlen(str)] : str)+"\n");
	if(quiet) return;
	write(BOLD+BLU+(((str[0]==58)||(str[0]==64)) ? "{ring}" : (capitalize(this_player()->query_real_name())+" {ring}"))+
	": "+NOSTYLE+((str[0]==58) ? (capitalize(this_player()->query_real_name())+" ") : "")+(((str[0]==58)||(str[0]==64)) ? str[1..strlen(str)] : str)+"\n");
	return 1;
}

q() {
  qchat(":"+exit_msg);
  return 0;
}
