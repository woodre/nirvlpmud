#include "/players/jaraxle/ansi.h"
#include "/players/jaraxle/closed/weapon/define.h"


main(object user, object wep, string name, string short){
object poison;
if(random(100) > 10) return 0; 
if(!present(ATT, environment(USER))) return 0;
if(!present("poison2", ATT)){
 tell_object(ATT,
 HIG+"You feel the cold flood of death enter your body"+HIW+"...\n"+NORM);
 tell_object(user,
 "Your "+wep->query_name()+" shimmers with a bright "+HIG+"green light"+NORM+"!\n"+
 "           "+HIW+"["+HIG+"P"+HIW+"] "+HIG+"o i s o "+HIW+"["+HIG+"N"+HIW+"]\n"+
 "   "+ATT->query_name()+" is flooded with poisonous energies!\n");
    poison = clone_object("/players/feldegast/obj/poison2.c");
    poison->set_duration(random(8) + 3);
    poison->set_damage(10);    
    move_object(poison, ATT);
    }
return 0;
}

