 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("spear");
    set_alias("black spear");
    set_short("A darkened spear");
    set_long("The silver of the blade has been tempered by the presence\n"+
             "of undead for so many years.\n");
    set_class(15);
    set_weight(2);
    set_value(850);
}
