 inherit "obj/weapon.c";
 reset(arg) {
  ::reset(arg);
    if (arg) return;
    set_name("longsword");
   set_alias("sword");
   set_type("sword");         /* set type added by Pavlik */
   set_short("A fine steel longsword");
   set_long("A longsword forged from fine steel.\n");
    set_class(15);
    set_weight(2);
    set_value(375);
}
