
inherit "obj/armor";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("vest") ;
	set_short("A magical vest") ;
        set_long("This is a magical vest. There is the UNDEAD symbol on it.\nType 'no_vest' to destruct that.\n");
        set_weight(2) ;
        set_value(0);
	set_type("armor") ;
        set_ac(2) ;
}

init()  {
       ::init();
	add_action("no_vest","no_vest");
	}

drop()   { return 1; }

no_vest()  {
	write("Your vest turns to dust.\n");
	destruct(this_object());
	return 1;
	}
