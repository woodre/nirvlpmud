#include "std.h"

object yarr;
 object weapon;
object leather_jacket;
int count;

#undef EXTRA_RESET
#define EXTRA_RESET\
    if (!find_living("yarr"))\
        starta_yarr();

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

extra_init() {
     add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
     add_action("look", "search");
  }
look(str) {
   if (!str) {
   return 0;
  }
   if (str == "at letter" || str == "at runic letter" || str == "letter" || str== "runic letter") {
    write("Its the runic symbol for B.\n");
   return 1;
  }
return 0;
}

FOUR_EXIT("players/boltar/lv1/thingroom", "north",
	  "players/boltar/lv1/itroom", "south",
	  "players/boltar/lv1/room3", "west",
	  "players/boltar/lv1/room1", "east",
	  "The Entrance Hall",
  "As you enter into the grand entrance hall of The Big House you notice" +
  "\n" +
  "That the celing streches far above your head and arches from all four walls\n" +
  "in towards the center.  In each of the four directions of the compass\n" +
  "there is a open archway with a strange runic letter above each arch.\n", 1)

starta_yarr() {
    if(!yarr || !living(yarr)) {
	yarr = clone_object("obj/monster.c");
call_other(yarr, "set_name", "yarr");
call_other(yarr, "set_short", "Yarr the lowrank beginner (neutral)");
call_other(yarr, "set_long", "Yarr the lowrank beginner (neutral) (male).\n"+
          "Yarr the strong.\n"+
          " ");
	call_other(yarr, "set_ac", 0);
	call_other(yarr, "set_level",3);
	call_other(yarr, "set_al",50);
	call_other(yarr, "set_hp",66);
	call_other(yarr, "set_wc",5);
	call_other(yarr, "set_aggressive", 0);
call_other(yarr, "add_money", 238);
	move_object(yarr, "players/boltar/lv1/room2");
	call_other(yarr, "set_object", this_object());
	call_other(yarr, "set_function", "why_did");
	call_other(yarr, "set_type", "sells");
	call_other(yarr, "set_match", " ");
	call_other(yarr, "set_type", "attack");
	call_other(yarr, "set_match", " ");
	call_other(yarr, "set_type", "left");
	call_other(yarr, "set_match", "the game");
	call_other(yarr, "set_type", "takes");
	call_other(yarr, "set_match", " ");
	call_other(yarr, "set_type", "drops");
	call_other(yarr, "set_match", " ");
	call_other(yarr, "set_function", "how_does_it_feel");
	call_other(yarr, "set_type", "is now level");
	call_other(yarr, "set_match", " ");
	call_other(yarr, "set_function", "smiles");
	call_other(yarr, "set_type", "smiles");
	call_other(yarr, "set_match", " happily.");
	call_other(yarr, "set_function", "say_hello");
	call_other(yarr, "set_type", "arrives");
	call_other(yarr, "set_match", "");
	call_other(yarr, "set_function", "test_say");
	call_other(yarr, "set_type", "says:");
	call_other(yarr, "set_match", " ");
	call_other(yarr, "set_type", "tells you:");
	call_other(yarr, "set_match", " ");
	call_other(yarr, "set_function", "follow");
	call_other(yarr, "set_type", "leaves");
	call_other(yarr, "set_match", " "); 
	call_other(yarr, "set_function", "gives");
	call_other(yarr, "set_type", "gives");
	call_other(yarr, "set_match", " ");
	
	call_other(yarr, "set_chat_chance", 3);
	call_other(yarr, "set_a_chat_chance", 44);
	call_other(yarr, "load_chat", "Yarr says: What's up?\n");
	call_other(yarr, "load_chat", "Yarr says: " +
		   "Hello there!\n");
	call_other(yarr, "load_chat", "Yarr says: " +
		   "I don't like Haji.\n");
	call_other(yarr, "load_chat", "Yarr says: " +
		   "I don't like Beasty.\n");
	call_other(yarr, "load_chat", "Yarr says: " +
		   "I don't like Avatar.\n");
call_other(yarr, "load_chat", "Yarr says: " +
   "I don't like Prischa.\n");
call_other(yarr, "load_chat", "Yarr says: " +
   "I don't like Edward.\n");
call_other(yarr, "load_chat", "Yarr says: " +
    "I don't like Gareth.\n");
call_other(yarr, "load_chat", "Yarr says: " +
     "I don't like Omega.\n");
	call_other(yarr, "load_chat", "Yarr says: " +
		   "Who are you?\n");
	call_other(yarr, "load_chat", "Yarr says: " +
		   "Why do you look like that?\n");
	call_other(yarr, "load_chat", "Yarr says: " +
		   "Why don't you go do some homework?\n");
	call_other(yarr, "load_chat", "Yarr says: " +
		   "The beer is too expensive.\n");
	call_other(yarr, "load_chat", 
		   "Yarr grins evilly.\n");
	call_other(yarr, "load_a_chat", "Yarr says: " +
		   "My friends will avenge me!\n");
	call_other(yarr, "load_a_chat", "Yarr says: " +
		   "I'm going to make sure you die for this!\n");
	call_other(yarr, "load_a_chat", "Yarr says: " +
		   "Help, someone!\n");
	call_other(yarr, "load_a_chat", "Yarr says: " +
		   "Aooooo\n");
	call_other(yarr, "load_a_chat", " " +
		   "Yarr pukes all over you!\n");
	call_other(yarr, "load_a_chat", "Yarr says: " +
		   "Bastard\n");
	call_other(yarr, "set_random_pick", 20);
	call_other(yarr, "set_move_at_reset", 0);

	leather_jacket = clone_object("obj/armor");
	call_other(leather_jacket, "set_name", "leather jacket");
	call_other(leather_jacket, "set_short", "A leather jacket");
	call_other(leather_jacket, "set_alias", "jacket");
call_other(leather_jacket, "set_long", "A leather jacket with the picture of a B-29 Superfortres painted on the back."+
   "\n");
	call_other(leather_jacket, "set_value", 20);
	call_other(leather_jacket, "set_weight", 1);
	call_other(leather_jacket, "set_ac", 1);
	call_other(leather_jacket, "set_type", "armor");
move_object(leather_jacket, yarr);
call_other(yarr, "init_command", "wear jacket");
        weapon = clone_object("obj/weapon");
        call_other(weapon, "set_name", "A black bladed axe");
	call_other(weapon, "set_alias", "axe");
        call_other(weapon, "set_class", 7);
        call_other(weapon, "set_value", 70);
        call_other(weapon, "set_weight", 1);
move_object(weapon, yarr);
call_other(yarr, "init_command", "wield axe");
}
}

why_did(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
    if(who == "yarr" || who == "Yarr")
	return;
    if (sscanf(str, "%s sells %s.", who, what) == 2) {
	notify("Yarr says: Why did you sell " + what + "\n");
    }
    if (sscanf(str, "%s attacks %s.", who, what) == 2) {
	notify("Yarr says: Why does " + who + " attack " + what + "?\n");
    }
    if (sscanf(str, "%s left the game.", who) == 1) {
	notify("Yarr says: Why did " + who + " quit the game ?\n");
    }
    if (sscanf(str, "%s takes %s.\n", who, what) == 2) {
	notify("Yarr says: Why did " + who + " take " + what + " ?\n");
    }
    if (sscanf(str, "%s drops %s.\n", who, what) == 2) {
	notify("Yarr says: Why did " + who + " drop " + what + " ?\n");
    }
}

notify(str) {
    say(str);
    write(str);
}
	
how_does_it_feel(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
    if(who == "yarr" || who == "Yarr")
	return;
    if (sscanf(str, "%s is now level %s.\n", who, what) == 2) {
	notify("Yarr says: How does it feel, being of level " + what);
    }
}
    
smiles(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
    if(who == "yarr" || who == "Yarr")
	return;
    if (sscanf(str, "%s smiles happily", who) == 1 &&
	who != "Yarr") {
	notify("Yarr grins evilly.\n");
    }
}
    
say_hello(str) {
    string who;
    if (sscanf(str, "%s arrives.", who) == 1) {
	notify( "Yarr says: Hi " + who + ".\n");
    }
}
    
test_say(str) {
    string a, b, message;

    sscanf(str, "%s %s", a, b);
    if(a == "yarr" || a == "Yarr")
	return;
    if (!sscanf(str, "%s says: %s\n", a, b) == 2) {
	return;
    }
    str = b;

    if (str == "hello" || str == "hi" || str == "hello everybody") {
	message = "Yarr says: Howdey\n";
    }
    if (str == "shut up") {
	message = "Yarr says: Shut up yourself.\n";
    }
    if (sscanf(str, "%sstay here%s", a, b) == 2 ||
	sscanf(str, "%snot follow%s", a, b) == 2 ||
	sscanf(str, "%sget lost%s", a, b) == 2) {
	message = "Yarr says: Ok then.\n";
    }
    if(!message)
	message = "Yarr says: What does  '" + str + "' mean??\n";
    notify(message);
}

follow(str) {
    string who, where;
    if(sscanf(str, "%s leaves %s.\n", who, where) == 2)
	call_other(yarr, "init_command", where);
}

gives(str) {
    string who, what, whom;
    int rand;
    object obj, next_obj;
    if(sscanf(str, "%s gives %s to %s.\n", who, what, whom) != 3)
	return;
    if(whom != "Yarr")
	return;
    if(what == "firebreather" || what == "special" ||
       what == "beer" || what == "bottle") {
	rand = random(4);
	if(rand == 0) {
	    if(random(10) > 6) {
		notify("Yarr sighs and says: I guess you're gonna kill me now.\n");
		obj = first_inventory(yarr);
		while(obj) {
		    next_obj = next_inventory(yarr);
		    transfer(obj, environment(yarr));
		    notify("Yarr drops " + call_other(obj, "short") + ".\n");
		    obj = next_obj;
		}
		call_other(yarr, "init_command", "west");
	    }
	}
	if(rand == 1) {
	    call_other(yarr, "init_command", "drink " + what);
	}
	if(rand == 2) {
	    obj = first_inventory(yarr);
	    while(!call_other(obj, "id", what))
		obj = next_inventory(obj);
	    transfer(obj, environment(yarr));
	    notify("Yarr drops the " + what + ".\n");
	}
	if(rand == 3) {
	    obj = first_inventory(yarr);
	    while(!call_other(obj, "id", what))
		obj = next_inventory(obj);
	    transfer(obj, find_living(lower_case(who)));
	    notify("Yarr returned the " + what + " to " + who + ".\n");
	}
    } else if(what == "corpse") {
	notify("Yarr says: HEY, bury your corpses yourself, asshole.\n");
	obj = first_inventory(yarr);
	while(!call_other(obj, "id", what))
	    obj = next_inventory(obj);
	transfer(obj, find_living(lower_case(who)));
	notify("Yarr returned the " + what + " to " + who + ".\n");
    } else {
	notify("Yarr says: Thank you very much, sir.\n");
    }
}

monster_died() {
    object obj, b;
    int num;
    obj = first_inventory(yarr);
    while(obj) {
	b = next_inventory(yarr);
	if(call_other(obj, "id", "bottle")) {
	    destruct(obj);
	    num = 1;
	}
	obj = b;
    }
    if(num)
	notify("There is a crushing sound of bottles breaking, as the body falls.\n");
}

down() {
    call_other(this_player(), "move_player", "down#room/station");
    return 1;

}
