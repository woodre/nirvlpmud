#include "/players/snow/dervish/def.h"

ssave(object ob){
  if(!ob) ob = environment();
  save_object("players/snow/dervish/member/" +ob->query_real_name());
  return 1; 
 }
