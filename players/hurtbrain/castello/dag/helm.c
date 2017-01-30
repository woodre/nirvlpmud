
inherit "obj/armor";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("helmet") ;
	set_short("Gladiator's helmet") ;
        set_long("This is a gladiator's helmet.\n") ;
        set_weight(1) ;
        set_value(120);
	set_type("helmet") ;
        set_ac(1) ;
}
