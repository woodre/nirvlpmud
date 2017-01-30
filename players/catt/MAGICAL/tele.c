inherit"obj/weapon";
#include "std.h"
int i, charges, price;
object targetloc, demon;
string pointo;


reset(arg) {
::reset(arg);
    if(arg) return;
    if (!arg) charges=random(6);
    price = charges * 20;
   set_name("old withered staff");
   set_alias("staff");
   set_short("An Old Withered Staff");
   set_class(12);
    set_type("staff");
   message_hit= ({"see the staff glow white as"," cries out in in terrible, excruciating pain",
                  "see the staff glow blue as"," cries out in a lot of pain",
                  "see the staff glow green as"," cries out in pain",
                "see the staff glow crimson as"," tries to deal with the magical assault",
                 "see the staff glow purple as"," deflects some of the magical energies",
                  "see the staff glow yellow as"," deflects most of the magical energies",
                  "see the staff glow as"," deflects almost all of the magical energies"});
   set_hit_func(this_object());
}

weapon_hit(attacker) {
string w_type;
w_type = 0;
   if(w_type == 0) {
    switch(random(11)) {
      case 0: w_type = "a fireball"; break;
      case 1: w_type = "a lightning bolt"; break;
      case 2: w_type = "magic missiles"; break;
         case 3: w_type = "a cone of frost"; break;
         case 4: w_type = "a blinding spray of light"; break;
         case 5: w_type = "clenched spectral hand"; break;
         case 6: w_type = "several small flaming meteors"; break;
         case 7: w_type = "a large tentacle of spectral energy"; break;
         case 8: w_type = "hundreds of small ice darts"; break;
         case 9: w_type = "a wall of fire that rises out of the "+
                        "ground"; break;
         case 10: w_type = "a ray of pain"; break;
    }
    write("Your staff hits "+attacker->query_name()+" with "+w_type+".\n");
    say(attacker->query_name()+" is hit with "+w_type+".\n");
    return 5;
   }
return 0; }



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
