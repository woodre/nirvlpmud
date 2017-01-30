inherit "obj/weapon.c";
reset(arg) {
    ::reset();
    if (arg) return;
    set_name("cutlass");
    set_alias("sword");
    set_short("A cutlass");
    set_long("A sharp cutlass, used by pirates instead of long swords\n");
    set_class(13);
    set_weight(2);
    set_value(650);
    set_hit_func(this_object());
}
