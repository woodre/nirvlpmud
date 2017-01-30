inherit "obj/armor";
#include "/players/hippo/bs.h"
int i;
reset(arg){
   ::reset(arg);
   set_short("a piece of fat");
   set_arm_light(0);
set_long(
     "This is a piece of fat, that could protect you against"+BS+
      "the cold. And it'll protect you a bit from damage, too"+BS);
  set_ac(1);
set_weight(1);
set_value(150);
   set_name("fat");
   set_type("misc");
   i=random(5)+1;
   set_size(i);
}
