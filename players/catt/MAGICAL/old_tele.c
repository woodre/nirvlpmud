inherit"obj/weapon";
#include "std.h"
int i, charges, price;
object targetloc, demon;
string pointo;

id(str) { return str == "staff"; }

reset(arg) {
::reset(arg);
    if (!arg) charges=random(6);
    price = charges * 20;
   set_short("An Old Withered Staff");
   set_class(12);
   set_hit_func(this_object());
}

weapon_hit(attacker) {
string type;
type = 0;
   if(type == 0) {
    switch(random(11)) {
      case 0: type = "a fireball"; break;
      case 1: type = "a lightning bolt"; break;
      case 2: type = "magic missles"; break;
         case 3: type = "a cone of frost"; break;
         case 4: type = "a blinding spray of light"; break;
         case 5: type = "clenched spectral hand"; break;
         case 6: type = "several small flaming meteors"; break;
         case 7: type = "a large tentacle of spectral energy"; break;
         case 8: type = "hundreds of small ice darts"; break;
         case 9: type = "a wall of fire that rises out of the "+
                        "ground"; break;
         case 10: type = "a ray of pain"; break;
    }
    write("Your staff hits "+attacker->query_name()+" with "+type+".\n");
    say(attacker->query_name()+" is hit with "+type+".\n");
  return 3; }
return 0; }

query_save_flag() { return 1; } /* non saveable */


long() {
write("An old withered staff with distinct runes carved in black.\n" +
      "You seem to feel a strange power in the staff, and the    \n" +
      "markings tell you that the Demon Lords had some part in the\n" +
   "making of it.\n");
}


query_value()
{
    return price;
}


get() {
    return 1;
}

query_weight() {
    return 1;
}
