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
   if(GOB->query_water_element() <= 0){ write("You do not know how to call water.\n"); return 1; }
   if(waterment){ write(HIB+"Water"+NORM+" has already flooded the area.\n"); return 1; }
   
   tell_room(environment(USER),
      capitalize(NAME)+" stretches "+UP+" his arms out, his palms to the sky. . .\n"+
      "\t"+capitalize(UPR)+" closes "+UP+" eyes and raises "+UP+" face to the heavens. . .\n"+
      "\t\tRains fall onto the area, flooding the land.\n", ({ USER }));
   write("You stretch your arms out, pointing your palms to the sky. . .\n"+
      "\tYou close your eyes and raise your face to the heavens...\n"+
      "\t\tRains fall onto the area, flooding the land.\n");
   write(BLU+"\t\t["+HIW+"You bring water into the room"+NORM+BLU+"]\n"+NORM);
   move_object(clone_object("/players/jaraxle/closed/guild/elements/water.c"),environment(USER));
   USER->add_hp(-el_cost);
   USER->add_sp(-el_cost2);
   
   if(firement){
      tell_room(environment(USER), "The "+HIB+"rains"+NORM+" drown out the immense heat from the "+HIR+"fire"+NORM+".\n");
      destruct(firement);
      return 1; }
   return 1; }
