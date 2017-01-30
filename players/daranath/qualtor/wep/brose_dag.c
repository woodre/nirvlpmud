 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("black rose dagger");
    set_type("dagger");
    set_alias("rose dagger");
    set_short("Black Rose hilted dagger");
    set_long("An extremely well made dagger, the hilt of the weapon is\n"+
             "inscribed with a black rose winding around its base.\n");
    set_class(15);
    set_weight(1);
    set_value(650);
}
