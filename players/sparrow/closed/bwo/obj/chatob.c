/* Most of this object taken from Cyber channel object coded by Wocket */
#include <ansi.h>

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
    if(present("black_willow_object",players[i])){
      members += ({ players[i], });
      num_members++;
    }
  }
  for(i=0,n=sizeof(members); i<n ; i++){
    if(present("black_willow_object",members[i])->muffled() != 1){
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
   "/obj/user/chistory"->add_history("Black Willow Order", str);
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
  if(str=="history"||str=="-h")
  {
    write("/obj/user/chistory"->query_history("Black Willow Order"));
    return 1;
  }
  msg = "";
  msg += query_tag()+" "+NORM;
  msg += capitalize(this_player()->query_real_name());
  msg += " speaks: "+NORM;
  msg += str;
  msg += "\n";
  send_msg(msg);
}

emote(string str){
  string msg;
    string em, arg, file;
    
    if(sscanf(str, "%s %s", em, arg) != 2) {
      em = str;
    }
    em = implode(explode(em, "."), "");
    if(file_size(file="/bin/soul/_"+em+".c") > 0) {
      return (int)file->guildcast("black willow", arg);
    }
  msg = "";
  msg += query_tag()+" "+NORM;
  msg += capitalize(this_player()->query_real_name())+" "+str;
  msg += "\n";
  send_msg(msg);
}

add_history(m) { 
  "/obj/user/chistory"->add_history("Black Willow Order", m);
}

query_tag() {
  return HIK+"["+HIC+"<"+NORM+CYN+"{"+HIK+"-"+NORM+CYN+"}"+HIC+">"+HIK+"]"+NORM;
}

