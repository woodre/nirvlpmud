 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("tool");
    set_alias("sickle");
    set_short("A two-handed sickle");
    set_long("A rusted sickle that is used in controling and harvesting\n"+
             "the farmlands here. It is not worth much as a weapon.\n");
    set_class(9);
    set_weight(2);
    set_value(250);
}
