#include "/players/jareel/ansi.h"
#include "/players/jareel/GUILD/weapon/define.h"


main(object user, object wep, string name, string short){ 

if(random(100) > 15) return 0;
tell_object(user,
BOLD+"Your "+name+" shakes violently...\n\n"+
HIB+"        R I V E R  "+NORM+BOLD+"- "+HIB+"OF "+NORM+BOLD+"-"+HIB+"   H E A L T H"+NORM+BOLD+"\n\n"+
"   Energy enters your body and heals you!"+NORM+"\n");

user->add_hit_point(random(7) + 5);
return 0;
}

