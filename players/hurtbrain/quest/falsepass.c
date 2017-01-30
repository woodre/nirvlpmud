
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("passport");
        set_short("A false passport") ;
        set_long("Mr Smith's passport.\n") ;
        set_weight(2) ;
        set_value(200);
}
