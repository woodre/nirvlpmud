inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("bucket helmet");
   set_short("A standard bucket helmet");
   set_alias("helmet");
   set_long("The helmet is solid steel bucket helmet with a cross-eye\n"+
            "opening for vision.\n");
   set_type("helmet");
   set_ac(1);
   set_weight(1);
   set_value(550);
}
