#include "/players/wocket/closed/ansi.h"

cmd(str){
string who,what,how;
string msg,msg2;
object whoob;
  if(!str){ 
    notify_fail("What would you like to emote?\n");
    return 0;
  }
  sscanf(str,"%s %s",what,who);
    sscanf(who,"%s %s",who,how);
  if(!how){ how = ""; }
  if(!who){
    notify_fail("Who would you like to emote to?\n");
    return 0;
  }
  whoob = find_player(who);
    msg = "You "+what+" "+how+" at "+whoob->query_name();
  if(environment(this_player()) != environment(whoob)){
    msg += " from afar.\n";
  } else {
    msg += ".\n";
  }

  tell_object(this_player(),msg);
  return 1;
}
