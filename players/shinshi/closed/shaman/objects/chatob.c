/* Most of this object taken from Cyber channel object coded by Wocket */
/* I got this code from the Dervish directory in Snow's directory -Shinshi*/
/* Which would be /players/snow/dervish/objects/chatob.c */
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
    if(present("shinshi_shaman_relic",players[i])){
      members += ({ players[i], });
      num_members++;
    }
  }
  for(i=0,n=sizeof(members); i<n ; i++){
    if(present("shinshi_shaman_relic",members[i])->muffled() != 1){
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
   "/obj/user/chistory"->add_history("Shaman", str);
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
    write("/obj/user/chistory"->query_history("Shaman"));
    return 1;
  }
  msg = "";
  msg += BLU+"("+GRN+"X"+BLU+"X "+WHT+"Shaman"+BLU+" X"+GRN+"X"+BLU+") "+WHT;
  msg += capitalize(this_player()->query_real_name());
  msg += ":   "+OFF+OFF;
  msg += BOLD+str+OFF;
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
      return (int)file->guildcast("Shaman", arg);
    }
  msg = "";
  msg += BLU+"("+GRN+"X"+BLU+"X "+WHT+"Shaman"+BLU+" X"+GRN+"X"+BLU+") "+OFF+OFF;
  msg += BOLD+capitalize(this_player()->query_real_name())+" "+str+OFF;
  msg += "\n";
  send_msg(msg);
}

add_history(m) { 
  "/obj/user/chistory"->add_history("Shaman", m);
}

query_tag() {
  return BLU+"("+GRN+"X"+BLU+"X "+WHT+"Shaman"+BLU+" X"+GRN+"X"+BLU+") "+OFF+OFF;
}