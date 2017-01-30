inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("chainmail");
   set_short("A suit of darkened chainmail");
   set_alias("darkened chainmail");
   set_long("Once worn by one of the nobles within Nirvana's realm, the\n"+
            "chain has been influcenced by the undead from which it came.\n"+
            "The chain is no longer its shining silver color, having an\n"+
            "ashen look to it now.\n");
   set_type("armor");
   set_ac(4);
   set_weight(3);
   set_value(1000);
}
