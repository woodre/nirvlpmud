
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("staff");
        set_short("Staff of the wizards") ;
      set_long("This is the staff of the wizards. Only mighty one have it.\n") ;
        set_weight(2) ;
        set_value(1500);
        set_class(17) ;
}
