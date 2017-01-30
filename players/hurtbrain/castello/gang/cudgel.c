
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("cudgel");
        set_short("Policeman's cudgel") ;
        set_long("This is the tipical cudgel used by the policemen.\n") ;
        set_weight(1) ;
        set_value(350);
        set_class(12) ;
}

