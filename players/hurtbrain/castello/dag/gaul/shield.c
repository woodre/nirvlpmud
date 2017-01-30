
inherit "obj/armor";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("shield") ;
        set_short("A very big shield") ;
        set_long("This is an enornous shield used to carry a gaul chief.\n") ;
        set_weight(2) ;
        set_value(500);
        set_type("shield") ;
        set_ac(1) ;
}
