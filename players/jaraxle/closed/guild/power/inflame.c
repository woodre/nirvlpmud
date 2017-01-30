#include "/players/jaraxle/closed/guild/sdefine.h"
#include "/players/jaraxle/ansi.h"
object firement;
main(string str, object gob, object player)
{
   firement = present("fire_element", ENV);
   /*
   if(GOB->query_fire_element() <= 0){ write("You do not know how to call fire.\n"); return 1; }
   */
   if(!firement){ write("The area is not prepared for "+HIR+"fire"+NORM+".\n"); return 1; }
   
   if(GOB->query_fire_shield() > 0){ write("You are already inflamed.\n"); return 1; }
   
   if(SP < 30+(GOB->query_fire_element()*2)){ write("You do not have enough mana to "+HIR+"inflame"+NORM+" yourself.\n"); return 1; }
   
   write("You clinch your fists tightly beside you, and begin to emit a low growl. . .\n"+
      HIR+"\t\tFlames"+NORM+" ignite over your body!\n");
   tell_room(environment(USER), capitalize(NAME)+" clinches "+UP+" fists by "+UP+" side and lets out a low growl.\n"+
      HIR+"\t\tFlames"+NORM+" ignite all over "+UP+" body!\n", ({ USER }));
   USER->add_sp(-30-(GOB->query_fire_element()*2));
   GOB->set_fire_shield(GOB->query_fire_element()*4);
   return 1; }
