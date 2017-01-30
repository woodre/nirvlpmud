#include "/players/maledicta/ansi.h"
#include "/players/maledicta/weapon/define.h"
#include "/sys/ansi.h"


main(object user, object wep, string name, string short){
  object poison;
  if(random(100) > 20){ 
    return 0; 
  }  
  if(!present(ATT, environment(USER))) {
      return 0;
  }
  if(!present("poison", ATT)){
    tell_object(ATT, RED+"You begin to feel feverish!\n"+NORM);
    tell_object(user, HIW+"["+HIY+"-"+HIW+"]"+NORM+YEL+" Your "+HIK+name+NORM+YEL+" infuses "+HBRED+"pestilence"+NORM+YEL+" into the body of "+ATT->query_name()+"!"+NORM+"\n");
    poison = clone_object("/players/maledicta/weapon/diseased_obj.c");
    poison->set_duration(random(5) + 1);
    poison->set_damage(random(5) + 6);    
    move_object(poison, ATT);
  }
return 0;
}