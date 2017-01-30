inherit "obj/armor";
#include "/players/hippo/bs.h"
reset(arg){
   ::reset(arg);
set_short("glazour coat");
   set_arm_light(0);
set_long(
  "A strong glazour coat from an incisor"+BS);
set_ac(3);
set_weight(1);
   set_value(1500);
   set_alias("coat");
   set_name("glazour coat");
set_type("armor");
}
