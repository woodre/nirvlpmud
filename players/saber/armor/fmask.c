inherit "obj/armor";
reset(arg){
   ::reset(arg);
  if(arg) return;
   set_name("face mask");
   set_short("A black face mask");
   set_alias("mask");
   set_long("A black cloth face mask.\n");
   set_type("helmet");
   set_ac(1);
   set_weight(1);
   set_value(10);
}
