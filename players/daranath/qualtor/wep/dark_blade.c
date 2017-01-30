#include <ansi.h>
 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("blade");
    set_alias("dark blade");
    set_type("sword");
    set_short(BLK+BOLD+"Dark Blade"+NORM);
    set_long("A blade made from the darkest steel, this blade seems\n"+
             "extremely light and powerful for its size.\n");
    set_class(18);
    set_weight(2);
    set_value(4400);
}
