
inherit "obj/armor";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("ring") ;
	set_short("A golden ring") ;
        set_long("A protection ring. It has strange inscriptions.\n") ;
        set_weight(1) ;
        set_value(400);
	set_type("ring") ;
        set_ac(1) ;
}
