#include "/players/jareel/ansi.h"
#include "/players/jareel/GUILD/weapon/define.h"


main(object user, object wep, string name, string short){ 

if(random(100) > 30) return 0;

tell_object(user, 
"Your "+name+" shimmers with "+RED+"heat"+NORM+" as it strikes "+ATTN+".\n");
tell_room(environment(user),
USERN+"'s "+name+" shimmers with "+RED+"heat"+NORM+" as it strikes "+ATTN+".\n", ({USER}));
return 1;
}

