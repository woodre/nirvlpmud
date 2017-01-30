#include "/players/maledicta/ansi.h"
#include "/players/maledicta/weapon/define.h"


main(object user, object wep, string name, string short){ 

if(random(100) > 15) return 0;
tell_object(user,
"Your "+name+" shimmers...\n"+
GRN+"    F L O W I N G   M "+HIG+"A N A"+NORM+"\n"+
"   Energy flows into your body and renews you.\n");
user->add_spell_point(random(5) + 3);
return 0;
}

