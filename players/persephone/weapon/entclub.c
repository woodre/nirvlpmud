inherit "obj/weapon.c";
reset(arg) {
    ::reset();
    if (arg) return;
    set_name("club");
    set_alias("branch");
    set_short("A large wooden club");
    set_long("A wooden club actually a tree limb would be more apt a description.\n");
    set_class(15);
    set_weight(3);
    set_value(20000);
    set_hit_func(this_object());
}
