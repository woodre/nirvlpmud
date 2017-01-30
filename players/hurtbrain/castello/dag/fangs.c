
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("fangs");
	set_short("Viper's fangs") ;
        set_long("This are viper's fangs. They are coated with poison.\n") ;
        set_weight(2) ;
        set_value(1000);
	set_class(16) ;
}
