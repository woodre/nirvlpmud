inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("chainmail");
   set_short("A suit of dwarven chainmail");
   set_alias("chain");
   set_long("A sturdy suit of dwarven chain, the armor has been through\n"+
            "a lot of combat about the realms of Nirvana. The chainmail\n"+
            "has shoulder guards built into the framing.\n");
   set_type("armor");
   set_ac(4);
   set_weight(2);
   set_value(1000);
}
