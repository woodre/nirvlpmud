
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("knife");
        set_short("A pocket knife") ;
        set_long("A pocket knife with a very sharpened blade.\n") ;
        set_weight(1) ;
        set_value(200);
        set_class(10) ;
}

