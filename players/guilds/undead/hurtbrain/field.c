
inherit "obj/armor";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("field") ;
	set_short("A force field") ;
        set_long("This is a force field. There is the UNDEAD symbol on it.\nType 'no_field' to destruct that.\n");
        set_weight(2) ;
        set_value(0);
	set_type("armor") ;
        set_ac(3) ;
}

init()  {
       ::init();
	add_action("no_field","no_field");
	}

drop()   { return 1; }

no_field()  {
	write("Your field turns to dust.\n");
	destruct(this_object());
	return 1;
	}
