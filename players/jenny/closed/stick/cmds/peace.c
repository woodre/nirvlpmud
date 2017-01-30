#include "/players/jenny/define.h"
main(str) {
object att,ob;
int h;
ob = all_inventory(environment(TP));
h = 0;
while(h<sizeof(ob)) {
  if(ob[h]->query_attack()) { 
    att = ob[h]->query_attack();
    ob[h]->stop_fight();
    att->stop_fight();
  }
h++;
}
tell_room(environment(TP),BOLD+RED+capitalize(TPN)+
   NORM+" has called a stop to all fighting!\n");
return 1; }
