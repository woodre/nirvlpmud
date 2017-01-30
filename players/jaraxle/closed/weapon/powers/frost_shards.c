#include "/players/jaraxle/ansi.h"
#include "/players/jaraxle/closed/weapon/define.h"


main(object user, object wep, string name, string short){ 

if(random(100) > 15) return 0;

tell_object(user, 
HIW+"Your "+name+" drives into your foe sending shards of"+HIB+" ICE"+NORM+""+
HIW+" digging into their flesh!\n"+NORM);

tell_room(environment(user),
HIW+USERN+"'s "+name+" drives into it's victim slamming them with"+
" shards of "+HIB+"ICE"+HIW+"!"+NORM+"\n", ({USER}));
return 3;
}

