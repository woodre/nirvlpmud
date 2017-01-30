inherit "obj/armor";
#include "/players/hippo/bs.h"
int i;
reset(arg){
   ::reset(arg);
set_short("glazour coat");
   set_arm_light(0);
set_long(
   "A strong glazour coat from an incisor"+BS);
set_ac(4);
set_weight(3);
set_value(600);
   set_alias("coat");
   set_name("glazour coat");
set_type("armor");
   i=random(2)+4;
   set_size(i);
}
