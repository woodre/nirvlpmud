 inherit "obj/weapon.c";
 reset(arg) {
   ::reset(arg);
    if (arg) return;
    set_name("bastard sword");
   set_alias("sword");
   set_type("sword");         /* set type added by Pavlik */
   set_short("A bastard sword");
    set_long("A massive bastard sword forged from fine steel\n");
    set_class(17);
    set_weight(4);
    set_value(500);
}
