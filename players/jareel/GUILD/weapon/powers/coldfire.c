#include "/players/jareel/ansi.h"
#include "/players/jareel/GUILD/weapon/define.h"


main(object user, object wep, string name, string short){ 

if(random(100) > 30) return 0;

tell_object(ATT,CYN+"\n        *****   COLD FIRE   *****\n\n"+NORM);
tell_object(USER, "Your weapon flares!\n");
tell_object(USER,CYN+"\n        *****   COLD FIRE   *****\n\n"+NORM);
tell_room(environment(user),"Cold Fire engulfs "+ATTN+"!\n"); 
if(ATT->is_player() && ATT->query_hp() > 20) ATT->add_hit_point(-(random(10) + 4));
else if(ATT->is_npc() && ATT->query_hp() > 20) ATT->heal_self(-(random(10) + 4)); 
return 7;
}


