inherit "obj/armor";
#include "/players/hippo/bs.h"
int i;
reset(arg){
   ::reset(arg);
   set_short("anti-blood boots");
set_long(
   "Some boots, used by thrombocytes to walk through blood"+BS);
   set_ac(1);
set_weight(1);
set_value(200);
   set_alias("bloodboots");
   set_name("boots");
set_type("boots");
   i=random(5)+1;
   set_size(i);
}
