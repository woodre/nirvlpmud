inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("dress");
   set_short("A crushed velvet dress");
   set_alias("velvet");
   set_long("A crushed velvet dress that clings to the curves of your body.\n"+
            "It has a long slit that accents the legs, showing just a\n"+
            "a bit more then it should.\n");
   set_type("armor");
   set_ac(2);
   set_weight(1);
   set_value(150);
}
