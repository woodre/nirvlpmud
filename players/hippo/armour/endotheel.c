inherit "/obj/armor";
#include "/players/hippo/bs.h"
int i;
reset(arg){
   ::reset(arg);
   set_short("endotheel");
set_long(
   "This is a peace of endotheel, you extracted from the monster"+BS+
   "It looks quite magical. Maybe you could wear it?"+BS);
set_ac(1);
set_weight(1);
set_value(200);
set_name("endotheel");
set_type("ring");
   i=random(5)+1;
   set_size(i);
}
