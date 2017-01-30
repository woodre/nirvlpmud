

inherit "obj/armor";

reset(arg) {
    if(!arg)
    ::reset(arg);
    set_name("chainmail");
    set_alias("armor");
    set_short("chainmail");
    set_long("A worn out and dented suit of chainmail.\n");
    set_ac(3);
    set_value(500);
    set_weight(3);
    set_type("armor");
}

