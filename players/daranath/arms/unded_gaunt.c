inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("gauntlets");
   set_short("A pair of darkened gauntlets");
   set_alias("gauntlet");
   set_long("The black leather of the gauntlets is worn and eaten by\n"+
            "worms and other such predators of the dead.\n");
   set_type("ring");
   set_ac(1);
   set_weight(1);
   set_value(500);
}
