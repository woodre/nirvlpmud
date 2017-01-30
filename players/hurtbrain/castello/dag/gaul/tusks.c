
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("tusks");
        set_short("Elephant's tusks") ;
        set_long("These are elephants tusks. They are heavy.\n") ;
        set_weight(3) ;
        set_value(1500);
        set_class(17) ;
}
