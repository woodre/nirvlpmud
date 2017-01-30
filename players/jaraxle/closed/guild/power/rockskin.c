#include "/players/jaraxle/closed/guild/sdefine.h"
#include "/players/jaraxle/ansi.h"
object earthment;
main(string str, object gob, object player)
{
   earthment = present("earth_element", ENV);
   /*
   if(GOB->query_earth_element() <= 0){ write("You do not know how to call earth.\n"); return 1; }
   */
   if(!earthment){ write("The area is not prepared for "+YEL+"earth"+NORM+".\n"); return 1; }
   
   if(GOB->query_earth_shield() > 0){ write("You are already hardened.\n"); return 1; }
   
   if(SP < 30+(GOB->query_earth_element()*2)){ write("You do not have enough mana to "+YEL+"rock-skin"+NORM+" yourself.\n"); return 1; }
   
   write("You flex your muscles and angrilly stomp your right foot onto the ground...\n"+
      "\tThe "+YEL+"earth"+NORM+" crawls up your leg...\n"+
      "\t\tbonds over your entire body...\n"+
      "\t\t\tforming a rock hard skin.\n");
   tell_room(environment(USER), capitalize(NAME)+" flexes "+UP+" muscles and angrilly stomps "+UP+" right foot onto the ground...\n"+
      "\tThe "+YEL+"earth"+NORM+" crawls up "+UP+" leg...\n"+
      "\t\tbonding over "+UP+" entire body...\n"+
      "\t\t\tforming a rock hard skin.\n", ({ USER }));
   USER->add_sp(-30-(GOB->query_earth_element()*2));
   GOB->set_earth_shield(GOB->query_earth_element()*4);
   return 1; }
