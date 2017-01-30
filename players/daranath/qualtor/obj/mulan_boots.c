inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("leather boots");
   set_short("A pair of leather boots");
   set_alias("boots");
   set_long("A pair of leather boots that are soaked in blood and are\n"+
            "covered with a thick layer of mud. They cannot be worth\n"+
            "much money at all.\n");
   set_type("boots");
   set_ac(1);
   set_weight(1);
   set_value(75);
}
