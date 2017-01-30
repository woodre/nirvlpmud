int w;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("club");
    set_alias("stone club");
    set_short("A wicked stone club");
    set_long("A massive club made from stone, this weapon not only does a\n"+
             "major amount of damage, but it weighs more then most weapons do.\n");
    set_class(17);
    set_weight(5);
    set_value(850);
}
