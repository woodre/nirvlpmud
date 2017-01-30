#include "/players/wocket/closed/ansi.h"

object listeners;
object members;
int num_listeners;
int num_members;

reset(arg){
  if(arg) return;
num_listeners = num_members = 0;
listeners = members = ({});
}

resetchannel(){
int i,n;
object players;
players = users();
listeners = members = ({});
for(i=0,n=sizeof(players); i<n ; i++){
  if(present("guild_implants",players[i])){
     members += ({ players[i], });
     num_members++;
  }
}
for(i=0,n=sizeof(members); i<n ; i++){
   if(present("guild_implants",members[i])->muffled() != 1){
      listeners += ({ members[i], });
      num_listeners++;
   }
}
return 1;
}

send_msg(string str){
int i,n;
for(i=0,n=sizeof(listeners);i<n;i++){
  if(listeners[i])
  tell_object(listeners[i],str);
}

}

officer_send_msg(string str){
int i,n;
for(i=0,n=sizeof(listeners);i<n;i++){
   if(listeners[i] && present("guild_implants",listeners[i])->query_officer(
0 == 1){
   tell_object(listeners[i],str);
}
}
}

force_send_msg(string str){
int i,n;
for(i=0,n=sizeof(members);i<n;i++){
   if(members[i])
   tell_object(members[i],str);
}
return 1;
}

tell(string str){
string msg;
msg = "";
msg += RED+"~~~"+NORM+BOLD;
msg += this_player()->query_name()+NORM;
msg += RED+"@CyberNet>> "+NORM;
msg += (string) str;
msg += "\n";
send_msg(msg);
}

emote(string str){
string msg;
msg = "";
msg += RED+"~~~CyberNet "+NORM+BOLD+"Image"+NORM+RED+">> "+NORM;
msg += this_player()->query_name()+" "+str;
msg += "\n";
send_msg(msg);
}

otell(string str){
string msg;
msg = "";
msg += HIB+"~~~"+NORM+BOLD;
msg += this_player()->query_name()+NORM;
msg += HIB+"@OfficerNet>> "+NORM;
msg += (string) str;
msg += "\n";
officer_send_msg(msg);
}
