int w;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("club");
    set_alias("spiked club");
    set_short("A HUGE spiked club");
    set_long("This is what seems to be half a tree, with several\n"+
             "spikes protruding from one end.\n");
    set_class(17);
    set_weight(5);
    set_value(800);
}
