 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("club");
    set_alias("spiked club");
    set_short("A wicked spiked club");
    set_long("The club has a wicked looking set of spiked protruding from\n"+
             "its business end. A vicious looking weapon.\n");
    set_class(12);
    set_weight(2);
    set_value(400);
}
