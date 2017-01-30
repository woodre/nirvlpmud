#include "/players/jaraxle/closed/guild/sdefine.h"
#include "/players/jaraxle/ansi.h"
object waterment, firement;
int el_cost, el_cost2;
main(string str, object gob, object player)
{
   waterment = present("water_element", ENV);
   firement = present("fire_element", ENV);
   
   
   if(GOB->query_cost_toggle() ==1){ el_cost = 11; el_cost2 = 0; }
   else
      if(GOB->query_cost_toggle() ==2){ el_cost = 0; el_cost2 = 11; }
   else
      if(GOB->query_cost_toggle() ==3){ el_cost = 6; el_cost2 = 6; }
   
   if(USER->query_ghost()) return 0;
   
   if(GOB->query_fire_element() <= 0){ write("You do not know how to call fire.\n"); return 1; }

   if(HP < el_cost || SP < el_cost2){ write("You do not have enough mana to bring in this element.\n");
      return 1; }
   if(firement){ write(HIR+"Fire"+NORM+" has already swarmed the area.\n"); return 1; }
   tell_room(environment(USER),
      capitalize(NAME)+" claps "+UP+" hands together, then pushes them out in front of "+USER->OBJ+".\n"+
      HIR+"\t\tFlames"+NORM+" ignite across the room!\n", ({ USER }));
   write("You clap your hands together, pushing them out before you.\n"+
      HIR+"\tFlames"+NORM+" ignite across the room!\n");
   write(RED+"\t\t["+HIW+"You bring fire into the room"+NORM+RED+"]\n"+NORM);
   move_object(clone_object("/players/jaraxle/closed/guild/elements/fire.c"),environment(USER));
   USER->add_hp(-el_cost);
   USER->add_sp(-el_cost2);
   
   if(waterment){
      tell_room(environment(USER), "Clouds of steam rise as the "+HIR+"flames"+NORM+" evaporate all "+HIB+"water"+NORM+" in the room.\n");
      destruct(waterment);
      return 1; }
   return 1; }
