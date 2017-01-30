
inherit "obj/armor";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("buckler") ;
	set_short("A buckler") ;
        set_long("This is gladiator's shield.\n") ;
        set_weight(1) ;
        set_value(150);
	set_type("shield") ;
        set_ac(1) ;
}
