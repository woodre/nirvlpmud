#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/weapon";

reset(arg) {
::reset(arg);
set_name("eshin claws");
set_alias("claws");
set_type("knife");
set_short(HIK+"Eshin Fighting Claws"+NORM);
set_long("\
   These claws are simple looking, but upon closer inspection you can\n\
easily see it is a deception.  A pair of blades are strapped to the  \n\
back of ones hand or paw, depending on the species.  They are light and\n\
carry a wicked edge.\n");   
set_class(18);
set_weight(1);
set_value(1500);
set_hit_func(this_object());
}
weapon_hit(attacker){
if(random(60) < 20){
write("The claws stab into "+attacker->query_name()+" leaving a painful gash!\n");
return 2;
}
return 0;
}
