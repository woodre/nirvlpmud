 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("dagger");
    set_alias("black dagger");
    set_short("A wicked dagger with a blackened blade");
    set_long("The standard weapon of a necromancer, this dagger had a dark\n"+
             "blade that has been corrupted by evil and decay for years.\n");
    set_class(16);
    set_weight(1);
    set_value(250);
}
