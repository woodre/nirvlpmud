inherit "obj/armor";

reset(arg){
   ::reset(arg);
   set_name("vapor boots");
   set_short("A pair of vapor boots");
   set_alias("boots");
   set_long("The vapor boots are made of air, yet they\n"+
            "have form and are very light.\n");
   set_type("boots");
   set_ac(random(2)+1);
  set_params("other|air",0,10,0);
  set_params("other|earth",0,-10,0);
   set_weight(1);
   set_value(100);
}
