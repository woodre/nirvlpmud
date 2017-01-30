#include <ansi.h>
 inherit "obj/container.c";
 reset(arg) {
    ::reset();
    if (arg) return;

set_name("sack");
set_short(YEL+"A sack made from human skin"+NORM);
set_long("Pieces and parts of human skin, sewn together to form a large sack,\n"+
         "then magically imbued to have a large carrying capacity.\n");
set_weight(1);
set_value(500+random(200));
set_max_weight(35);
}
