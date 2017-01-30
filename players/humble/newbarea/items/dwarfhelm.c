/*COPYRIGHT (C) VITAL CORP */
/* A HUMBLE MANIPULATION */
#include "../defs.h"
inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
    set_name(RED+"Dwarven Helm"+NORM);
    set_short(RED+"Dwarven Helm"+NORM);
    set_alias("helm");
    set_long(HIW+"The helm is severely beaten up, it has definately seen\n"+NORM+
    HIW+"better days.  It is round with a battered point at the top of the helm.\n"+NORM+
    HIW+"You doubt it offers that much protection but it is better than nothing.\n"+NORM);
   set_ac(1);
    set_type("helmet");
   set_weight(1);
    set_value(80);
}

