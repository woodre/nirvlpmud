 inherit "obj/weapon.c";
 reset(arg) {
   ::reset(arg);
    if (arg) return;
    set_name("sword");
    set_short("Sword");
    set_type("sword");         /* set type added by Pavlik */
    set_long("A sword made from fine steel.\n");
    set_class(12);
    set_weight(3);
    set_value(200);
}
