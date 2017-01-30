
inherit "obj/armor";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("helmet") ;
	set_short("Centurion's helmet") ;
        set_long("This is a tipical centurion's helmet with red hair crest on it.\n") ;
        set_weight(1) ;
        set_value(600);
	set_type("helmet") ;
        set_ac(1) ;
}
