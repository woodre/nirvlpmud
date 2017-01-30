#include "/players/jaraxle/ansi.h"
#include "/players/jaraxle/closed/weapon/define.h"


main(object user, object wep, string name, string short){ 

if(random(100) > 7) return 0;
tell_object(user,
"Your "+name+" shimmers...\n"+
HIB+"    H E A L I N G   W A"+NORM+BLU+" R M T H"+NORM+"\n"+
"   You feel healing energy enter your body.\n");
user->add_hit_point(random(5) + 3);
return 0;
}

