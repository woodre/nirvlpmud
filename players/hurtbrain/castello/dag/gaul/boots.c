
inherit "obj/armor";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("boots") ;
        set_short("A pair of boots") ;
        set_long("These are a normal pair of boots.\n") ;
        set_weight(2) ;
        set_value(500);
        set_type("boots") ;
        set_ac(1) ;
}
