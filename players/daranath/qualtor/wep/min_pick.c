 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("mining pick");
    set_alias("pick");
    set_type("pick");
    set_short("A dwarven mining pick");
    set_long("Generally used as a tool more then a weapon, the mining\n"+
             "can still dish out a tremendous amount of damage.\n");
    set_class(13);
    set_weight(2);
    set_value(300);
}
