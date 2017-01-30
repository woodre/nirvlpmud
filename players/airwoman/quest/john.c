inherit "obj/monster.talk";
 
reset(arg) {
        object onion;
        ::reset (arg);
        if(!arg) {
        set_name("john");                 
        set_alias("john");
        set_short("Onion John");
        set_long("This is Onion John.  He likes to take\n"+
                "good care of his onion fields.  His most\n"+
                "prized possession is the onion he carries\n"+
                "with him.  He would have to die before you\n"+
                "can take that away from him!\n");
 
        set_level(20);
	set_hp(1000);
        set_al(30);
        set_wc(17);
	set_ac(17);
	set_ac(20);
        set_chat_chance(10);
        load_chat("John says:  Howdy! Ya like my onions?\n");
        onion=clone_object("players/airwoman/onion");
        move_object(onion, this_object());
   }
}
