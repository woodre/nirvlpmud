 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("white dagger");
    set_type("dagger");
    set_alias("pearl dagger");
    set_short("White pearl hilted dagger");
    set_long("A pristine dagger with a hilt made from white pearl.\n");
    set_class(18);
    set_weight(2);
    set_value(2200);
}
