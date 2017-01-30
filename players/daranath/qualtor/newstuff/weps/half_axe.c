#include <ansi.h>
#define tp this_player()->query_name()
#define targ capitalize(attacker->query_name())
 inherit "obj/weapon.c";
int a;

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("halfling axe");
set_type("axe");
set_short("Short double bladed Axe");
set_long("A normal double bladed axe, but the shaft of the weapon has\n"+
         "been perfectly sized for a Halfling. Dried blood cakes this \n"+
         "weapon, reminders of battles from long ago.\n");
set_class(16);
set_light(1);
set_weight(2);
set_value(200+random(500));
}

