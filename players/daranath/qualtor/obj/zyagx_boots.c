inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("rubber boots");
   set_short("A pair of rubber, grime covered boots");
   set_alias("boots");
   set_long("A pair of rubber boots, with a thick layer of grime, blood\n"+
            "chemicals and other substances not identifiable here.\n");
   set_type("boots");
   set_ac(1);
   set_weight(1);
   set_value(800);
}
