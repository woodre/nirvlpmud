#include "/players/maledicta/closed/w/sdefine.h"


main(string str, object gob, object player)
{
  	if(USER->query_ghost()) return 0;
   if(GOB->query_end() < 18){
      tell_object(USER,"You are too weak to RAGE.\n");
      return 1;
      }  
   if(GOB->query_rage()){ 
      tell_object(USER, "You are already raging!\n");
      return 1;
      }
   tell_object(USER,
   "You feel energy build around your body...\n"+
   "It courses through you and builds into a blind rage!\n");
 
   GOB->set_rage(random(3) + 5);
   GOB->add_end(-18);
   	return 1;
}


