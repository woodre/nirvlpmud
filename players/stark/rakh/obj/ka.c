/*
  Killing Aura
*/
#include "/players/stark/defs.h"
#define GOB present("rakh_guild",TP)
int kitten;

id(string str) { return str == "killing_aura"; }
drop() { return 1; }
get() { return 1; }

reset(arg){
set_heart_beat(1);
    if(arg) return;
}

heart_beat(){
if(present("rakh_guild",ENV(TO))->query_fps()>0){
    destruct(TO);
    }
ENV(TO)->add_hp(-5);
tell_object(ENV(TO),"The Dark Fae whips around you!\n");
}