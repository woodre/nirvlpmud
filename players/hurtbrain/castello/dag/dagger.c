
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("dagger");
	set_short("A dagger") ;
        set_long("This is a romanic dagger.\n") ;
        set_weight(2) ;
        set_value(200);
	set_class(9) ;
}
