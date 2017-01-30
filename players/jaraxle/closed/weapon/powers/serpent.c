#include "/players/jaraxle/ansi.h"
#include "/players/jaraxle/closed/weapon/define.h"


main(object user, object wep, string name, string short){
object lion;
if(random(100) > 5) return 0; 
if(!present(ATT, environment(USER))) return 0;
if(USER->query_alignment() > -40) return 0;
if(ATT->query_alignment() < 40) return 0;
if(present("serpent_from_wep", environment(USER))) return 0;
 wep->set_pet_allow(1);      
 tell_object(USER, 
  "A mist issues forth from your "+short+" and covers\nthe ground...\n"+
  "The Serpent of Corruption forms before your eyes!\n"); 
 tell_room(environment(USER),
  "The Serpent of Corruption forms before your eyes!\n", ({USER}));
      if(ATT){   
lion = clone_object("/players/jaraxle/closed/weapon/serpent_corruption.c");
       lion->set_owner(USER); 
       move_object(lion, environment(USER));
       lion->attack_object(ATT); 
       }
       return 0;
}

