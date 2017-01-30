/* Most of this object taken from Cyber channel object coded by Wocket */
#include "/players/anshar/hero/def.h"

object listeners;
object members;
int num_listeners;
int num_members;

reset(arg){
  if(arg) return;
  num_listeners = num_members = 0;
  listeners = members = ({});
}

query_members() { return members; }
query_listeners() { return listeners; }

resetchannel(){
  int i,n;
  object players;
  players = users();
  num_members = num_listeners = 0;
  listeners = members = ({});
  for(i=0,n=sizeof(players); i<n ; i++){
    if(present(GID,players[i])){
      members += ({ players[i], });
      num_members++;
    }
  }
  for(i=0,n=sizeof(members); i<n ; i++){
    if(present(GID,members[i])->muffled() != 1){
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
  msg += HIG+BOLD+"**HERO** ";
  msg += capitalize(this_player()->query_real_name());
  msg += ":   "+NORM+NORM;
  msg += BOLD+str+NORM;
  msg += "\n";
  send_msg(msg);
}

emote(string str){
  string msg;
  msg = "";
  msg += HIG+BOLD+"**HERO** "+NORM+NORM;
  msg += BOLD+capitalize(this_player()->query_real_name())+" "+str+NORM;
  msg += "\n";
  send_msg(msg);
}
