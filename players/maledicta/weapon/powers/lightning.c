#include "/players/maledicta/ansi.h"
#include "/players/maledicta/weapon/define.h"


main(object user, object wep, string name, string short){ 

if(random(100) > 15) return 0;

tell_object(user, 
HIW+"Your "+name+" strikes out quickly!\n\n"+
HIY+"    L I G H T N I N G "+HIW+"~ "+HIB+"S T R I K E"+NORM+"\n\n"+
HIW+"   "+ATTN+" falls back as a torrent of energy engulfs "+ATTOB+"!"+NORM+"\n");

tell_room(environment(user),
HIW+USERN+"'s spins "+USERPO+" "+name+" over "+USERPO+" head..."+NORM+"\n\n"+
HIW+"       "+ATTN+" is engulfed by a fountain of "+HIY+"Energy"+NORM+"!\n", ({USER}));
return 5;
}


