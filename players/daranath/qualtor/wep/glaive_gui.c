 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("glaive");
    set_alias("glaive-guisarme");
    set_type("polearm");
    set_short("A Silver Glaive-Guisarme");
    set_long("A wicked pole arm with both a slashing blade and a small hook\n"+
             "to tear the flesh of its oppenent backwards. This silver glaive\n"+
             "is quite valuable to collectors.\n");
    set_class(17);
    set_weight(2);
    set_value(1500);
}
