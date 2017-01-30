#include "/players/jenny/define.h"
main(str) { 
string who;
string what;
  if(!str) return 0;
  if(sscanf(str,"%s %s",who,what) != 2) return 0;
  if(!find_player(who)) { write("Target is not in play.\n"); return 1; }
  if(find_player(who)->query_level() > TPL) {
    write("You may not set the home of someone above you.\n"); 
  return 1; }
  find_player(who)->set_home(what);
  write("You have set "+who+"'s home to "+what+"\n");
return 1; }
