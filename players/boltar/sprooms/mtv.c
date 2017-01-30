#include "std.h"

object beavis;
 object weapon;
object leather_jacket;
int count;

#undef EXTRA_RESET
#define EXTRA_RESET\
    if (!find_living("moron"))\
        starta_beavis();

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
   if (str == "at sofa") {
    write("A beat-up old sofa.\n");
   return 1;
  }
return 0;
}


TWO_EXIT("players/boltar/sprooms/mtv2.c", "east",
 "players/boltar/lv2/endless3.c", "west",
	   "cartoon hall",
 "As you enter this room you notice everything looks like a cartoon drawing,\n" +
 "including you.  The hallway looks endless. There is a sofa here.\n", 1)

starta_beavis() {

    if(!beavis || !living(beavis)) {
    beavis = clone_object("players/boltar/sprooms/new_beavis.c");
    	move_object(beavis, "players/boltar/sprooms/mtv");
    }
}
 
/*
	beavis = clone_object("obj/monster.c");
call_other(beavis, "set_name", "beavis");
call_other(beavis, "set_short", "Beavis the moron (stupid)");
call_other(beavis, "set_id", "beavis");
call_other(beavis, "set_long", "Beavis the moron (stupid) (male).\n"+
          "Beavis loves Heavy Metal.\n"+
          " ");
	call_other(beavis, "set_ac", 0);
call_other(beavis, "set_gender", "male");
        beavis->set_race("moron");
	call_other(beavis, "set_level",12);
	call_other(beavis, "set_al",-60);
	call_other(beavis, "set_hp",350);
	call_other(beavis, "set_wc",5);
	call_other(beavis, "set_aggressive", 0);
call_other(beavis, "add_money", 238);
	call_other(beavis, "set_object", this_object());
	call_other(beavis, "set_function", "why_did");
	call_other(beavis, "set_type", "sells");
	call_other(beavis, "set_match", " ");
	call_other(beavis, "set_type", "attack");
	call_other(beavis, "set_match", " ");
	call_other(beavis, "set_type", "left");
	call_other(beavis, "set_match", "the game");
	call_other(beavis, "set_type", "takes");
	call_other(beavis, "set_match", " ");
	call_other(beavis, "set_type", "drops");
	call_other(beavis, "set_match", " ");
	call_other(beavis, "set_function", "how_does_it_feel");
	call_other(beavis, "set_type", "is now level");
	call_other(beavis, "set_match", " ");
	call_other(beavis, "set_function", "smiles");
	call_other(beavis, "set_type", "smiles");
	call_other(beavis, "set_match", " happily.");
	call_other(beavis, "set_function", "say_hello");
	call_other(beavis, "set_type", "arrives");
	call_other(beavis, "set_match", "");
	call_other(beavis, "set_function", "test_say");
	call_other(beavis, "set_type", "says:");
	call_other(beavis, "set_match", " ");
	call_other(beavis, "set_type", "tells you:");
	call_other(beavis, "set_match", " ");
	call_other(beavis, "set_function", "follow");
	call_other(beavis, "set_type", "leaves");
	call_other(beavis, "set_match", " "); 
	call_other(beavis, "set_function", "gives");
	call_other(beavis, "set_type", "gives");
	call_other(beavis, "set_match", " ");
	
	call_other(beavis, "set_chat_chance", 20);
	call_other(beavis, "set_a_chat_chance", 44);
	call_other(beavis, "load_chat", "Beavis says: This sucks.\n");
	call_other(beavis, "load_chat", "Beavis says: " +
		   "Stop in the name of all that does not suck.\n");
	call_other(beavis, "load_chat", "Beavis says: " +
		   "Fire! Fire!.\n");
	call_other(beavis, "load_chat", "Beavis says: " +
		   "Fire's cool.\n");
	call_other(beavis, "load_chat", "Beavis says: " +
		   "huh huh ha ha ha.\n");
call_other(beavis, "load_chat", "Beavis says: " +
   "He said butt.. heh...heheh.\n");
call_other(beavis, "load_chat", "Beavis says: " +
   "Diareia cha cha cha.\n");
call_other(beavis, "load_chat", "Beavis says: " +
          "Breakin' the law! Breakin' the law!\n");
call_other(beavis, "load_chat", "Beavis says: " +
    "Take me down to a paradise city.\n");
call_other(beavis, "load_chat", "Beavis says: " +
     "heh heh heh hah.\n");
	call_other(beavis, "load_chat", "Beavis says: " +
		   "I guess college music is cool only if you are in college.\n");
	call_other(beavis, "load_chat", "Beavis says: " +
		   "If I wanted to read I would be in school.\n");
	call_other(beavis, "load_chat", "Beavis says: " +
		   "This sucks!! Change it!!! Change it!!!\n");
	call_other(beavis, "load_chat", "Beavis says: " +
		   "We're going down to Babes R Us.\n");
	call_other(beavis, "load_chat", 
		   "Beavis grins evilly.\n");
	call_other(beavis, "load_a_chat", "Beavis says: " +
		   "Blood's cool.\n");
	call_other(beavis, "load_a_chat", "Beavis says: " +
		   "Fire! Fire!\n");
	call_other(beavis, "load_a_chat", "Beavis says: " +
		   "heh hehehhe hehheh\n");
	call_other(beavis, "load_a_chat", "Beavis says: " +
		   "Swords are cool.\n");
	call_other(beavis, "load_a_chat", " " +
		   "Beavis pukes all over you!\n");
	call_other(beavis, "load_a_chat", "Beavis says: " +
		   "Bastard\n");
	call_other(beavis, "set_random_pick", 20);
	call_other(beavis, "set_move_at_reset", 0);

	leather_jacket = clone_object("obj/armor");
	call_other(leather_jacket, "set_name", "AC/DC shirt");
	call_other(leather_jacket, "set_short", "An AC/DC shirt");
	call_other(leather_jacket, "set_alias", "shirt");
call_other(leather_jacket, "set_long", "A plain ordinary AC/DC T-shirt"+
   "\n");
	call_other(leather_jacket, "set_value", 600);
	call_other(leather_jacket, "set_weight", 2);
	call_other(leather_jacket, "set_ac", 3);
	call_other(leather_jacket, "set_type", "armor");
move_object(leather_jacket, beavis);
call_other(beavis, "init_command", "wear shirt");
        weapon = clone_object("obj/weapon");
        call_other(weapon, "set_name", "A chain saw");
	call_other(weapon, "set_alias", "saw");
        call_other(weapon, "set_class", 14);
        call_other(weapon, "set_value", 750);
        call_other(weapon, "set_weight", 4);
move_object(weapon, beavis);
call_other(beavis, "init_command", "wield saw");
}
}

why_did(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
    if(who == "beavis" || who == "Beavis")
	return;
    if(who == "butthead" || who == "Butthead")
	return;
    if (sscanf(str, "%s sells %s.", who, what) == 2) {
	notify("Beavis says:  " + what + "'s are cool.\n");
    }
    if (sscanf(str, "%s attacks %s.", who, what) == 2) {
	notify("Beavis says:  " + who + " fighting " + what + " sucks.\n");
    }
    if (sscanf(str, "%s left the game.", who) == 1) {
	notify("Beavis says:  quiting's cool.\n");
    }
    if (sscanf(str, "%s takes %s.\n", who, what) == 2) {
	notify("Beavis says:  " + who + " sucks.\n" + what + "'s suck!\n");
    }
    if (sscanf(str, "%s drops %s.\n", who, what) == 2) {
	notify("Beavis says:  " + who + " droped a " + what + " heheh heh cool. \n");
      }
}

notify(str) {
    say(str);
    write(str);
}
	
how_does_it_feel(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
    if(who == "beavis" || who == "Beavis")
	return;
    if (sscanf(str, "%s is now level %s.\n", who, what) == 2) {
	notify("Beavis says: level " + what+" is cool.");
    }
}
    
smiles(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
    if(who == "beavis" || who == "Beavis")
	return;
    if (sscanf(str, "%s smiles happily", who) == 1 &&
	who != "Beavis") {
	notify("Beavis grins evilly.\n");
    }
}
    
say_hello(str) {
    string who;
    if (sscanf(str, "%s arrives.", who) == 1) {
	notify( "Beavis says: " + who + " sucks.\n");
    }
}
    
test_say(str) {
    string a, b, message;

    sscanf(str, "%s %s", a, b);
    if(a == "beavis" || a == "Beavis")
	return;
    if(a == "butthead" || a == "Butthead")
	return;
    if (!sscanf(str, "%s says: %s\n", a, b) == 2) {
	return;
    }
    str = b;

    if (str == "hello" || str == "hi" || str == "hello everybody") {
	message = "Beavis says: You suck.\n";
    }
    if (str == "shut up") {
	message = "Beavis says: Shut up yourself.\n";
    }
    if (sscanf(str, "%sstay here%s", a, b) == 2 ||
	sscanf(str, "%snot follow%s", a, b) == 2 ||
	sscanf(str, "%sget lost%s", a, b) == 2) {
	message = "Beavis says: Ok then.\n";
    }
    if(!message)
	message = "Beavis says: '" + str + "' sucks\n";
    notify(message);
}

follow(str) {
    string who, where;
    if(sscanf(str, "%s leaves %s.\n", who, where) == 2)
	call_other(beavis, "init_command", where);
}

gives(str) {
    string who, what, whom;
    int rand;
    object obj, next_obj;
    if(sscanf(str, "%s gives %s to %s.\n", who, what, whom) != 3)
	return;
    if(whom != "Beavis")
	return;
    if(what == "firebreather" || what == "special" ||
       what == "beer" || what == "bottle") {
	rand = random(4);
	if(rand == 0) {
	    if(random(10) > 6) {
		notify("Beavis sighs and says: I guess you're gonna kill me now.\n");
		obj = first_inventory(beavis);
		while(obj) {
		    next_obj = next_inventory(beavis);
		    transfer(obj, environment(beavis));
		    notify("Beavis drops " + call_other(obj, "short") + ".\n");
		    obj = next_obj;
		}
		call_other(beavis, "init_command", "west");
	    }
	}
	if(rand == 1) {
	    call_other(beavis, "init_command", "drink " + what);
	}
	if(rand == 2) {
	    obj = first_inventory(beavis);
	    while(!call_other(obj, "id", what))
		obj = next_inventory(obj);
	    transfer(obj, environment(beavis));
	    notify("Beavis drops the " + what + ".\n");
	}
	if(rand == 3) {
	    obj = first_inventory(beavis);
	    while(!call_other(obj, "id", what))
		obj = next_inventory(obj);
	    transfer(obj, find_living(lower_case(who)));
	    notify("Beavis returned the " + what + " to " + who + ".\n");
	}
    } else if(what == "corpse") {
	notify("Beavis says: HEY, bury your corpses yourself, asshole.\n");
	obj = first_inventory(beavis);
	while(!call_other(obj, "id", what))
	    obj = next_inventory(obj);
	transfer(obj, find_living(lower_case(who)));
	notify("Beavis returned the " + what + " to " + who + ".\n");
    } else {
	notify("Beavis says: Thank you very much, sir.\n");
    }
}

monster_died() {
    object obj, b;
    int num;
    obj = first_inventory(beavis);
    while(obj) {
	b = next_inventory(beavis);
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

