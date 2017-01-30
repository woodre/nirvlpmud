
inherit "obj/armor";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("scarf");
	set_alias("feathers");
        set_short("A scarf of ostrich feathers") ;
        set_long("An eccentric scarf made of ostrich feathers.\n") ;
        set_weight(1) ;
        set_value(200);
	set_type("amulet");
        set_ac(1) ;
}
