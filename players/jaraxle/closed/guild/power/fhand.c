#include "/players/jaraxle/closed/guild/sdefine.h"
#include "/players/jaraxle/ansi.h"
object firement;
main(string str, object gob, object player)
{
   firement = present("fire_element", ENV);
   /*
   if(GOB->query_fire_element() <= 0){ write("You do not know how to call fire.\n"); return 1; }
   */
   if(!firement){ write("The area is not prepared for "+RED+"fire"+NORM+".\n"); return 1; }
   
   if(GOB->query_fire_hands() > 0){ write("You are already using fire hands.\n"); return 1; }
   
   if(SP < 30+(GOB->query_fire_element()*2)){ write("You do not have enough mana to "+RED+"fire hand"+NORM+" yourself.\n"); return 1; }
   
   write("You flex your muscles and angrilly stomp your right foot onto the ground...\n"+
      "\tThe "+YEL+"earth"+NORM+" crawls up your leg...\n"+
      "\t\tbonds over your entire body...\n"+
      "\t\t\tforming a rock hard skin.\n");
   tell_room(environment(USER), capitalize(NAME)+" flexes "+UP+" muscles and angrilly stomps "+UP+" right foot onto the ground...\n"+
      "\tThe "+YEL+"earth"+NORM+" crawls up "+UP+" leg...\n"+
      "\t\tbonding over "+UP+" entire body...\n"+
      "\t\t\tforming a rock hard skin.\n", ({ USER }));
   USER->add_sp(-30-(GOB->query_fire_element()*2));
   GOB->set_fire_hands(GOB->query_fire_element()*4);
   return 1; }
