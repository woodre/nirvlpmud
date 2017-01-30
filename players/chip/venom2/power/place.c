
#include "/players/chip/venom2/sdefine.h"


main(string str, object gob, object player)
{
string one,two;
	if(USER->query_ghost()){ return 0; }
	if(USER->query_level() < 15){ return 0; }
   if(gob->query_lair() != 1){ return 0; }
   if(USER->query_attack()){ tell_object(player, "You cannot while you are fighting!\n"); return 1; }
   if(environment(USER)->realm() == "NT" || 
      !creator(environment(USER)) ||
      environment(USER)->realm() == "NM"){
      tell_object(player, "You cannot place your lair here for some reason.\n");
      return 1; 
      }
   if(sscanf(file_name(environment(player)), "%s#%s", one, two) == 2){
      tell_object(player, "You cannot place your lair here for some reason.\n");
      return 1;
      }
   tell_object(player, 
   "You place your palm on the ground...\n"+
   HIK+"    D A R K   M A T T E R"+NORM+"  is injected into the ground at your feet.\n");
   gob->set_lair(file_name(environment(player)));
   gob->save_venom(1);
   return 1;
   }
      	
