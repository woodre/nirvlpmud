 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("sword");
    set_alias("short");
    set_short("A short sword");
     set_long("The sword is a one-handed variety with a short, but very\n"+
               "sharp blade. The hilt is very plain and unordinary.\n");
    set_class(11);
    set_weight(1);
    set_value(175);
}
