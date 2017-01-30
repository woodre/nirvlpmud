inherit "obj/armor";
#include "/open/ansi.h"

reset(arg){
   ::reset(arg);
   set_short(BOLD+"leather bracers"+NORM);
   set_long("This is a pair of leather bracers, they can be very protective.\n");
   set_ac(1);
   set_weight(1);
   set_value(500);
   set_alias("leather bracers");
   set_name("bracers");
   set_type("bracelet");
}
