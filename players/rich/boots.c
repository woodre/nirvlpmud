inherit "obj/armor.c";

  reset(arg) {
   ::reset(arg);
      set_name("standard issue boots");
      set_alias("boots");
      set_short("Standard Issue Boots");
      set_long("These are starfleet standard issue boots.\n");
      set_value(70);
      set_weight(1);
      set_ac(1);
      set_type("boots");
 }
