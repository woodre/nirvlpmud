 inherit "obj/container.c";
 reset(arg) {
    ::reset();
    if (arg) return;
    set_name("sack");
    set_short("A leather sack");
    set_long("A black leather sack.\n");
    set_weight(1);
    set_value(50);
    set_max_weight(10);
}
