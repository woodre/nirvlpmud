int w;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("club");
    set_alias("spiked club");
    set_short("Wicked spiked club");
    set_long("A small club with several spikes sticking from one end.\n");
    set_class(15);
    set_weight(2);
    set_value(100);
}
