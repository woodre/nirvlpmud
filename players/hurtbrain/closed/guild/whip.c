
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("whip");
	set_alias("firewhip");
	set_short("A firewhip") ;
        set_long("This is a firewhip. There is the UNDEAD symbol on it.\nType 'no_whip' to destruct that.\n") ;
        set_weight(2) ;
        set_value(0);
	set_class(16) ;
}

init()  {
       ::init();
	add_action("no_whip","no_whip");
	}

drop()   { return 1; }

no_whip()  {
        write("Your whip turns to dust.\n");
	destruct(this_object());
	return 1;
	}
