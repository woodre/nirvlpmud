#include "/players/wocket/closed/ansi.h"

string *seniors;

id(str){ return str == "seniorwizchannel1"; }

reset(arg){
  if(arg) return;
  seniors = ({ "feldegast","wocket","maledicta","arrina","eurale","beck" });
}

tell_seniors(msg){
int i,a;
  for(i=0,a=sizeof(seniors);i<a;i++){
    if(find_player(seniors[i]))
      tell_object(find_player(seniors[i]),msg);
  }
}

format_msg(str){
string msg;
  if(this_player()->query_level() < 100) return 0; 
  msg = "["+BOLD+"senior"+OFF+"] ";
  msg += BOLD+capitalize(this_player()->query_real_name())+OFF;
  msg += " wizs: ";
  msg += str+"\n";
  tell_seniors(msg);
}

senior(str){
  if(!str){ 
    notify_fail("What would you like to tell to the other seniors?\n");
    return 0;
  }
  format_msg(str);
  return 1;
}

init(){
  add_action("senior","senior");
}

query_prevent_shadow(){ return 1; }
