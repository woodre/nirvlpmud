inherit "obj/armor";

reset(arg){
   ::reset(arg);
   set_type("ring");
   set_short("Hades's ring");
   set_long("Hades's ring of infravision.\n");
   set_ac(1);
   set_weight(1);
   set_value(100000);
   set_alias("ring");
   set_name("ring");
   set_light(6);
}
id(str){return str == "infravision" || str == "ring";}
