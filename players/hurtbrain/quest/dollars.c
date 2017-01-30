
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("dollars");
      set_short("100 dollars");
        set_long("This is a romanic dagger.\n") ;
        set_weight(2) ;
        set_value(200);
}
