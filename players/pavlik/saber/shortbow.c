 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("short bow");
    set_alias("bow");
   set_alt_name("shortbow");
    set_type("bow");         /* set type added by Pavlik */
   set_short("Short bow");
   set_long("A sturdy looking short bow\n");
    set_class(12);
    set_weight(2);
    set_value(150);
}
