#include "/players/jaraxle/closed/guild/sdefine.h"
#include "/players/jaraxle/ansi.h"
object earthment, windment;
int el_cost, el_cost2;
main(string str, object gob, object player)
{
   earthment = present("earth_element", ENV);
   windment = present("wind_element", ENV);
   
   if(GOB->query_cost_toggle() ==1){ el_cost = 11; el_cost2 = 0; }
   else
      if(GOB->query_cost_toggle() ==2){ el_cost = 0; el_cost2 = 11; }
   else
      if(GOB->query_cost_toggle() ==3){ el_cost = 6; el_cost2 = 6; }

   if(USER->query_ghost()) return 0;
   
   /*
   if(GOB->query_earth_element() <= 0){ write("You do not know how to call earth.\n"); return 1; }
   */
   if(HP < el_cost || SP < el_cost2){ write("You do not have enough mana to bring in this element.\n");
      return 1; }
   
   if(earthment){ write("The "+YEL+"earth"+NORM+" has already been torn asunder.\n"); return 1; }
   tell_room(environment(USER),
      capitalize(NAME)+" kneels down to the ground, placing "+UP+" hands into the soil. . .\n"+
      "\tThe "+YEL+"earth"+NORM+" begins to shake violently. . .\n"+
      "\t\tImmense pillars of bedrock tear up the ground as it is splits and cracks.\n", ({ USER }));
   write("You kneel down to the ground, placing your hands into the soil. . .\n"+
      "\tThe "+YEL+"earth"+NORM+" begins to shake violently. . .\n"+
      "\t\tImmense pillars of bedrock tear up the ground as it is splits and cracks.\n");
   write(YEL+"\t\t["+HIW+"You bring earth into the room"+NORM+YEL+"]\n"+NORM);
   move_object(clone_object("/players/jaraxle/closed/guild/elements/earth.c"),environment(USER));
   USER->add_hp(-el_cost);
   USER->add_sp(-el_cost2);
   
   if(windment){
      tell_room(environment(USER), "The large pillars of "+YEL+"earth"+NORM+" settle the "+HIC+"winds"+NORM+" from the area\n");
      
      destruct(windment);
      return 1; }
   return 1; }
