
inherit "obj/armor";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("ring") ;
	set_short("A golden ring") ;
        set_long("This is a ring of protection. You can wear it.\n") ;
        set_weight(1) ;
        set_value(300);
	set_type("ring") ;
        set_ac(1) ;
}

