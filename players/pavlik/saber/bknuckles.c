 inherit "obj/weapon.c";
 reset(arg) {
   ::reset(arg);
    if (arg) return;
   set_name("brass knuckles");
   set_alias("knuckles");
   set_type("knuckles");         /* set type added by Pavlik */
   set_short("Brass knuckles");
   set_long("A wicked looking set of brass knuckles\n");
   set_class(9);
   set_weight(1);
   set_value(50);
}
