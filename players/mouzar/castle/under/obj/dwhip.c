#include "/obj/ansi.h"
inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("whip");
set_alias("snake whip");
set_short(GRN+"Snake Whip"+NORM);
set_long(
"This is a long whip that is made out of snakes.  At the tip there are five\n"
+ "snake heads hissing waiting to attack the next victim.\n");
set_value(500);
set_weight(1);
set_class(15);
set_hit_func(this_object());
}
weapon_hit(attacker) {
if(random(100) < 40) {
write(GRN+"The snake heads bite into "+attacker->query_name()+" letting their venom seep innto it's blood\n"+NORM);
say(GRN+"The snake heads bite into "+attacker->query_name()+" letting their venom enter it's blood\n"+NORM);
return 10;
   }
return 0;
 }
