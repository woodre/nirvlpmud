#include "/players/jaraxle/ansi.h"
#include "/players/jaraxle/closed/weapon/define.h"


main(object user, object wep, string name, string short){ 
   
   if(random(100) > 30) return 0;
   
   tell_object(ATT,HIC+"\n        *****   COLD FIRE   *****\n\n"+NORM);
   tell_object(USER, "Your weapon flares!\n");
   tell_object(USER,HIC+"\n        *****   "+HIW+"COLD FIRE"+HIC+"   *****\n\n"+NORM);
   tell_room(environment(user),"Cold Fire engulfs "+ATTN+"!\n"); 
   if(random(4)){ 
      tell_object(USER, "The weapon quivers as you hit your foe!\n");
      tell_room(environment(user),BLU+
         "\n          ~ F  L  A  R  E ~\n\n"+NORM);
   }
   
   if(random(8)){ 
      tell_room(environment(user),BLU+        "\n          -= F  L  A  R  E =-\n\n"+NORM); }
if(random(6)){ tell_object(USER,HIC+"\n        "+HIC+"*** "+HIW+"COLD "+HIC+" ** "+HIW+" FIRE"+HIC+" ***\n\n"+NORM); }
      if(ATT->is_player() && ATT->query_hp() > 20) ATT->add_hit_point(-(random(10) + 4));
      else if(ATT->is_npc() && ATT->query_hp() > 20) ATT->heal_self(-(random(10) + 4)); 
      return 7;
   }


