inherit "obj/monster";

int num_donuts,squishees;

object gold;

reset(arg) {
	if (arg) { 
	   num_donuts += random(10);
	   squishees += random(10);        
	   return;
	}
	::reset(arg);
        set_name("Apu");
      set_alias("apu");
        set_short("Apu Nahasapenupetalan");
       set_long(format("This is Apu. He looks like he has had a number of guns "+
			"pointed at him.  I guess that's part of the job.  "+
		        "A job he is dedicated to, nonetheless.  24/7 "+
                "as they call it.\n"+
			"If you want to see what he can sell you, "+
                 "type list.\n", 75));
	set_al(100);
	set_wc(30);
	set_level(20);
	set_hp(1200);
	set_ac(14);
	set_chat_chance(10);
	load_chat("Apu says: Would you like a squishee?\n");
	load_chat("Apu says: Don't look if you aren't going to buy!!\n");
	gold = clone_object("obj/money");
	num_donuts = 20;
	gold->set_money(4000+random(1000));
	move_object(gold, this_object());
}

list_items() {
	say("\n");
	say("Apu says: I sell donut boxes right now.\n");
	say("          I can sell you up to "+num_donuts+" donuts\n");
	say("	  One box of donuts costs 5000 coins\n");
	return 1;
}

buy_item(str) {
	object ob;
	int i;

	i = this_player()->query_money();
	if ((!str) || (!(str == "donuts")))
           return 0;
	if (str == "donuts") {
	   if (i<5000) {
              say("Apu says: Are you trying to cheat me?!?\n");
	      say("          You haven't enough money to buy that.\n");
	      return 1;
	   }
	   if (num_donuts == 0) {
              say("Apu says: I have sold out of donuts!\n");
	      return 1;
	   }
	   ob = clone_object("players/gowron/room/obj/donut");
	   move_object(ob, this_player());
	   this_player()->add_money(-5000);
           say("Apu says: Thank you for buying donuts.\n");
	   num_donuts--;
	   return 1;
	}
	return 0;
}

	
init() {
::init();
	add_action("list_items", "list");
      add_action("buy_item", "buy"); 
}

