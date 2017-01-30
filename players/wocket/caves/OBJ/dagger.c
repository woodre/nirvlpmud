#include "/players/wocket/closed/ansi.h"
inherit "/obj/weapon";

reset(arg){
set_name("dagger");
set_short("A steel dagger");
set_long("A sturdy steel dagger.  It has been sharpened till it was a slender\n"+
         "strip of metal coming to a extremely sharp point.\n");
set_class(16);
set_type("dagger");
set_weight(2);
set_value(1000);
set_hit_func(this_object());
}

weapon_hit(){
int W;
W = random(5);
if(W == 1){
    write("The dagger finds it's mark and strikes deeply.\n");
    return 2;
}
}