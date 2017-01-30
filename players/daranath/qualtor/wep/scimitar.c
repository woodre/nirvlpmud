 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("steel scimitar");
    set_alias("scimitar");
    set_type("sword");
    set_short("A steel scimitar");
    set_long("The scimitar is made from a strong steel. A good cutting weapon.\n");
    set_class(10);
    set_weight(2);
    set_value(125);
}
