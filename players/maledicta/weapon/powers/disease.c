#include "/players/maledicta/ansi.h"
#include "/players/maledicta/weapon/define.h"


main(object user, object wep, string name, string short){
object poison;
if(random(100) > 20) return 0; 
if(!present(ATT, environment(USER))) return 0;
if(!present("poison2", ATT)){
 tell_object(ATT,
 HIW+"You feel a blinding pain and squint as light pierces your mind!\n"+NORM);
 tell_object(user,
 HIW+"Your "+NORM+BOLD+name+HIW+" pulls in light...\n"+
 "Deadly energy infuses the body of "+ATT->query_name()+"!"+NORM+"\n");
    poison = clone_object("/players/maledicta/weapon/diseased_obj.c");
    poison->set_duration(random(5) + 1);
    poison->set_damage(5);    
    move_object(poison, ATT);
    }
return 0;
}

