 inherit "obj/weapon.c";
 reset(arg) {
   ::reset(arg);
    if (arg) return;
   set_name("morning star");
   set_alias("star");
    set_type("mace");         /* set type added by Pavlik */
   set_short("A morning star");
   set_long("A wicked looking morning star.\n");
    set_class(16);
    set_weight(3);
    set_value(400);
}
