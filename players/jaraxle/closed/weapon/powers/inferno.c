#include "/players/jaraxle/ansi.h"
#include "/players/jaraxle/closed/weapon/define.h"


main(object user, object wep, string name, string short){ 

if(random(100) > 7) return 0;

tell_object(user, 
"Your "+name+" spins about with fury!\n\n"+
"        "+HIR+" W O O S H"+NORM+"\n\n"+
"     The air around "+ATTN+" bursts into flame!\n");

tell_room(environment(user),
USERN+"'s spins "+USERPO+" "+name+" over "+USERPO+" head...\n\n"+
"       "+ATTN+" is engulfed by a fountain of "+HIR+"Flame"+NORM+"!\n", ({USER}));
return 5;
}


