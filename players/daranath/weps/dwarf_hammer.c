 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("hammer");
    set_alias("warhammer");
    set_short("A silver edged dwarven warhammer");
    set_long("Dwarven forged by blacksmiths long since dead, the warhammer\n"+
             "has silver viens running throughout the head of the hammer.\n"+
             "A highly valued weapon to any dwarf.\n");
    set_class(15);
    set_weight(2);
    set_value(850);
}
