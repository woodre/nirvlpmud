#include "DEF.h"
 
register(str) {
  if(!str) { write("Register <who> \n"); return 1; }
  if(!find_player(str)) { write("Not on.... \n"); return 1; }
  if(call_other(find_player(str),"query_ghost"))
  { write("Sorry, he's dead... \n"); return 1; }
call_other(find_player(str),"reset",1);
find_player(str)->recalc_quest();
write("Registered "+capitalize(str)+"....\n");
return 1;
}
