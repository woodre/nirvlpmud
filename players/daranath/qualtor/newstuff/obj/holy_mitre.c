inherit "obj/armor";

reset(arg){
   ::reset(arg);

set_name("Holy Mitre");
set_short("Holy Mitre");
set_alias("mitre");
set_long("A large hat worn by the holy priests that used to walk Qual'tors temples\n"+
         "the Mitre has the symbol of the city emblazened in gold.\n");
set_type("helmet");
set_ac(2);
set_weight(1);
set_value(3175);
}

query_save_flag() {return 1;}

