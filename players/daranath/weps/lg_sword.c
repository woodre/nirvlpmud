 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("sword");
    set_alias("long");
    set_short("A long sword");
    set_long("The sword is a one-handed variety with a long, but very\n"+
             "sharp blade. The hilt is very plain and unordinary.\n");
    set_class(12);
    set_weight(2);
    set_value(275);
}
