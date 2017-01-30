inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("leather boots");
   set_short("Black leather boots");
   set_alias("boots");
   set_long("A pair of leather boots dyed black.\n");
   set_type("boots");
   set_ac(2);
   set_weight(1);
   set_value(150);
}

query_save_flag() {return 1; }
