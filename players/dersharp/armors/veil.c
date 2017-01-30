inherit "obj/armor";

reset(arg){
   ::reset(arg);
   set_short("A small pink veil");
   set_long("This dainty piece of armor is used to hide the beautiful faces\n"+
            "of courtesans.\n");
   set_ac(1);
   set_weight(1);
   set_value(250);
   set_alias("veil");
   set_name("A small pink veil");
   set_type("helmet");
}
