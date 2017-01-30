#include "/players/maledicta/ansi.h"
#include "/players/maledicta/weapon/define.h"
#include "/sys/ansi.h"

main(object user, object wep, string name, string short){ 
  if(random(100) > 25) { 
    return 0;
  }
  tell_object(user,
  HIW+"["+HIM+"+"+HIW+"]"+NORM+MAG+" Your "+HIK+name+NORM+MAG+" infuses you with "+HIK+"DARK MANA"+NORM+MAG+"!\n"+NORM);
  user->add_spell_point(random(6) + 10);
  return 0;
}
