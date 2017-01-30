
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("gun");
        set_short("A machine gun") ;
        set_long("This is a very dangerous machine gun. Be careful.\n") ;
        set_weight(2) ;
        set_value(400);
        set_class(13) ;
}

