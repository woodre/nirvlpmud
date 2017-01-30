#include "/players/maledicta/ansi.h"
#include "/players/maledicta/weapon/define.h"


main(object user, object wep, string name, string short){ 

if(random(100) > 8) return 0;
tell_object(user,
HIR+"[]"+NORM+" Your "+name+" hums with power...\n"+
HIR+"[]"+NORM+" You feel the toxins within your body begin to dissipate...\n");
if(user->query_stuffed()) user->add_stuffed(-1);
if(user->query_soaked()) user->add_soaked(-1);

return 0;
}

