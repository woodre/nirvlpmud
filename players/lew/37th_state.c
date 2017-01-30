reset(arg)
{
    if (!arg)
	set_light(1);
    extra_reset();
}

extra_reset()
{
    object banger, weapon;
    int n,i,class,value,weight;
    string w_name,alt_name;

    i = 0;
    if (!present("banger")) {
/* Changed number from 15 to 5. -Snow 8/99  */
	while(i<5) {
	    i += 1;
	    banger = clone_object("obj/monster.talk");
	    call_other(banger, "set_name", "banger");
	    call_other(banger, "set_alias", "gang");
	    call_other(banger, "set_race", "banger");
	    call_other(banger, "set_level", random(15) + 4);
	    call_other(banger, "set_hp", 160);
	    call_other(banger, "set_al", -100);
	    call_other(banger, "set_short", "A gang banger");
	    call_other(banger, "set_ac", 5);
	    call_other(banger, "set_aggressive", 1);
	    call_other(banger, "set_a_chat_chance", 50);
	    call_other(banger, "load_a_chat", "Gang Banger yells: Get his ass!\n");
	    call_other(banger, "load_a_chat", "Gang Banger says: damn peewee!\n");
	    call_other(banger, "load_a_chat", "Gang Banger says: Stop him!\n");
	    call_other(banger, "load_a_chat", "Gang Banger says: Get him!\n");
	    call_other(banger, "load_a_chat", 
		"Gang Banger says: Let's rip out his guts!\n");
	    call_other(banger, "load_a_chat", 
	       "Gang Banger says: Kill him before he runs away!\n");
	    call_other(banger, "load_a_chat", 
	       "Gang Banger says: What is that punk doing here!\n");
	    n = random(3);
	    weapon = clone_object("obj/weapon");
	    if (n == 0) {
		w_name = "switch blade";
		class = 9;
		value = 30;
		weight = 1;
		alt_name = "knife";
	    }
	    if (n == 1) {
		w_name = "bat";
		class = 14;
		value = 50;
		weight = 1;
		alt_name = "bat";
	    }
	    if (n == 2) {
		w_name = "chain";
		class = 12;
		value = 25;
		weight = 1;
		alt_name = "chain";
	    }
	    call_other(weapon, "set_name", w_name);
	    call_other(weapon, "set_class", class);
	    call_other(weapon, "set_value", value);
	    call_other(weapon, "set_weight", weight);
	    call_other(weapon, "set_alt_name", alt_name);
	    transfer(weapon, banger);
	    call_other(banger, "init_command", "wield "+w_name);
	    move_object(banger, this_object());
	}
    }
}
init()
{
    add_action("north","north");
}

north()
{
    if (present("banger") && !this_player()->query_ghost())
    {
	write("An banger bars your way.\n");
	return 1;
    }
    call_other(this_player(), "move_player", "north#/players/lew/36th_state");
    return 1;
}


long() {
  write(""+
"This area seems to be home to a rather large group of Disciples\n" +
", they look real pissed off and you start thinking it wasn't a good idea\n"+
"to come here.\n"+
  "There is a CTA El Platform off to the north.\n");
}

short(){return "Stateway gardens";}

