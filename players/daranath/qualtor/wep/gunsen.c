 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("gunsen");
    set_alias("fan");
    set_type("fan");
    set_short("A dark red Gunsen");
    set_long("More a tool then a weapon, the Gunsen is a small iron fan\n"+
             "commonly carried by women within the Crimson Guard.\n");
    set_class(15);
    set_weight(2);
    set_value(700);
}
