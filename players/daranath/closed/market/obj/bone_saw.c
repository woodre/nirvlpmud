#include <ansi.h>
 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("bone saw");
set_type("exotic");
set_alias("saw");
set_short("Bone Saw");
set_long("The blade of the Bone Saw was perfectly designed for cutting through\n"+
         "flesh and especially bone. A decent weapon, although it is perhaps\n"+
         "better used as a tool upon the dead.\n");
set_class(17);
set_weight(1);
set_value(200);
}
