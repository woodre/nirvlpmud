
inherit "obj/armor";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("jacket") ;
	set_alias("armor");
	set_short("An bullet-proof jacket") ;
        set_long("It's a heavy bullet-proof jacket. Wear it.\n") ;
        set_weight(3) ;
        set_value(500);
	set_type("armor") ;
        set_ac(3) ;
}

