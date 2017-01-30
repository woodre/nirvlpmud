 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("hook");
    set_alias("demon hook");
    set_short("A sharp demonic meat hook");
    set_long("A sharpened meat hook that someone took and made into a\n"+
             "greusome looking weapon, this item has a wooden crosspiece\n"+
             "for support and a bloody metal point.\n");
    set_class(15);
    set_weight(2);
    set_value(650);
}
