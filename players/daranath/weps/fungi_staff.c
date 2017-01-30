 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("staff");
    set_alias("skull staff");
    set_short("Skull headed staff");
    set_long("The staff is a two-handed weapon with a skull, set atop\n"+
            "the staff in a menacing fashion.\n");
    set_class(11);
    set_weight(1);
    set_value(275);
}
