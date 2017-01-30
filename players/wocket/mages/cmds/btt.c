#include "/players/wocket/closed/ansi.h"
#define CHANNELD "/players/wocket/mages/daemons/channelD.c"

cmd(str){
if(!str){
  notify_fail("What would you like to say on the guild line?\n");
  return 0;
}
if(present("mageguildob",this_player())->query_muffled()){
  write("You can not used the guild line while muffled.\n");
  return 1;
}
if(str == "history"){
  CHANNELD->viewhistory();
  return 1;
}

if(str == "who"){
  CHANNELD->guildwho();
  return 1;
}
switch(str[0]){
case ':': CHANNELD->create_emote(this_player(),str); break;
case '>': CHANNELD->create_echo(this_player(),str); break;
case '^': CHANNELD->create_think(this_player(),str); break;
default: CHANNELD->tell_guild(HIB+"*"+HIM+""+this_player()->query_name()+NORM+" sings: "+str+"\n"); break;
}
return 1;
}
