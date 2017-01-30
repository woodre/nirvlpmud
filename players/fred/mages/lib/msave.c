#include "/players/fred/mages/defs.h"

msave(object ob){
  if(!ob) ob = ENV();
  save_object(SAVE_PATH+ob->query_real_name());
  tell_object(ob,
    BOLD+BLK+"Saving Black Circle...\n"+NORM);
  return 1; 
 }
