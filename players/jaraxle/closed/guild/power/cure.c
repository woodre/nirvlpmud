/*
* spell : Cure   (water)
* glevel : 1
* elevel : 1
* effect: add_hp 9+random(element level);
* cost  : add_sp 10+element level
* spec  : Can only heal self
* files : none
*/

#include "/players/jaraxle/closed/guild/sdefine.h"
#include "/players/jaraxle/ansi.h"
object waterment;
int ncost, heal_amount;

main(string str, object gob, object player)
{
   ncost = 10+GOB->query_water_element();
    heal_amount = 9+random(GOB->query_water_element()+1);
   waterment = present("water_element", ENV);
   
   if(USER->query_ghost()) return 0;
   
   if(!waterment){ write("The area is not prepared for "+HIB+"water"+NORM+".\n"); return 1; }
   
   if(GOB->query_water_element() <= 0){ write("You cannot use this spell.\n"); return 1; }
   
   if(str){ write("You can only cure yourself at this time.\n"); return 1; }
   
   if(MHP - HP < heal_amount){ write("You do not need to cure.\n"); return 1; }
   if(SP < ncost){ 
      write("You lack the mana for cure.\n"); return 1; }
   tell_object(USER, "With a flick of your wrist you splash some "+HIB+"water"+NORM+" on your face,\n"+
      "\trefreshing your spirit.\n");
   tell_room(environment(USER), "With a flick of "+UP+" wrist "+capitalize(NAME)+" splashes some "+HIB+"water"+NORM+" on "+UP+" face,\n"+
      "\trefreshing "+UP+" spirit.\n", ({ USER }));
   USER->add_sp(-ncost);
   USER->add_hp(heal_amount);
   return 1;
}

