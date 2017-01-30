inherit "obj/armor";

reset(arg){
    ::reset(arg);
    if (arg) return;
    set_short("Monk's garb");
    set_long("\
A plain, durable, comfortable outfit designed for use rather than\n\
looks. Its design allows for great movement.\n");
    set_ac(3);
    set_weight(3);
    set_value(750);
    set_name("garb");
    set_type("armor");
}
