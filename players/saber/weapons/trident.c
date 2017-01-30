 inherit "obj/weapon.c";
 reset(arg) {
   ::reset(arg);
    if (arg) return;
    set_name("trident");
    set_type("trident");         /* set type added by Pavlik */
    set_short("A wicked looking trident");
    set_long("A wicked looking trident forged of black iron.\n");
    set_class(16);
    set_weight(3);
    set_value(400);
}
