#include "/players/jareel/ansi.h"
#include "/players/jareel/GUILD/weapon/define.h"


main(object user, object wep, string name, string short){ 

if(random(100) > 15) return 0;

tell_object(user, 
BOLD+"You swing your "+name+" before you in a wide arc...\n\n"+
NORM+HIB+"                P O W E R\n"+
"                   O F\n"+
"              G L A C I E R"+NORM+"\n"+
BOLD+ATTN+" is frozen into a wall of "+NORM+BLU+"Ice"+NORM+"!\n");

tell_room(environment(user),
USERN+" swings "+USERPO+" "+name+" in a wide arc before "+USEROB+"...\n"+
HIB+"Ice envelops "+ATTN+"!"+NORM+"\n", ({ user }));
return 7;
}


