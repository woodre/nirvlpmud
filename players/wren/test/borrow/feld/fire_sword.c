	/* fire sword */

#include <ansi.h>
inherit "obj/weapon";

reset(arg)  {
    ::reset();
    if(arg) return;

set_id("fire sword");
set_name("flame blade ");
set_alias("blade");
set_short("A firey blade");
set_long("Sword of fire from the forge of darkness  \n");

set_type("sword");   /*sword,knife,club,axe,bow,polearm */
set_class(20);
set_weight(1);
set_value(1);
set_hit_func(this_object());
set_params("other|fire", "flame_special");

}

weapon_hit(attacker) {
int W;
W = random(13);
if(W>9)  {
    say(" others hear. \n");
    write(" you hear. \n");
    return 3;
          }
return;
}

int
flame_special() {
     if(!random(5)) {
        tell_room(environment(), RED+"Flames"+NORM+" swirl around the blade as it strikes.\n");
        return 20; 
    }
}
