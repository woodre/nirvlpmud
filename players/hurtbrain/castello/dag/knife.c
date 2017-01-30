
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("knife");
	set_short("A sharpened knife") ;
        set_long("This is a very sharpened knife.\n") ;
        set_weight(2) ;
        set_value(1400);
	set_class(17) ;
}
