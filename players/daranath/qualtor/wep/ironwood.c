 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("ironwood quarterstaff");
    set_alias("quarterstaff");
    set_type("staff");
    set_short("IronWood Quarterstaff");
    set_long("The IronWood quarterstaff is weapon magically enhanced from the\n"+
             "IronWood forest. The forest has been lost to Nirvana for\n"+
             "years, no one knowing where the forest lies.\n");
    set_class(17);
    set_weight(2);
    set_value(1400);
}
