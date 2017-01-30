 inherit "obj/weapon.c";
 reset(arg) {
   ::reset(arg);
    if (arg) return;
    set_name("broadsword");
    set_alias("sword");
    set_type("sword");         /* set type added by Pavlik */
    set_alt_name("broad sword");
    set_short("Broadsword");
    set_long("A broadsword made from fine steel\n");
    set_class(12);
    set_weight(3);
    set_value(400);
}
