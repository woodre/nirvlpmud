
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("gladio");
	set_short("A gladio") ;
        set_long("This is a short sword used in gladiator's fighting.\n") ;
        set_weight(2) ;
        set_value(150);
	set_class(8) ;
}
