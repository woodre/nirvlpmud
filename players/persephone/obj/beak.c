inherit "obj/weapon.c";
reset(arg) {
    ::reset();
    if (arg) return;
    set_name("beak");
    set_alias("sword");
    set_short("A Woodpeckers Beak");
    set_long("A beak that looks like it would make a reasonable weapon\n");
    set_class(10);
    set_weight(1);
    set_value(150);
    set_hit_func(this_object());
}
