
inherit "obj/armor";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("hat");
	set_alias("top-hat");
        set_short("A top-hat") ;
        set_long("A dark blue top-hat. You don't notice anything strange.\n") ;
        set_weight(1) ;
        set_value(200);
	set_type("helmet");
        set_ac(1) ;
}

