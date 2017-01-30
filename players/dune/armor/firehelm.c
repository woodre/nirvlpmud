inherit "obj/armor";

reset(arg){
   ::reset(arg);
   set_name("fire helm");
   set_short("A fire helmet");
   set_alias("helmet");
   set_long("This is a helmet made of pure fire.\n"+
            "Though you think it would burn your\n"+
            "head off, it does not feel hot at all.\n");
   set_type("helmet");
   set_ac(random(2)+1);
  set_params("other|fire",0,10,0);
  set_params("other|ice",0,-10,0);
   set_weight(2);
   set_value(100);
}
