 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("dagger");
    set_alias("rusty");
    set_short("A rusty dagger");
    set_long("The dagger has a rusted blade, making it almost useless.\n");
    set_class(7);
    set_weight(1);
    set_value(90);
}
