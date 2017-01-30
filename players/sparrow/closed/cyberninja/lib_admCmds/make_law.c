#include "../DEFS.h"

status main(string str) {
if(!call_other(OFFICED, "checkStone", TP, "diamond")) return 0;
  if(!str) {
write("Only Directives can create new laws.\n");
    return 1; 
  }
write_file(LOGDIR + "/LAWS",
""+BOLD+""+BLUE+"->"+RED+str+""+BLUE+"<-"+OFF+"\n"+BOLD+GREEN+"Law created by "+TRN+" at "+CYAN+"("+BLACK+ctime()+""+CYAN+")"+OFF+"\n\n");
write("You create a new law.\n");
  return 1;
}
