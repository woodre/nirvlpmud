#include "/players/jareel/ansi.h"
#include "/players/jareel/GUILD/weapon/define.h"


main(object user, object wep, string name, string short){ 

if(random(100) > 20) return 0;

tell_object(user, 
"Your "+name+" releases a long tongue of electrical power...\n"+
"       "+ATTN+" cries out in pain as "+HIB+"ELECTRICITY"+NORM+" engulfs "+ATTOB+"!\n");
tell_room(environment(user),
USERN+"'s "+name+" releases a long tongue of electrical power...\n"+
"       "+ATTN+" cries out in pain as "+HIB+"ELECTRICITY"+NORM+" engulfs "+ATTOB+"!\n", ({USER}));

return 4;
}


