#include "/players/jareel/ansi.h"
#include "/players/jareel/GUILD/weapon/define.h"


main(object user, object wep, string name, string short){
object poison;
if(random(100) > 20) return 0; 
if(!present(ATT, environment(USER))) return 0;
if(!present("poison2", ATT)){
  tell_object(ATT,
  "Your body grows cold as life is traded for disease!\n");
  tell_object(user,
  HIW+"Your "+name+" pulls in "+HIR+"light"+HIW+"..."+NORM+"\n\n"+
  HIW+"      { } "+HIR+"P L A G U E "+HIW+"{ }"+NORM+"\n\n"+
  HIW+ATT->query_name()+"'s body shakes violently!"+NORM+"\n");
   
    poison = clone_object("/players/maledicta/weapon/diseased_obj.c");
    poison->set_duration(random(10) + 5);
    poison->set_damage(7);    
    move_object(poison, ATT);
    }
return 0;
}

