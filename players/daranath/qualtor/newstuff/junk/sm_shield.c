inherit "obj/armor";

reset(arg){
   ::reset(arg);

set_name("small shield");
set_short("A small metal shield");
set_alias("shield");
set_long("A small, round metallic shield. Simple, yet effective, way of\n"+
         "protecting yourself during a fight. Very boring however.\n");
set_type("shield");
set_ac(1);
set_weight(1);
set_value(50);
}
