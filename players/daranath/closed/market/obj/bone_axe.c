#include <ansi.h>
 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("Bone Axe");
set_type("axe");
set_alias("battleaxe");
set_short(WHT+"Bone laced Battleaxe"+NORM);
set_long("A mitril handle runs up to a wide blade made of pure bone, strengthen\n"+
         "magically, and then diamond edged to give this axe a bite as \n"+
         "sharp as steel. The axe itself is simply gruesome to look at.\n");
set_class(20);
set_weight(2);
set_value(3500+random(1000));
}
