#include "/players/quicksilver/closed/color.h"


init() {
  string other;
  
  if(!query_ip_number(this_player())) return;
  if(this_player()->query_real_name()=="quicksilver") other="esoterica";
  else other="quicksilver";
  if(this_player()->query_real_name()!="quicksilver"&&this_player()->query_real_name()!="esoterica") 
     destruct(this_object());
  add_action("qchat","v");
  add_action("q","quit");
  qchat(":joins you in the game.",1);
  if(find_player(other)) write(BOLD+BLA+"~v~: "+NOSTYLE+capitalize(find_player(other)->query_real_name())+" is logged in!\n");
  else write(BOLD+BLA+"~v~: "+NOSTYLE+capitalize(other)+" is not logged in.\n");
}

reset(arg) {
   if(arg) return;
}

query_auto_load() {
  return "/players/quicksilver/closed/esoteric.c:";
}

get() { return 1; }
drop() { return 1; }
id(str) { return str=="qchat2"; }

qchat(str,quiet) {
string other;

  if(this_player()->query_real_name()=="quicksilver") other="esoterica";
  else other="quicksilver";
	if(find_player(other)) tell_object(find_player(other),BOLD+BLA+"~v~"+(((str[0]==58)||(str[0]==64)) ? "" : " "+(capitalize(this_player()->query_real_name())+" ~v~"))+
	": "+NOSTYLE+((str[0]==58) ? (capitalize(this_player()->query_real_name())+" ") : "")+(((str[0]==58)||(str[0]==64)) ? str[1..strlen(str)] : str)+"\n");
	if(quiet) return;
	write(BOLD+BLA+"~v~"+(((str[0]==58)||(str[0]==64)) ? "" : " "+(capitalize(this_player()->query_real_name())+" ~v~"))+
	": "+NOSTYLE+((str[0]==58) ? (capitalize(this_player()->query_real_name())+" ") : "")+(((str[0]==58)||(str[0]==64)) ? str[1..strlen(str)] : str)+"\n");
	return 1;
}

q() {
  qchat(":leaves silently.");
  return 0;
}
