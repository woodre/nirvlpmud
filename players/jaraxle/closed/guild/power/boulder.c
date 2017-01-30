/*
* spell : Boulder   (earth)
* glevel : 1
* elevel : 1
* effect: spell_object 10+(random(element level*4))
* cost  : 10+(element level*2) sp
* spec  : 
* files : none
*/

#include "/players/jaraxle/closed/guild/sdefine.h"
#include "/players/jaraxle/ansi.h"
object victim, earthment;
int Dam1;
int ncost;

main(string str, object gob, object player)
{
   ncost = 10+(GOB->query_earth_element()*2);
   Dam1 = 10+(random(GOB->query_earth_element()*4));
   earthment = present("earth_element", ENV);
   
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
   
   if(!earthment){ write("The area is not prepared for "+YEL+"earth"+NORM+".\n"); return 1; }
   
   if(GOB->query_delay() >= time()){ return 1; }
   
   if(SP < ncost){ 
      write("You lack the mana for boulder.\n"); return 1; }
tell_object(USER, "As you raise your hands, a boulder appears over "+capitalize(victim->query_name())+".\n"+
    capitalize(victim->query_name())+" is crushed by the awesome mass!\n");
tell_room(environment(USER), "As "+capitalize(NAME)+" raises "+UP+" hands, a boulder appears over "+capitalize(victim->query_name())+".\n"+
    capitalize(victim->query_name())+" is crushed by the awesome mass!\n", ({ USER, victim }));
tell_object(victim, capitalize(NAME)+" crushes your body with a giant "+BOLD+BLK+"boulder"+NORM+"!\n");
   USER->spell_object(victim, "boulder", Dam1, ncost, "","","");
   GOB->set_delay(time());
   return 1;
}

