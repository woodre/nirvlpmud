
inherit "obj/armor";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("necklace") ;
	set_short("A silver necklace") ;
        set_long("This is a silver necklace. It seems to glow.\n") ;
        set_weight(1) ;
        set_value(400);
	set_type("amulet") ;
        set_ac(1) ;
}
