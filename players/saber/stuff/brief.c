 inherit "obj/container.c";
 reset(arg) {
    ::reset();
    if (arg) return;
    set_name("briefcase");
    set_short("A black briefcase");
    set_long("An expensive black leather briefcase.\n");
    set_weight(1);
    set_value(200);
    set_max_weight(10);
}
