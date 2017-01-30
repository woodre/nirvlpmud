#include "std.h"

object butthead;
 object weapon;
object leather_jacket;
int count;

#undef EXTRA_RESET
#define EXTRA_RESET\
    if (!find_living("moronb"))\
        starta_butthead();

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


TWO_EXIT("players/boltar/lv2/jetroom.c", "east",
 "players/boltar/sprooms/mtv.c", "west",
	   "cartoon hall",
 "As you enter this room you notice everything looks like a cartoon drawing,\n" +
 "including you.  The hallway looks endless.\n", 1)

starta_butthead() {
    if(!butthead || !living(butthead)) {
    butthead = clone_object("players/boltar/sprooms/new_butthead.c");
    move_object(butthead, "players/boltar/sprooms/mtv2");
}}

/*
	butthead = clone_object("obj/monster.c");
call_other(butthead, "set_name", "butthead");
call_other(butthead, "set_short", "Butthead the moron (stupid)");
call_other(butthead, "set_long", "Butthead the moron (stupid) (male).\n"+
          "Butthead loves Heavy Metal.\n"+
          " ");
	call_other(butthead, "set_ac", 0);
	call_other(butthead, "set_level",12);
call_other(butthead, "set_gender", "male");
         butthead->set_race("moronb");
	call_other(butthead, "set_al",-60);
	call_other(butthead, "set_hp",350);
	call_other(butthead, "set_wc",5);
	call_other(butthead, "set_aggressive", 0);
call_other(butthead, "add_money", 238);
	call_other(butthead, "set_object", this_object());
	call_other(butthead, "set_function", "why_did");
	call_other(butthead, "set_type", "sells");
	call_other(butthead, "set_match", " ");
	call_other(butthead, "set_type", "attack");
	call_other(butthead, "set_match", " ");
	call_other(butthead, "set_type", "left");
	call_other(butthead, "set_match", "the game");
	call_other(butthead, "set_type", "takes");
	call_other(butthead, "set_match", " ");
	call_other(butthead, "set_type", "drops");
	call_other(butthead, "set_match", " ");
	call_other(butthead, "set_function", "how_does_it_feel");
	call_other(butthead, "set_type", "is now level");
	call_other(butthead, "set_match", " ");
	call_other(butthead, "set_function", "smiles");
	call_other(butthead, "set_type", "smiles");
	call_other(butthead, "set_match", " happily.");
	call_other(butthead, "set_function", "say_hello");
	call_other(butthead, "set_type", "arrives");
	call_other(butthead, "set_match", "");
	call_other(butthead, "set_function", "test_say");
	call_other(butthead, "set_type", "says:");
	call_other(butthead, "set_match", " ");
	call_other(butthead, "set_type", "tells you:");
	call_other(butthead, "set_match", " ");
	call_other(butthead, "set_function", "follow");
	call_other(butthead, "set_type", "leaves");
	call_other(butthead, "set_match", " "); 
	call_other(butthead, "set_function", "gives");
	call_other(butthead, "set_type", "gives");
	call_other(butthead, "set_match", " ");
	
	call_other(butthead, "set_chat_chance", 20);
	call_other(butthead, "set_a_chat_chance", 44);
	call_other(butthead, "load_chat", "Butthead says: This sucks.\n");
	call_other(butthead, "load_chat", "Butthead says: " +
		   "Stop in the name of all that does not suck.\n");
	call_other(butthead, "load_chat", "Butthead says: " +
		   "Fire! Fire!.\n");
	call_other(butthead, "load_chat", "Butthead says: " +
		   "Fire's cool.\n");
	call_other(butthead, "load_chat", "Butthead says: " +
		   "huh huh ha ha ha.\n");
call_other(butthead, "load_chat", "Butthead says: " +
   "He said sex.. heh...heheh.\n");
call_other(butthead, "load_chat", "Butthead says: " +
   "Diareia cha cha cha.\n");
call_other(butthead, "load_chat", "Butthead says: " +
       "Pull my finger.\n");
call_other(butthead, "load_chat", "Butthead says: " +
    "Shut up dumb ass.\n");
call_other(butthead, "load_chat", "Butthead says: " +
     "heh heh heh hah.\n");
	call_other(butthead, "load_chat", "Butthead says: " +
                   "Pull my finger.\n");
	call_other(butthead, "load_chat", "Butthead says: " +
		   "If I wanted to read I would be in school.\n");
	call_other(butthead, "load_chat", "Butthead says: " +
                   "This sucks.\n");
	call_other(butthead, "load_chat", "Butthead says: " +
		   "We're going down to Babes R Us.\n");
	call_other(butthead, "load_chat", 
		   "Butthead grins evilly.\n");
	call_other(butthead, "load_a_chat", "Butthead says: " +
		   "Blood's cool.\n");
	call_other(butthead, "load_a_chat", "Butthead says: " +
		   "Fire! Fire!\n");
	call_other(butthead, "load_a_chat", "Butthead says: " +
		   "heh hehehhe hehheh\n");
	call_other(butthead, "load_a_chat", "Butthead says: " +
		   "That wuz cool.\n");
	call_other(butthead, "load_a_chat", " " +
		   "Butthead pukes all over you!\n");
	call_other(butthead, "load_a_chat", "Butthead says: " +
		   "Bastard\n");
	call_other(butthead, "set_random_pick", 20);
	call_other(butthead, "set_move_at_reset", 0);

	leather_jacket = clone_object("obj/armor");
	call_other(leather_jacket, "set_name", "Metalica shirt");
	call_other(leather_jacket, "set_short", "An Metalica shirt");
	call_other(leather_jacket, "set_alias", "shirt");
call_other(leather_jacket, "set_long", "A plain ordinary Metalica T-shirt"+
   "\n");
	call_other(leather_jacket, "set_value", 600);
	call_other(leather_jacket, "set_weight", 2);
	call_other(leather_jacket, "set_ac", 3);
	call_other(leather_jacket, "set_type", "armor");
move_object(leather_jacket, butthead);
call_other(butthead, "init_command", "wear shirt");
        weapon = clone_object("obj/weapon");
        call_other(weapon, "set_name", "A remote control");
	call_other(weapon, "set_alias", "remote");
        call_other(weapon, "set_class", 14);
        call_other(weapon, "set_value", 750);
        call_other(weapon, "set_weight", 2);
move_object(weapon, butthead);
call_other(butthead, "init_command", "wield remote");
}
}

why_did(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
    if(who == "butthead" || who == "Butthead")
	return;
    if(who == "beavis" || who == "Beavis")
	return;
    if (sscanf(str, "%s sells %s.", who, what) == 2) {
	notify("Butthead says:  " + what + "'s are cool.\n");
    }
    if (sscanf(str, "%s attacks %s.", who, what) == 2) {
	notify("Butthead says:  " + who + " fighting " + what + " sucks.\n");
    }
    if (sscanf(str, "%s left the game.", who) == 1) {
	notify("Butthead says:  quiting's cool.\n");
    }
    if (sscanf(str, "%s takes %s.\n", who, what) == 2) {
	notify("Butthead says:  " + who + " sucks.\n" + what + "'s suck!\n");
    }
    if (sscanf(str, "%s drops %s.\n", who, what) == 2) {
	notify("Butthead says:  " + who + " droped a " + what + " heheh heh cool. \n");
      }
}

notify(str) {
    say(str);
    write(str);
}
	
how_does_it_feel(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
    if(who == "butthead" || who == "Butthead")
	return;
    if (sscanf(str, "%s is now level %s.\n", who, what) == 2) {
	notify("Butthead says: level " + what+" is cool.");
    }
}
    
smiles(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
    if(who == "butthead" || who == "Butthead")
	return;
    if (sscanf(str, "%s smiles happily", who) == 1 &&
	who != "Butthead") {
	notify("Butthead grins evilly.\n");
    }
}
    
say_hello(str) {
    string who;
    if (sscanf(str, "%s arrives.", who) == 1) {
	notify( "Butthead says: " + who + " sucks.\n");
    }
}
    
test_say(str) {
    string a, b, message;

    sscanf(str, "%s %s", a, b);
    if(a == "butthead" || a == "Butthead")
	return;
    if(a == "beavis" || a == "Beavis")
	return;
    if (!sscanf(str, "%s says: %s\n", a, b) == 2) {
	return;
    }
    str = b;

    if (str == "hello" || str == "hi" || str == "hello everybody") {
	message = "Butthead says: You suck.\n";
    }
    if (str == "shut up") {
	message = "Butthead says: Shut up yourself.\n";
    }
    if (sscanf(str, "%sstay here%s", a, b) == 2 ||
	sscanf(str, "%snot follow%s", a, b) == 2 ||
	sscanf(str, "%sget lost%s", a, b) == 2) {
	message = "Butthead says: Ok then.\n";
    }
    if(!message)
	message = "Butthead says: '" + str + "' sucks\n";
    notify(message);
}

follow(str) {
    string who, where;
    if(sscanf(str, "%s leaves %s.\n", who, where) == 2)
	call_other(butthead, "init_command", where);
}

gives(str) {
    string who, what, whom;
    int rand;
    object obj, next_obj;
    if(sscanf(str, "%s gives %s to %s.\n", who, what, whom) != 3)
	return;
    if(whom != "Butthead")
	return;
    if(what == "firebreather" || what == "special" ||
       what == "beer" || what == "bottle") {
	rand = random(4);
	if(rand == 0) {
	    if(random(10) > 6) {
		notify("Butthead sighs and says: I guess you're gonna kill me now.\n");
		obj = first_inventory(butthead);
		while(obj) {
		    next_obj = next_inventory(butthead);
		    transfer(obj, environment(butthead));
		    notify("Butthead drops " + call_other(obj, "short") + ".\n");
		    obj = next_obj;
		}
		call_other(butthead, "init_command", "west");
	    }
	}
	if(rand == 1) {
	    call_other(butthead, "init_command", "drink " + what);
	}
	if(rand == 2) {
	    obj = first_inventory(butthead);
	    while(!call_other(obj, "id", what))
		obj = next_inventory(obj);
	    transfer(obj, environment(butthead));
	    notify("Butthead drops the " + what + ".\n");
	}
	if(rand == 3) {
	    obj = first_inventory(butthead);
	    while(!call_other(obj, "id", what))
		obj = next_inventory(obj);
	    transfer(obj, find_living(lower_case(who)));
	    notify("Butthead returned the " + what + " to " + who + ".\n");
	}
    } else if(what == "corpse") {
	notify("Butthead says: HEY, bury your corpses yourself, asshole.\n");
	obj = first_inventory(butthead);
	while(!call_other(obj, "id", what))
	    obj = next_inventory(obj);
	transfer(obj, find_living(lower_case(who)));
	notify("Butthead returned the " + what + " to " + who + ".\n");
    } else {
	notify("Butthead says: Thank you very much, sir.\n");
    }
}

monster_died() {
    object obj, b;
    int num;
    obj = first_inventory(butthead);
    while(obj) {
	b = next_inventory(butthead);
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
*/
