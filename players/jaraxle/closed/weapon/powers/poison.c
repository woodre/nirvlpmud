#include "/players/jaraxle/ansi.h"
#include "/players/jaraxle/closed/weapon/define.h"


main(object user, object wep, string name, string short){
object poison;
if(random(100) > 10) return 0; 
if(!present(ATT, environment(USER))) return 0;
if(!present("poison2", ATT)){
 tell_object(ATT,
 GRN+"You feel the cold flood of death enter your body"+HIW+"...\n"+NORM);
 tell_object(user,
 "Your "+wep->query_name()+" glows a sickly "+GRN+"Green"+NORM+"...\n"+
 "       "+HIW+"---- "+NORM+GRN+"P O I S O N "+HIW+"----"+NORM+"\n"+
 "  "+ATT->query_name()+" screams in agony!\n");
    poison = clone_object("/players/feldegast/obj/poison2.c");
    poison->set_duration(random(3) + 1);
    poison->set_damage(6);    
    move_object(poison, ATT);
    }
return 0;
}

