#include "/players/maledicta/ansi.h"
#include "/players/maledicta/weapon/define.h"
#include "/sys/ansi.h"


main(object user, object wep, string name, string short){ 
  if(random(100) > 25) { 
    return 0;
  }
  tell_object(user,  HIW+"["+HIC+"+"+HIW+"]"+NORM+CYAN+" Your "+HIK+name+NORM+CYAN+" infuses you with "+HIK+"DARK HEALING"+NORM+CYAN+"!\n"+NORM);
user->add_hit_point(random(50) + 100);
  return 0;
}
