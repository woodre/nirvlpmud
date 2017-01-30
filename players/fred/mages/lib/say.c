#include "/players/fred/mages/defs.h"

cmd_say(str){
  string me, how;
  int index;
  if(!str){ write("Say what?\n"); return 1; }
  if(str[(index = (strlen(str)-1))] == '?')
   how = "ask";
  else if(str[index] == '!')
   how = "exclaim";
  else how = "say";

  str = format(str, 60);
  me = TP->query_name();
  if(TP->query_ghost()){
   say(BOLD+BLK+"ghost of "+TPN+" "+how+"s: "+NORM+str+"\n");
   write(BOLD+BLK+"You "+how+": "+NORM+str+"\n");
   return 1; }
   say(BOLD+BLK+me+ " "+how+"s: "+NORM+str+"\n");
   write(BOLD+BLK+"You "+how+": "+NORM+str+"\n");
  return 1;
}
