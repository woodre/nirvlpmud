#include "/players/jareel/define.h"
inherit "/obj/weapon";

reset(arg){
    if(arg) return;
    ::reset(arg);
    set_alias("dag");
  set_id("dagger");
    set_short("A dagger");
    set_long("This dagger is very simple it is basically a\n"+
                     "small knife with a white handle.  The dagger\n"+
                      "looks like you could poke someones eye out\n"+
                      "if you were not careful.\n");
set_class(15);
    set_weight(1);
    set_type("dagger");
    set_value(100);
    set_hit_func(this_object());
}
weapon_hit(attacker){
int i;
i = random(40);
if(i==1){
write(
         ""+TPN+" pokes with the dagger.\n");
return 3;
}
}
