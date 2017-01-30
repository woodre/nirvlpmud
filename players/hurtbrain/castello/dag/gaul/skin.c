
inherit "obj/armor";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("skin") ;
        set_short("An elephant skin") ;
        set_long("This is a skin of an elephant. Perhaps you can wear it.\n") ;
        set_weight(4) ;
        set_value(1500);
        set_type("armor") ;
        set_ac(4) ;
}
