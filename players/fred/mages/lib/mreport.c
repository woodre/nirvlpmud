#include "/players/fred/mages/defs.h"

cmd_mreport(str){
 if(!str){ write("Report what?\n"); return 1;}
 write_file("/players/fred/mages/log/bug_report",
  capitalize(TPRN)+" reported: "+str+"\n");
write("Thanks for the report "+capitalize(TPRN)+"!\nDone.\n");
return 1;}
