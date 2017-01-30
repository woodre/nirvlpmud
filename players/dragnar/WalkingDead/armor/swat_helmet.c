inherit "obj/armor";

#include <ansi.h>

reset(arg){
   ::reset(arg);
	set_short(HIBLK+"SWAT Helmet"+NORM);
  set_long(
"A black SWAT Kevlar Helmet with adjustable chin strap. Made from the\n\
the best materials and designed with comfort in mind, it has padding\n\
that fits perfectly. It is pre-fited to work with night vision goggles\n\
and can be fitted with a flip down face shield.\n");
   set_ac(2);
   set_weight(1);
   set_value(1400);
   set_name("helmet");
   SetMultipleIds( ({ "swat","swat helmet", "walkerobj" }) );
   set_type("helmet");
}

void init() 
{
  ::init();
}
