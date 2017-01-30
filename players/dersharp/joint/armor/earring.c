inherit "obj/armor";
reset(arg) {
   ::reset(arg);
   set_short("A dangly-earring");
   set_alias("earring");
   set_long("This once belonged to Vince of Tremors.  You can still see\n"+
            "blood on it from the battle to get it!\n");
   set_ac(1);
   set_value(300);
   set_type("misc");
   set_name("earring");
}
