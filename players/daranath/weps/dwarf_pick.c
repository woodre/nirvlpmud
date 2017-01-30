 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("pick");
    set_alias("war pick");
    set_short("A blackened dwarven war pick");
    set_long("A sturdy pick used in times of war within dwarven lore,\n"+
             "the war pick has been blackened from use.\n");
    set_class(15);
    set_weight(1);
    set_value(850);
}
