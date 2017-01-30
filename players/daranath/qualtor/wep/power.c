 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("elemental power");
    set_type("energy");
    set_alias("power");
    set_short("Elemental Power");
    set_long("The power of the element of Crystal.\n");
    set_class(16);
    set_weight(2);
    set_value(1000);
}
