#include "/players/maledicta/ansi.h"
#include "/players/maledicta/weapon/define.h"


main(object user, object wep, string name, string short){ 

if(random(100) > 30) return 0;

tell_object(user, 
"Your "+name+" shimmers with "+BLU+"frost"+NORM+" as it strikes "+ATTN+".\n");
tell_room(environment(user),
USERN+"'s "+name+" shimmers with "+BLU+"frost"+NORM+" as it strikes "+ATTN+".\n", ({USER}));
return 1;
}

