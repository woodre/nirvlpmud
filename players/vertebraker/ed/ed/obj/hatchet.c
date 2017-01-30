#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit WEAPON;

reset(arg) {
    if(arg) return;
    ::reset();
    set_id("hatchet");
    set_alias("steel-bladed hatchet");
    set_alt_name("steel hatchet");
    set_short("A steel-bladed hatchet");
    set_long(
"A razor-sharp cutting-blade is at one end of this wood-chopping tool.  At the\n"+
"other end is the large, wooden butt which supports the entire tool.  It looks\n"+
"like it could make a decent weapon.\n");
    set_class(14);
    set_type("axe");
    set_message_hit(({
   "hacked","to small pieces",
   "cleaved","",
   "sliced","",
   "gouged","",
   "axed","",
   "hit","",
   "took a swing at",""
    }));
    set_value(1250);
    set_weight(2);
}
