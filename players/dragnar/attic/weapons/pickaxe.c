inherit "obj/weapon";

void
reset(int arg) {
    ::reset(arg);
    if (arg) return;
    set_name("pick axe");
    set_alias("axe");
    set_short("Pick Axe");
    set_long("The axe from the grave digger.\n");
    set_class(12);
    set_value(1000);
    set_weight(4);
}
