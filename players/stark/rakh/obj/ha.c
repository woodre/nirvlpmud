/*
  Healing Aura #1
*/
#include "/players/stark/defs.h"
#define GOB present("rakh_guild",TP)
int kitten;

id(string str) { return str == "healing_aura"; }
drop() { return 1; }
get() { return 1; }

reset(arg){
kitten=GOB->query_aura1_lvl();
set_heart_beat(1);
    if(arg) return;
}
init(){
add_action("healing","healing");
}

heart_beat(){
/*TPADDHP(kitten*4);*/
ENV(TO)->add_hp(kitten*2);
tell_object(ENV(TO),kitten+"The fae feeds you gently.\n");
}

healing(){
write("You cancel your healing aura.\n");
destruct(TO);
return 1;
}
