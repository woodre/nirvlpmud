
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("sword");
       set_type("sword");
	set_short("Caesar's sword") ;
        set_long("This is Giulius' sword. It seems to be powerful.\n") ;
        set_weight(3) ;
        set_value(2500);
	set_class(18) ;
}
