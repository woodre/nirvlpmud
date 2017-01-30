inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("kobold shield");
   set_short("A small round shield");
   set_alias("shield");
   set_long("A small wooden shield painted to match the tribal tattoos\n"+
            "within the village. It looks somewhat important.\n");
   set_type("shield");
   set_ac(1);
   set_weight(1);
   set_value(50);
}
