 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("blade");
    set_alias("sword");
    set_short("A silver blade");
    set_long("The silver of the blade has been tempered by the presence\n"+
             "of undead for so many years.\n");
    set_class(15);
    set_weight(2);
    set_value(850);
}
