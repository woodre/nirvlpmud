#include "/players/jareel/ansi.h"
inherit "/obj/weapon";

reset(arg){
     ::reset(arg); 
     if(arg) return;
     
     set_alt_name("fire");
     set_id("dagger");
     set_alias("dagger");
     set_name("dagger of fire and ice");
     set_short("Dagger of"+BOLD+RED+" Fire "+NORM+"and "+BOLD+CYN+"ICE"+NORM);
     set_long("This finely forged dagger is made of the metal Iron, a coveted\n"+
       "metal for adventurers.  The runes enscribed along the blade absorb all\n"+
       "the light hitting them.  It looks deadly.\n");
     set_read(BOLD+RED+"Fire "+NORM+"and "+BOLD+CYN+"Ice"+NORM+".\n");
     set_class(17);
     set_weight(1);
     set_type("small");
     set_value(1200);
     set_hit_func(this_object());
}

weapon_hit(attacker){

     int sph;
     sph = random(6);

     if(sph==0)  {
       write("The dagger bites deep into the skin.\n");
     }

     if(sph==1)  {
       write("Blood runs down the daggers blade.\n");
     }
     
     if(sph==2)  {
       write(BOLD+RED+"\n"+
         "               (  .      )                 \n"+
         "        )           (              )       \n"+
         "              .  '   .   '  .  '  .        \n"+          
         "     (    , )       (.   )  (   ',    )    \n"+
         "      .' ) ( . )    ,  ( ,     )   ( .     \n"+
         "   ). , ( .   (  ) ( , ')  .' (  ,    )    \n"+
         "  (_,) . ), ) _) _,')  (, ) '. )  ,. (' )  \n"+
         "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ \n"+
         "\n"+NORM);
         say(BOLD+RED+"F I R E"+NORM+" explodes into "+NORM+attacker->query_name()+".\n\n");
         write("\nThe daggern BURNS you!!!\n\n");
         this_player()->hit_player(10, "other|jareel");
       return 5;
     }

     if(sph==3)  {
       write(
         "                    "+BOLD+CYN+" /   ))     |\         )               ).\n"+           
         ""+NORM+"               c--."+BOLD+CYN+" (\  ( `.    / )  (\   ( `.     ).     ( (\n"+           
         ""+NORM+"              | |"+BOLD+CYN+"   ))  ) )   ( (   `.`.  ) )    ( (      ) )\n"+          
         ""+NORM+"              | |"+BOLD+CYN+"  ( ( / _..----.._  ) | ( ( _..----.._  ( (\n"+           
         ""+NORM+",-.           | |"+BOLD+CYN+"---) V.'-------.. `-. )-/.-' ..------ `--) \._\n"+        
         ""+NORM+"| /===========| |"+BOLD+CYN+"  (   |      ) ( ``-.`\/'.-''           (   ) ``-.\n"+
         ""+NORM+"| | / / / / / | |"+BOLD+CYN+"--------------------->  <-------------------------_>=-\n"+
         ""+NORM+"|  \===========| |"+BOLD+CYN+"                 ..-'./\.`-..                _,,-'\n"+    
         ""+NORM+"`-'           | |"+BOLD+CYN+"-------._------''_.-'----`-._``------_.-----'\n"+         
         ""+NORM+"              | |"+BOLD+CYN+"         ``----''            ``----''\n"+                  
         ""+NORM+"              | |"+BOLD+CYN+"\n"+                                                       
         ""+NORM+"               c--`"+BOLD+CYN+"\n"+ 
         "\n"+NORM);
         say(BOLD+CYN+"I C E "+NORM+"stashes into "+attacker->query_name()+".\n");
       return 5;
     }

     if(sph==4)  {
       write(BOLD+"\n"+"\n"+
         "The legendary dagger release "+BOLD+RED+"Fire"+NORM+" and"+BOLD+CYN+" Ice\n"+NORM);
         this_player()->add_spell_point(random(10));
     return 0;}
     return 5;
}
