#include "/players/maledicta/ansi.h"
#include "/players/maledicta/weapon/define.h"


main(object user, object wep, string name, string short){ 

if(random(100) > 15) return 0;

tell_object(user, 
HIW+"You raise your "+name+" heavenward...\n\n"+
HIY+"   S T O R M   "+NORM+BOLD+"of"+HIY+"   D E A T H"+NORM+"\n\n"+
HIW+"  "+ATTN+" is struck over and over by lightning bolts!"+NORM+"\n");

tell_room(environment(user),
HIW+USERN+" raises "+USERPO+" "+name+" heavenward..."+NORM+"\n"+
HIW+ATTN+" is struck over and over by "+HIY+"Lightning Bolts"+HIW+"!"+NORM+"\n", ({ user }));
return 7;
}


