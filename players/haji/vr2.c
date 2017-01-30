#include "std.h"
#define HARRY 1

int count;

#undef EXTRA_INIT
#define EXTRA_INIT\
    add_action("down","down");
#if HARRY
object bill;
#undef EXTRA_RESET
#define EXTRA_RESET\
    if (!present("bill"))\
        starta_bill();
#endif

FOUR_EXIT("room/vill_road1","west",
	 "room/vill_road3","east",
	 "room/adv_guild","south",
	 "room/shop","north",
	 "Village road",
 "A long road going through the village.\n" +
 "There are stairs going down.\n"
 , 1)

#if HARRY
starta_bill() {
    if(!bill || !living(bill)) {
	bill = clone_object("obj/monster");
	call_other(bill, "set_name", "bill");
	call_other(bill, "set_alias", "fjant");
	call_other(bill, "set_short", "Bill Clinton the horny pervert");
	call_other(bill, "set_long", "Bill really wants to have sex with you.\n");
	call_other(bill, "set_ac", 0);
	call_other(bill, "set_level",3);
	call_other(bill, "set_al",50);
	call_other(bill, "set_ep",2283);
	call_other(bill, "set_hp",30);
	call_other(bill, "set_wc",5);
	call_other(bill, "set_aggressive", 0);
	move_object(bill, "room/vill_road2");
	call_other(bill, "set_object", this_object());
	call_other(bill, "set_function", "why_did");
	call_other(bill, "set_type", "sells");
	call_other(bill, "set_match", " ");
	call_other(bill, "set_type", "attack");
	call_other(bill, "set_match", " ");
	call_other(bill, "set_type", "left");
	call_other(bill, "set_match", "the game");
	call_other(bill, "set_type", "takes");
	call_other(bill, "set_match", " ");
	call_other(bill, "set_type", "drops");
	call_other(bill, "set_match", " ");
	call_other(bill, "set_function", "how_does_it_feel");
	call_other(bill, "set_type", "is now level");
	call_other(bill, "set_match", " ");
	call_other(bill, "set_function", "smiles");
	call_other(bill, "set_type", "smiles");
	call_other(bill, "set_match", " happily.");
	call_other(bill, "set_function", "say_hello");
	call_other(bill, "set_type", "arrives");
	call_other(bill, "set_match", "");
	call_other(bill, "set_function", "test_say");
	call_other(bill, "set_type", "says:");
	call_other(bill, "set_match", " ");
	call_other(bill, "set_type", "tells you:");
	call_other(bill, "set_match", " ");
	call_other(bill, "set_function", "follow");
	call_other(bill, "set_type", "leaves");
	call_other(bill, "set_match", " "); 
	call_other(bill, "set_function", "gives");
	call_other(bill, "set_type", "gives");
	call_other(bill, "set_match", " ");
	
	call_other(bill, "set_chat_chance", 85);
	call_other(bill, "set_a_chat_chance", 33);
	call_other(bill, "load_chat", "Bill says: What are you waiting for?" +
 "I really want to fuck you now!!!!\n");
	call_other(bill, "load_chat", "Bill says: " +
		   "Go fuck yourself!!!\n");
	call_other(bill, "load_chat", "Bill says: " +
		   "Bend over so we can have some fun!!!!!!\n");
	call_other(bill, "load_chat", "Bill says: " +
		   "I don't like condoms.\n");
	call_other(bill, "load_chat", "Bill says: " +
		   "I feel really horny.\n");
	call_other(bill, "load_chat", "Bill says: " +
		   "What can I do for you or more to the point to you?\n");
	call_other(bill, "load_chat", "Bill says: " +
		   "Is that your real face, or is it a mask?\n");
	call_other(bill, "load_chat", "Bill says: " +
		   "What are you doing here?\n");
	call_other(bill, "load_chat", "Bill says: " +
		   "Quit playing with yourself!!!!!\n");
	call_other(bill, "load_chat", 
		   "Bill checks out your bod.\n");
	call_other(bill, "load_a_chat", "Bill says: " +
		   "Whip me beat me make me write bad checks!!!!!!\n");
	call_other(bill, "load_a_chat", "Bill says: " +
		   "That hurt do it again!!!!\n");
	call_other(bill, "load_a_chat", "Bill says: " +
		   "Help, someone, I need sex now!!!!!\n");
	call_other(bill, "load_a_chat", "Bill says: " +
		   "Why can't you go masterbate elsewhere?\n");
	call_other(bill, "load_a_chat", "Bill says: " +
		   "Aooooo\n");
	call_other(bill, "load_a_chat", "Bill says: " +
		   "I hate fisters!\n");
	call_other(bill, "load_a_chat", "Bill says: " +
		   "Bastard\n");
	call_other(bill, "load_a_chat", "Bill says: " +
		   "OOOOOOO You big brute!\n");
	call_other(bill, "set_random_pick", 20);
	call_other(bill, "set_move_at_reset", 0);
    }
}

why_did(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
    if(who == "bill" || who == "Bill")
	return;
    if (sscanf(str, "%s sells %s.", who, what) == 2) {
	notify("Bill says: Why did you sell " + what + "\n");
        notify("You fucking asshole that is stealing!!!!\n");
    }
    if (sscanf(str, "%s attacks %s.", who, what) == 2) {
	notify("Bill says: Why does " + who + " attack " + what + "?\n");
        notify("Bill says: Beat me instead you beast!!!!\n");
    }
    if (sscanf(str, "%s left the game.", who) == 1) {
	notify("Bill says: Why did " + who + " quit the game ?\n");
        notify("Bill says: That fucking prick didn't even say bye!!!\n");
    }
    if (sscanf(str, "%s takes %s.\n", who, what) == 2) {
	notify("Bill says: Why did " + who + " take " + what + " ?\n");
        notify("Bill says: The dishonest little fuck!!! That's stealing!!!\n");
    }
    if (sscanf(str, "%s drops %s.\n", who, what) == 2) {
	notify("Bill says: Why did " + who + " drop " + what + " ?\n");
        notify("Bill says: What a fucking moron!!!\n");
    }
}

notify(str) {
    say(str);
    write(str);
}
	
how_does_it_feel(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
    if(who == "bill" || who == "Bill")
	return;
    if (sscanf(str, "%s is now level %s.\n", who, what) == 2) {
	notify("Bill says: How does it feel, to be fucked up the ass!!!!\n");
    }
}
    
smiles(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
    if(who == "bill" || who == "Bill")
	return;
    if (sscanf(str, "%s smiles happily", who) == 1 &&
	who != "Bill") {
	notify("Bill smiles happily.\n");
    }
}
    
say_hello(str) {
    string who;
    if (sscanf(str, "%s arrives.", who) == 1) {
	notify( "Bill says: Hi " + who + ", why don't you go fuck yourself!!! !\n");
    }
}
    
test_say(str) {
    string a, b, message;

    sscanf(str, "%s %s", a, b);
    if(a == "bill" || a == "Bill")
	return;
    if (!sscanf(str, "%s says: %s\n", a, b) == 2) {
	return;
    }
    str = b;

    if (sscanf(str, "%sBill%s", a, b) == 2)
	message = "Bill nods enthusiastically.\n";
    if (str == "shut up") {
	message = "Bill says: Why do you want me to shut up ?\n";
    }
    if (sscanf(str, "%stay here%s", a, b) == 2 ||
	sscanf(str, "%son't follow%s", a, b) == 2 ||
	sscanf(str, "%set lost%s", a, b) == 2) {
	message = "Bill says: Fuck off and die then.\n";
    }
    if(message)
	notify(message);
}

follow(str) {
    string who, where;
    if(sscanf(str, "%s leaves %s.\n", who, where) == 2)
	call_other(bill, "init_command", where);
}

gives(str) {
    string who, what, whom;
    int rand;
    object obj, next_obj;
    if(sscanf(str, "%s gives %s to %s.\n", who, what, whom) != 3)
	return;
    if(whom != "Bill")
	return;
    if(what == "firebreather" || what == "special" ||
       what == "beer" || what == "bottle") {
	rand = random(4);
	if(rand == 0) {
	    if(random(10) > 6) {
		notify("Bill sighs and says: I guess you're gonna kill me now.\n");
		obj = first_inventory(bill);
		while(obj) {
		    next_obj = next_inventory(bill);
		    transfer(obj, environment(bill));
		    notify("Bill drops " + call_other(obj, "short") + ".\n");
		    obj = next_obj;
		}
		call_other(bill, "init_command", "west");
	    }
	}
	if(rand == 1) {
	    call_other(bill, "init_command", "drink " + what);
	}
	if(rand == 2) {
	    obj = first_inventory(bill);
	    while(!call_other(obj, "id", what))
		obj = next_inventory(obj);
	    transfer(obj, environment(bill));
	    notify("Bill drops the " + what + ".\n");
	}
	if(rand == 3) {
	    obj = first_inventory(bill);
	    while(!call_other(obj, "id", what))
		obj = next_inventory(obj);
	    transfer(obj, find_living(lower_case(who)));
	    notify("Bill returned the " + what + " to " + who + ".\n");
	}
    } else if(what == "corpse") {
	notify("Bill says: HEY, burry your corpses yourself, ashole.\n");
	obj = first_inventory(bill);
	while(!call_other(obj, "id", what))
	    obj = next_inventory(obj);
	transfer(obj, find_living(lower_case(who)));
	notify("Bill returned the " + what + " to " + who + ".\n");
    } else {
	notify("Bill says: Thank you very much, sir.\n");
    }
}

monster_died() {
    object obj, b;
    int num;
    obj = first_inventory(bill);
    while(obj) {
	b = next_inventory(bill);
	if(call_other(obj, "id", "bottle")) {
	    destruct(obj);
	    num = 1;
	}
	obj = b;
    }
    if(num)
	notify("There is a crushing sound of bottles breaking, as the body falls.\n");
}

#endif

down() {
      call_other(this_player(), "move_player", "down#room/station");
        return 1;
  }
