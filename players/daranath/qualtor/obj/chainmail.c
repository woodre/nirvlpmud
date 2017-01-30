inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("chainmail");
   set_short("A suit of chainmail armor");
   set_alias("chain");
   set_long("A suit of chainmail. Gives good protection in a fight.\n");
   set_type("armor");
   set_ac(3);
   set_weight(2);
   set_value(300);
}
