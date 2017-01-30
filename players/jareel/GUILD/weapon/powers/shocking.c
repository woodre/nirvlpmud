#include "/players/jareel/ansi.h"
#include "/players/jareel/GUILD/weapon/define.h"


main(object user, object wep, string name, string short){ 

if(random(100) > 30) return 0;

tell_object(user, 
BLU+"Your "+name+" crackles with lines of "+HIY+"electrical energy"+NORM+BLU+"..."+NORM+"\n");
tell_room(environment(user),
USERN+"'s "+name+" crackles with electrical energy as it strikes "+ATTN+"!\n", ({USER}));
return 1;
}

