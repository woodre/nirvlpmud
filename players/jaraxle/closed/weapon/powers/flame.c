#include "/players/maledicta/ansi.h"
#include "/players/maledicta/weapon/define.h"


main(object user, object wep, string name, string short){ 

if(random(100) > 30) return 0;

tell_object(user, 
"Your "+name+" erupts...\n"+
"               "+HIR+"FLAME"+NORM+"\n"+
"                    It burns into "+ATTN+"!\n");
tell_room(environment(user),
USERN+"'s "+name+" erupts into "+HIR+"Flame"+NORM+" as it strikes "+ATTN+"!\n", ({USER}));
return 3;
}


