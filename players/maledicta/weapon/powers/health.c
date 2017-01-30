#include "/players/maledicta/ansi.h"
#include "/players/maledicta/weapon/define.h"


main(object user, object wep, string name, string short){ 

if(random(100) > 15) return 0;

tell_object(user,
BLU+"You feel a magical warmth spread through your body"+BOLD+"..."+NORM+"\n");

user->add_hit_point(random(3) + 1);
return 0;
}

