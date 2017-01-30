 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("hammer");
    set_alias("warhammer");
    set_short("A sturdy metal warhammer");
    set_long("A deadly warhammer with bloody dried on one side of it.\n");
    set_class(12);
    set_weight(2);
    set_value(270);
}
