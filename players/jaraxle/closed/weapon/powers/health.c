#include "/players/jaraxle/ansi.h"
#include "/players/jaraxle/closed/weapon/define.h"


main(object user, object wep, string name, string short){ 

if(random(100) > 7) return 0;

tell_object(user,
BLU+"You feel a magical warmth spread through your body"+BOLD+"..."+NORM+"\n");

user->add_hit_point(random(3) + 1);
return 0;
}

