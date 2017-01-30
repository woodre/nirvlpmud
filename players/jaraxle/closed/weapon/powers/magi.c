#include "/players/jaraxle/ansi.h"
#include "/players/jaraxle/closed/weapon/define.h"


main(object user, object wep, string name, string short){ 

if(random(100) > 7) return 0;
tell_object(user,
"Your "+name+" shimmers...\n"+
GRN+"    F L O W I N G   M "+HIG+"A N A"+NORM+"\n"+
"   Energy flows into your body and renews you.\n");
user->add_spell_point(random(5) + 3);
return 0;
}

