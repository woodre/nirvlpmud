
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("sword");
	set_short("Slaughter's sword") ;
        set_long("This is Erode's sword. There is kid's blood on it.\n") ;
        set_weight(3) ;
        set_value(1500);
	set_class(17) ;
}
