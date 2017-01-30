 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("wooden club");
    set_alias("club");
    set_type("club");
    set_short("A wooden club");
    set_long("The wooden club is made from an old table leg. Cheap.\n");
    set_class(8);
    set_weight(1);
    set_value(50);
}
