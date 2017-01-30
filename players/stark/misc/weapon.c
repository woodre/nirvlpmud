 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("rapier");
    set_alias("sword");
    set_short("A slender rapier");
    set_long("A slender rapier made from fine steel.\n");
    set_class(13);
    set_weight(2);
}
