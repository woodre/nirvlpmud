#include "/players/maledicta/ansi.h"
#include "/players/maledicta/weapon/define.h"


main(object user, object wep, string name, string short){ 

if(random(100) > 20) return 0;

tell_object(user, 
"Your "+name+" shimmers with cold power...\n"+
"         "+BLU+"~ "+HIB+": "+NORM+BLU+"~ "+HIB+":"+NORM+BLU+" ~  "+NORM+BOLD+"Ice Attack  "+NORM+BLU+"~ "+HIB+": "+NORM+BLU+"~ "+HIB+":"+NORM+BLU+" ~  "+NORM+"\n"+
"        "+ATTN+" is struck with a cone of Ice!\n");

tell_room(environment(user),
USERN+" holds forth "+USERPO+" "+name+"...\n"+
ATTN+" is struck by a "+HIB+"cone of Ice"+NORM+"!\n", ({USER}));

return 4;
}


