
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("block");
        set_short("A very big block") ;
        set_long("This is an extremely heavy block. Who can carry it?\n") ;
        set_weight(5) ;
        set_value(2000);
        set_class(18) ;
}
