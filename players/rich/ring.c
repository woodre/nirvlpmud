inherit "obj/armor.c";

  reset(arg) {
   ::reset(arg);
      set_name("electric ring");
      set_alias("ring");
      set_short("Electric Ring");
      set_long("This is an electric ring.\n");
      set_value(1500);
      set_weight(1);
      set_ac(1);
      set_type("ring");
 }
