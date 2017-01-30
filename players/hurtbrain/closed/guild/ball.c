
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("ball");
	set_alias("fire");
	set_short("A ball of fire") ;
        set_long("This is a ball of fire. There is the UNDEAD symbol on it.\nType 'no_ball' to destruct that.\n") ;
        set_weight(1) ;
        set_value(0);
	set_class(10) ;
}

init()  {
       ::init();
	add_action("no_ball","no_ball");
	}

drop()   { return 1; }

no_ball()  {
        write("Your ball turns to dust.\n");
	destruct(this_object());
	return 1;
	}
