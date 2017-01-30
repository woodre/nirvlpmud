 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("halberd");
    set_alias("pole arm");
    set_short("A halberd");
    set_long("A two-handed pole arm with a wicked cutting blade, the\n"+
             "halberd is a weapon to be reckoned with.\n");
    set_class(14);
    set_weight(3);
    set_value(225);
}
