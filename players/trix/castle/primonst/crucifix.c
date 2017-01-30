#if 0 /* Rumplemintz */
#include "/open/ansi.h"
#else
#include <ansi.h>
#endif
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("crucifix");
   set_alt_name("cross");
   set_alias("cross");
	set_short(YEL+"Brass crucifix"+NORM);
   set_long("This is a simple brass cross the priest use to bless confessing people.\n");
   set_class(12);
   set_weight(2);
   set_value(500);
}
