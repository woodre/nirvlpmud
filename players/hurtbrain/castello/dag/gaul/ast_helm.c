
inherit "obj/armor";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("helmet") ;
        set_short("Helmet with feather") ;
        set_long("This is Asterix' helmet. It has a feather on his top.\n") ;
        set_weight(2) ;
        set_value(500);
        set_type("helmet") ;
        set_ac(1) ;
}

