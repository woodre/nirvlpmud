inherit "obj/armor";

reset(arg){
   ::reset(arg);
   set_short("Black shield");
   set_long("This is a small, but efficient\n"+
      "shield. Etched into its surface\n"+
      "is the likeness of a snarling\n"+
      "wolf.\n");
   set_ac(560);
   set_weight(2);
   set_value(400);
   set_alias("shield");
   set_name("shield");
   set_type("shield");
}
