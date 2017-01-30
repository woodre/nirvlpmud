#include "/players/maledicta/ansi.h"
#include "/players/maledicta/weapon/define.h"


main(object user, object wep, string name, string short){ 

if(random(100) > 15) return 0;
tell_object(user,
BOLD+"Your "+name+" shakes violently...\n\n"+
HIG+"       M A N A   R I V E R"+NORM+BOLD+"\n\n"+
"   Energy enters your body and fills you with power!"+NORM+"\n");

user->add_spell_point(random(7) + 5);
return 0;
}

