 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("naginata");
    set_alias("nagi");
    set_type("polearm");
    set_short("A Wicked Naginata");
    set_long("A long pole arm with a curved blade at its tip, the naginata\n"+
             "is the basic weapon amongst the Crimson Guard.\n");
    set_class(15);
    set_weight(2);
    set_value(900);
}
