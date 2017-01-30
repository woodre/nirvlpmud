/*COPYRIGHT (C) VITAL CORP */
/* A HUMBLE MANIPULATION */
#include "../defs.h"
inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
    set_name(YEL+"Wooden Shield"+NORM);
    set_short(YEL+"Wooden Shield"+NORM);
    set_alias("shield");
    set_long(HIW+"This is a small round wooden shield. It has two straps in the\n"+NORM+
    HIW+"back of the shield through which you can weave your arm through.\n"+NORM+
    HIW+"On the front of the shield there is a small metal piece stuck into the middle\n"+NORM+
    HIW+"of the shield, it's incredibly light but not very durable.\n"+NORM);
   set_ac(1);
    set_type("shield");
   set_weight(1);
    set_value(25);
}

