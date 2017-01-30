inherit "obj/armor";

reset(arg){
    ::reset(arg);
    if (arg) return;
    set_short("Elder's garb");
    set_long("\
Robes that are tailored a bit more for comfort than use, they are\n\
still quite flexible, as the Elders enjoy sparring from time to time.\n");
    set_ac(4);
    set_weight(2);
    set_value(3500);
    set_alias("garb");
    set_name("garb");
    set_type("armor");
}
