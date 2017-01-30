

inherit "obj/armor";

reset(arg) {
    if(!arg)
    ::reset(arg);
    set_name("leather armor");
    set_alias("leather");
    set_short("A suit of orc leather armor");
    set_ac(1);
    set_weight(2);
    set_long("A piece of rank smelling and looking armor.\n");
    set_value(100);
}

