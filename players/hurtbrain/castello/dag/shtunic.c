
inherit "obj/armor";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("tunic") ;
	set_alias("armor");
	set_short("A short white tunic") ;
        set_long("This is the tunic that many roman's tribunes worn.\n") ;
        set_weight(2) ;
        set_value(900);
	set_type("armor") ;
        set_ac(3) ;
}
