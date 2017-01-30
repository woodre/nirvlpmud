#include "/players/jaraxle/ansi.h"
#include "/players/jaraxle/closed/weapon/define.h"


main(object user, object wep, string name, string short){ 

if(random(100) > 7) return 0;

tell_object(user, 
"You hold your "+name+" out before you...\n\n"+
"                "+HIY+" N  O  V  A"+NORM+"\n\n"+
"  Flames leap out and engulf "+ATTN+"!\n");

tell_room(environment(user),
USERN+" holds forth "+USERPO+" "+name+"...\n"+
"                "+HIY+"N  O  V  A"+NORM+"\n"+
"  Flame engulfs "+ATTN+"!\n", ({ user }));
return 7;
}


