inherit "obj/armor.c";

  reset(arg) {
   ::reset(arg);
      set_name("dilithium crystal");
      set_alias("crystal");
      set_short("Dilithium Crystal");
      set_long("This is a dilithium crystal.\n");
      set_value(2000);
      set_weight(2);
      set_ac(1);
      set_type("amulet");
 }
