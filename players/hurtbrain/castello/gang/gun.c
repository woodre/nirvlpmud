
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("gun");
        set_short("A gun") ;
        set_long("You can see that this gun has not been used for years.\n") ;
        set_weight(1) ;
        set_value(250);
        set_class(11) ;
}

