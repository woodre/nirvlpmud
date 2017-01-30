/*
* spell : Firewhip   (fire)
* glevel : 1
* elevel : 1
* effect: spell_object 10+(random(element level*4))
* cost  : 10+(element level*2) sp
* spec  : 
* files : none
*/

#include "/players/jaraxle/closed/guild/sdefine.h"
#include "/players/jaraxle/ansi.h"
object victim, firement;
int Dam1;
int ncost;

main(string str, object gob, object player)
{
   ncost = 10+(GOB->query_fire_element()*2);
   Dam1 = 10+(random(GOB->query_fire_element()*4));
   firement = present("fire_element", ENV);
   
   if(!str && ATT)
      victim = ATT;
   else if(str)
      victim = present(str, environment(USER));
   if(!victim){
      tell_object(USER,
         "You don't see that here.\n");
      return 1;
   }
   if(!living(victim)){
      tell_object(USER,
         "You cannot attack "+str+"!\n");
      return 1;
   }
   if(!str && !ATT){ write("You must specify a target.\n"); return 1; }
   
   if(USER->query_ghost()) return 0;
   
   if(!firement){ write("The area is not prepared for "+HIR+"fire"+NORM+".\n"); return 1; }
   
   if(GOB->query_delay() >= time()){ return 1; }
   
   if(SP < ncost){ 
      write("You lack the mana for firewhip.\n"); return 1; }
   tell_object(USER, "You lash at "+capitalize(victim->query_name())+" with a "+HIR+"whip of fire"+NORM+"!\n"+
      capitalize(victim->query_name())+" screams in pain as the "+HIR+"firewhip"+NORM+" boils "+victim->OBJ+" skin.\n");
   tell_room(environment(USER), capitalize(NAME)+" lashes at "+capitalize(victim->query_name())+" with a "+HIR+"whip of fire"+NORM+"!\n"+
      capitalize(victim->query_name())+" screams in pain as the "+HIR+"firewhip"+NORM+" boils "+victim->OBJ+" skin.\n", ({ USER, victim }));
   tell_object(victim, capitalize(NAME)+" burns you violently with a "+HIR+"whip of flame"+NORM+"!\n"+
      "You scream in pain as your skin begins to boil.\n");
   USER->spell_object(victim, "firewhip", Dam1, ncost, "","","");
   GOB->set_delay(time());
   return 1;
}

