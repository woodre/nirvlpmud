 inherit "obj/weapon.c";
 reset(arg) {
    ::reset();
    if (arg) return;
    set_name("battle axe");
    set_alias("axe");
    set_type("axe");         /* set type added by Pavlik */
    set_short("A battle axe");
     set_long("A wide bladed battle axe forged from fine steel.\n");
    set_class(15);
    set_save_flag(0);
    set_weight(3);
    set_value(500);
}
