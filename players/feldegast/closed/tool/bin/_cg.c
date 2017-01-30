#include "/players/feldegast/defines.h"
#include "/players/feldegast/std/colorize.h"
int do_cmd(string str) {
  if(!str) return 0;
  if(str=="history")
  {
    write((string)"/obj/user/chistory.c"->query_history("gossip"));
    write("\n");
    return 1;
   }
  if(str[0]==':')
    emit_channel("gossip",colorize("(gossip) "+TPN+" "+str[1..strlen(str)]+"\n"));
  else
  emit_channel("gossip",colorize(TPN+" gossips: "+str+"\n"));
  return 1;
}
