
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("net");
	set_short("A combat net") ;
        set_long("This is a combat net used to block your enemies.\n") ;
        set_weight(2) ;
        set_value(150);
	set_class(8) ;
}
