

inherit "obj/armor";

reset(arg) {
    if(!arg)
    ::reset(arg);
    set_name("leather armor");
    set_alias("leather");
    set_short("A suit of leather armor");
    set_ac(1);
    set_weight(2);
    set_long("A finely crafted suit of leather armor with an insignia of a "+
             "hawk at the left shoulder.\n");
    set_value(150);
}

