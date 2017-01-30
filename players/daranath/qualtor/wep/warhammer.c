 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("warhammer");
    set_alias("dwarven warhammer");
    set_type("hammer");
    set_short("A dwarven warhammer");
    set_long("Dwarven warhammers are known for both thier strength and\n"+
             "the sheer amount of damage they can dish out.\n");
    set_class(12);
    set_weight(2);
    set_value(250);
}
