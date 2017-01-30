inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("chainmail");
   set_short("A suit of halfling chainmail");
   set_alias("halfling chainmail");
   set_long("A sturdy suit of halfling chain, the armor has been through\n"+
            "a lot of combat about the realms of Nirvana. The chainmail\n"+
            "has shoulder guards built into the framing.\n");
   set_type("armor");
   set_ac(4);
   set_weight(3);
   set_value(1000);
}
