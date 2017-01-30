
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("singolar");
        set_short("A true passport") ;
        set_long("Mr Bond's passport.\n") ;
        set_weight(2) ;
        set_value(200);
}
