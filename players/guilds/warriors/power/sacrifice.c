#include "/players/guilds/warriors/sdefine.h"

main(string str, object gob, object player)
{ 

if(USER->query_ghost()) return 1;
if(environment(USER)->realm() == "NM") return 0;
if(GOB->query_delay()) return 1;
if(USER->query_hp() < 50){
  tell_object(USER, "You do not have the health to sacrifice!\n");
  return 1;
  }
if(!USER->query_attack()){ 
   tell_object(USER, "You are not currently fighting.\n"); 
   return 1; 
   }

tell_object(USER, "You concentrate and "+BOLD+"~Sacrifice~"+NORM+" body for power.\n");
tell_room(environment(USER), USERN+" concentrates.\n",({USER}));

USER->add_hit_point(-(((USER->query_hp() * 8)/100)+4));
GOB->sacrifice_bonus(10 + (GOB->query_skills(97) * 4));
GOB->set_delay(1);
return 1;
}
