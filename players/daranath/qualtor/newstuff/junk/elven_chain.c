inherit "obj/armor";

reset(arg){
  ::reset(arg);
                  
  set_name("elven chain");
  set_short("A bodysuit of elven chainmail");
  set_alias("chainmail");
  set_long("Elven Chainmail, strong yet extremly thin. Very valuable both in\n"+
           "coin and while fighting.\n");
  set_type("armor");
  set_ac(3);
  set_weight(1);
  set_value(7500);
}

