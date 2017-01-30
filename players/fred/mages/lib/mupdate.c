#include "/players/fred/mages/defs.h"

mupdate(){
 object ob;
 ob = CO("/players/fred/mages/gob.c");
 MO(ob, TP);
 write(BOLD+BLK+"Updating Black Circle...\n"+NORM);
 destruct(TO);
  return 1;
 }
