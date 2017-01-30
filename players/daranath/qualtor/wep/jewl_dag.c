 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("jeweled dagger");
    set_type("dagger");
    set_alias("jeweled");
    set_short("Jeweled dagger");
    set_long("The dagger has jewels set into it at every possible place the\n"+
             "weapon smith could fit one. Most are diamonds, which are\n"+
             "also used to line the cutting edge, giving the dagger\n"+
             "incredible strength for such a small weapon.\n");
    set_class(18);
    set_weight(2);
    set_value(11700);
}
