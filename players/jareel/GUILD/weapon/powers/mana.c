#include "/players/jareel/ansi.h"
#include "/players/jareel/GUILD/weapon/define.h"


main(object user, object wep, string name, string short){ 

if(random(100) > 15) return 0;

tell_object(user,
GRN+"You feel a magical warmth spread up your arm from the "+name+NORM+BOLD+"..."+NORM+"\n");

user->add_spell_point(random(3) + 1);
return 0;
}

