#include "/players/jaraxle/ansi.h"
#include "/players/jaraxle/closed/weapon/define.h"


main(object user, object wep, string name, string short){ 

if(random(100) > 15) return 0;

tell_object(user, 
"Your "+name+" flares with cold energy...\n"+
"           "+HBBLU+"- - --- Burning Cold --- - -"+NORM+"\n"+
"  "+ATTN+" cries out in agony as streams of cold tear into "+ATTOB+"!\n");

tell_room(environment(user),
USERN+" holds forth "+USERPO+" "+name+"...\n"+
"Streams of cold energy envelop and burn "+ATTN+"!\n", ({USER}));
return 3;
}


