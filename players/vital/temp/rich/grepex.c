inherit "obj/armor.c";

  reset(arg) {
   ::reset(arg);
      set_name("body armor");
      set_alias("body");
      set_short("Bbeasty Acooney");
      set_long("This is a personal force field.\n");
      set_value(1250);
      set_weight(5);
      set_ac(5);
      set_type("armor");
 }
