 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("rapier");
    set_type("sword");         /* set type added by Pavlik */
   set_short("A slender rapier");
   set_long("A slender rapier made from fine steel.\n");
    set_class(13);
    set_weight(2);
    set_value(450);
}
