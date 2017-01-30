inherit "obj/monster.talk";
object bowl;
 
reset(arg) {
  
        ::reset(arg);
        if(!arg) {
        set_name("guru");
        set_level(10);
        set_al(0);
        set_short("The Almighty Guru Brahmin");
        set_long("This is a very wise man.\n"+
                "Maybe he knows about the blind boy\n"+
                "Why dont you try ASKing him?\n");
        set_aggressive(0);
        set_wc(14);
        set_ac(8);

	set_chat_chance(10);
	load_chat("Guru says: Welcome idiots!\n");
 }
}
                              
init () {
        add_action("ask_guru", "ask");  
        ::init();
}
 
ask_guru(str)
{    
     bowl = clone_object("players/airwoman/bowl");   
     if(str == "guru")                       
     {if(!present("bowl", this_player()))
        move_object(bowl, this_player());
        write("Guru says:  Thank you for asking me.\n"+
        "Guru says:  Basically you must retrieve the tears\n"+
        "from heaven with this bowl i have given to you.\n"+
        "You must go to the highest point of the mountain\n"+
        "and collect the tears of heaven.\n"+
        "By the way, somehow you must make heaven cry in\n"+
        "order to collect the tears.  With the tears you\n"+
        "can save the blind boy...really....\n");
	return 1;
        }
 
}  
