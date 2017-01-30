 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("spear");
    set_alias("kobold spear");
    set_short("A crude kobold spear");
    set_long("A wooden shaft with a sharpened stone for a spear head.\n");
    set_class(9);
    set_weight(2);
    set_value(150);
}
