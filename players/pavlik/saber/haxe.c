 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("hand axe");
    set_alias("axe");
    set_type("axe");         /* set type added by Pavlik */
   set_alt_name("handaxe");
   set_short("Hand axe");
   set_long("A well balanced hand axe\n");
    set_class(9);
    set_weight(2);
    set_value(50);
}
