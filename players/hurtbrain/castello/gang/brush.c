
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("brush");
        set_short("A shoe-brush") ;
        set_long("This is a simple shoe-brush used to clean shoes. It seems you can wield it.\n") ;
        set_weight(1) ;
        set_value(150);
        set_class(8) ;
}

