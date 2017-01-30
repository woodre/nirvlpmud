#include "/players/wocket/closed/ansi.h"
inherit "/obj/weapon";

reset(arg){
set_name("longsword");
set_alias("sword");
set_short("A rusted longsword");
set_long("A rusted longsword.  The hilt is decorated very simply with\n"+
         "small traces of silver.  It is a very sturdy sword and seems\n"+
         "to have lasted the test of time, fighting against many foes.\n");
set_class(14);
set_type("sword");
set_weight(2);
set_value(500);
set_hit_func(this_object());
}

weapon_hit(){
int W;
W = random(5);
if(W == 1){
    write(HIR+"The blade strikes deep into its nemesis.\n"+NORM);
    return 2;
}
}

