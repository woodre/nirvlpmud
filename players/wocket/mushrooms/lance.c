#include "/players/wocket/closed/ansi.h"
inherit "/obj/weapon";

reset(arg){
    if(arg) return;
    set_id("lance");
    set_short("An oak lance");
    set_long("This is an oak lance.  It seems very steady and balanced, though it\n is just for beginiers.\n");
    set_class(17);
    set_weight(3);
    set_value(2000);
    set_type("lance");
    set_hit_func(this_object());
}

query_save_flag(){ return 1; }

weapon_hit(attacker){
int i;
if(this_player()->query_level() > 7){ return 0; }
i = random(6);
if(i==1){
    tell_room(environment(this_player()),this_player()->query_name()+" lunges forward running "+(attacker)->query_name()+" through.\n\n"+HIR+"Entrails of "+(attacker)->query_name()+HIR+" cling to the wooden lance.\n"+NORM);
return 5;
}
}

