#include "/players/dune/closed/guild/DEFS.h"
#include "/players/pestilence/ansi.h"

status main(string str) {
if(!call_other(OFFICED, "checkStone", TP, "diamond")) return 0;
  if(!str) {
write("Only Directives can create new laws.\n");
    return 1; 
  }
write_file(LOGDIR + "/LAWS",
""+HIW+"->"+HIR+str+HIW+"<-"+NORM+"\n"+HIG+"Law created by "+TRN+" at "+HIW+"("+HIR+ctime()+HIW+")"+NORM+"\n\n");
write("You create a new law.\n");
  return 1;
}
