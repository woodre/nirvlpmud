/* Aingeal's badass test weapon */

inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("lightning");
    set_alias("bolt");
    set_short("Aingeal's lightning bolt");
    set_long("Aingeal's lightning bolt sparkles brilliantly against the backdrop of darkness.\n");
    set_class(50);
    set_weight(1);
    set_value(1);
    set_hit_func(this_object());
}

