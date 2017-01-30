 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("maul");
    set_alias("kobold maul");
    set_short("A heavy black maul");
    set_long("A two handed weapon for the kobold king, the maul could be\n"+
             "wielded by a strong individual with one hand. It looks like\n"+
             "an overgrown hammer with an elongated shaft for power.\n");
    set_class(15);
    set_weight(3);
    set_value(550);
}
