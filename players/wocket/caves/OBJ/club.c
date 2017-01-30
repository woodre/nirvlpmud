#include "/players/wocket/closed/ansi.h"
inherit "/obj/weapon";

reset(arg){
set_name("club");
set_short("A large club");
set_long("A sturdy club make from a large rock.  It has jagged edges and is \n"+
         "bloodstained in many different places.\n");
set_class(16);
set_type("blunt");
set_weight(2);
set_value(1000);
set_hit_func(this_object());
}

weapon_hit(){
int W;
W = random(5);
if(W == 1){
    write("The club finds it's mark and crushes it.\n");
    return 2;
}
}