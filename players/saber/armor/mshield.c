inherit "/obj/armor";
reset(arg){
   ::reset(arg);
set_name("magic shield");
set_alias("shield");
set_short("magic shield");
   set_long("An almost invisible magic force shield.\n");
   set_type("shield");
   set_ac(1);
   set_weight(1);
   set_value(1);
}

drop() { return 1; }
get() { return 0; }
