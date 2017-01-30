#include "/players/fred/mages/defs.h"

ssave(object ob){
  if(!ob) ob = ENV();
  save_object(SAVE_PATH+ob->query_real_name());
  return 1; 
 }
