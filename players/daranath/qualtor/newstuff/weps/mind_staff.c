#include <ansi.h>
 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("Mind Staff");
set_type("staff");
set_alias("quarterstaff");
set_short("Quarterstaff of the Mind "+HIW+"*"+HIR+"Psionic"+HIW+"*"+NORM);
set_long("A long, yet thin, crystal staff topped with a glowing red gem.\n"+
         "The staff was used during the psionic wars of long ago.\n");
set_class(16);
set_weight(1);
set_value(200+random(300));
}
