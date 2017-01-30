#include "DEF.h"

calm() {
object ob;
ob = first_inventory(ETP);
   while (ob) {
     if (living(ob)) {
      if (ob->query_attack()) {
       (ob->query_attack())->stop_fight();
       ob->stop_fight();
       }
      }
      ob = next_inventory(ob);
     }
 
write("You command the fighting to stop.... and it does. \n");
say(CTPRN+" commands the room to be STILL!\n");
return 1;
}
