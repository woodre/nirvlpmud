reset(arg)
{
    if (!arg)
	set_light(1);
    extra_reset();
}

extra_reset()
{
    object diaper, weapon;
    int n,i,class,value,weight;
    string w_name,alt_name;

    i = 0;
    if (!present("diaper")) {
	while(i<4) {
	    i += 1;
	    diaper = clone_object("obj/monster");
	    call_other(diaper, "set_name", "diaper");
	    call_other(diaper, "set_alias", "diaper");
	    call_other(diaper, "set_race", "diaper");
	    call_other(diaper, "set_hp", 30);
	    call_other(diaper, "set_al", 50);
	    call_other(diaper, "set_short", "A diaper");
	    call_other(diaper, "set_ac", 0);
	    call_other(diaper, "set_aggressive", 1);
            call_other(diaper, "set_level", random(2) + 1);
	    call_other(diaper, "set_a_chat_chance", 20);
	    call_other(diaper, "load_a_chat", "Diaper shouts: NAHHHHHHHHH!\n");
	    call_other(diaper, "load_a_chat", "Diaper says: Look Ma`,  no hands!\n");
	    call_other(diaper, "load_a_chat", "Diaper cries: I hate pins!\n");
	    call_other(diaper, "load_a_chat", "Diaper whines: Where is my baby?!\n");
	    call_other(diaper, "load_a_chat", 
		"Diaper says: I`m gonna tell my Mommy!\n");
	    n = random(3);
	    weapon = clone_object("obj/weapon");
	    if (n == 0) {
		w_name = "baby pin";
		class = 5;
		value = 8;
		weight = 1;
                alt_name = "pin";
	    }
	    if (n == 1) {
		w_name = "baby powder";
		class = 6;
		value = 15;
		weight = 1;
		alt_name = "powder";
	    }
	    if (n == 2) {
		w_name = "baby rattle";
		class = 7;
		value = 25;
		weight = 1;
		alt_name = "rattle";
	    }
	    call_other(weapon, "set_name", w_name);
	    call_other(weapon, "set_class", class);
	    call_other(weapon, "set_value", value);
	    call_other(weapon, "set_weight", weight);
	    call_other(weapon, "set_alt_name", alt_name);
	    transfer(weapon, diaper);
	    call_other(diaper,"init_command", "wield " + w_name);
	    move_object(diaper, this_object());
	}
    }
}
init()
{
    add_action("north","north");
}


north()
{
    call_other(this_player(),"move_player", "north#players/mistress/child/play.c");
    return 1;
}

long()
{
    write("\nThis is the weirdest diaper change room you have ever seen.\n");
    write("There is an exit back to the hall to the north.\n");
}

short() {
    return "The diaper change room";
}
