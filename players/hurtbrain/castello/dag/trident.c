
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("trident");
	set_short("A trident") ;
        set_long("This is a huge trident.\n") ;
        set_weight(2) ;
        set_value(150);
	set_class(8) ;
}
