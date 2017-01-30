
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("rifle");
        set_short("A bright rifle") ;
        set_long("This is a professional rifle. You will not miss a shot.\n") ;
        set_weight(1) ;
        set_value(300);
        set_class(11) ;
}

