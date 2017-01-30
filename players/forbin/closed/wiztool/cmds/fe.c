/* faremote command */

#include "/players/forbin/define.h"
#include "/players/forbin/closed/wiztool/define.h"

main(str) {
  string who, what;
  object ob;
  if(!str || sscanf(str, "%s %s", who, what) < 2) {
    write("Usage: fe <who> <what>\n");
    return 0;
  }
  ob = find_player(who);
  if(!ob) return 0;
  write(HIW+"<"+WTC+"afar"+HIW+">"+NORM+" You "+what+"\n");
  tell_object(ob,""+HIW+"<"+WTC+"afar"+HIW+">"+NORM+" "+TPN+" "+what+"\n"+NORM);
  return 1;
}
