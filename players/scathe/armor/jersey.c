inherit "obj/armor";

reset(arg){
    ::reset(arg);
    if (arg) return;
    set_short("Vince Carter's Jersey");
    set_long("\
A nice Vincer Carter jersey, fresh from his victory over those\n\
lousy New York Knicks!.\n");
    set_ac(0);
    set_weight(3);
    set_value(0);
    set_name("jersey");
    set_type("armor");
}
