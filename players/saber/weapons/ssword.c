 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("short sword");
    set_alias("sword");
    set_type("sword");         /* set type added by Pavlik */
   set_alt_name("shortsword");
   set_short("Short sword");
   set_long("A well sharpened short sword\n");
    set_class(10);
    set_weight(2);
    set_value(200);
}
