#include "/open/ansi.h"
inherit "obj/armor";

reset(arg){
   ::reset(arg);
	set_short(BOLD+"Work Boots"+NORM);
   set_long("A pair of heavy black boots.  They look very protective.\n");
   set_ac(2);
  set_params("magical",1,0,0); /* illarion may 2005 */
   set_weight(2);
   set_value(500);
   set_alias("boots");
   set_name("boots");
   set_type("boots");
}
