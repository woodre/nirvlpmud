#include "/players/maledicta/ansi.h"
#include "/players/maledicta/weapon/define.h"


main(object user, object wep, string name, string short){ 

if(random(100) > 15) return 0;

tell_object(user, 
"Your "+name+" spins about with fury!\n\n"+
BOLD+"      <<<<<<<<<< "+NORM+HIB+"I C E    S T O R M"+NORM+BOLD+" >>>>>>>>>>"+NORM+"\n\n"+
ATTN+" is slammed to the ground by the elemental forces!\n");

tell_room(environment(user),
USERN+"'s "+name+" spins before "+USEROB+"...\n"+
ATTN+" is slammed to the ground by an "+HIB+"Ice Storm"+NORM+"!\n", ({ USER }));

return 5;
}


