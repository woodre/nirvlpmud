#include "std.h"
#define HARRY 1

int count;

#undef EXTRA_INIT
#define EXTRA_INIT\
     add_action("down","down");\
     add_action("look", "look");\
     add_action("look", "l");\
     add_action("look", "examine");

#if HARRY
object bob;
#undef EXTRA_RESET
#define EXTRA_RESET\
        starta_bob();
#endif

FOUR_EXIT("room/vill_road1","west",
	 "room/vill_road3","east",
	 "room/adv_guild","south",
	 "room/shop","north",
	 "Village road",
 "A long road going through the village. This road is well worn from\n" +
 "constant travel of people back and forth. There is a small shop to\n"+
 "north and a strong brick building to the south.\n"+
 "There are stairs going down.\n"
 , 1)

look(str) {
  if (!str) return 0;
  if (str == "at shop") {
    write("A small squarish brick building with no windows on this side.\n"+
    "The enterance is to the west along the north side of the main road.\n");
    return 1;
  }
  if (str == "at adventures guild" || str == "at guild" ||
      str=="at building" || str=="at strong brick building") {
    write("The adventurers guild is a small stone building with odd \n"+
      "symbols carved into the walls. The enterance is on the south side\n"+
      "of the road east along the main road.\n");
  return 1;
  }
  if (str == "at stairs") {
     write("Concrete stairs lead down to something underground.\n");
     return 1;
  }
  return 0;
}

#if HARRY
starta_bob() {
    if(!bob || !living(bob)) {
	bob = clone_object("obj/monster");
	call_other(bob, "set_name", "bob");
	call_other(bob, "set_alias", "baghdad bob");
	call_other(bob, "set_short", "Baghdad Bob");
	call_other(bob, "set_long", "Baghdad Bob, The Information Minister.\n");
	call_other(bob, "set_ac", 0);
	call_other(bob, "set_level",12);
	call_other(bob, "set_al",50);
	call_other(bob, "set_hp",3000);
	call_other(bob, "set_wc",12);
	call_other(bob, "set_aggressive", 0);
	move_object(bob, "room/vill_road2");
	call_other(bob, "set_object", this_object());
	call_other(bob, "set_function", "why_did");
	call_other(bob, "set_type", "sells");
	call_other(bob, "set_match", " ");
	call_other(bob, "set_type", "attack");
	call_other(bob, "set_match", " ");
	call_other(bob, "set_type", "left");
	call_other(bob, "set_match", "the game");
	call_other(bob, "set_type", "takes");
	call_other(bob, "set_match", " ");
	call_other(bob, "set_type", "drops");
	call_other(bob, "set_match", " ");
	call_other(bob, "set_function", "how_does_it_feel");
	call_other(bob, "set_type", "is now level");
	call_other(bob, "set_match", " ");
	call_other(bob, "set_function", "smiles");
	call_other(bob, "set_type", "smiles");
	call_other(bob, "set_match", " happily.");
	call_other(bob, "set_function", "say_hello");
	call_other(bob, "set_type", "arrives");
	call_other(bob, "set_match", "");
	call_other(bob, "set_function", "test_say");
	call_other(bob, "set_type", "says:");
	call_other(bob, "set_match", " ");
	call_other(bob, "set_type", "tells you:");
	call_other(bob, "set_match", " ");
	call_other(bob, "set_function", "follow");
	call_other(bob, "set_type", "leaves");
	call_other(bob, "set_match", " "); 
	call_other(bob, "set_function", "gives");
	call_other(bob, "set_type", "gives");
	call_other(bob, "set_match", " ");
	
	call_other(bob, "set_chat_chance", 7);
	call_other(bob, "set_a_chat_chance", 33);
	call_other(bob, "load_chat", 
	"Baghdad Bob says: My feelings - as usual - we will slaughter them all.\n");
	call_other(bob, "load_chat", "Baghdad Bob says: " +
  	"surrender or be burned in their tanks.\n");
        call_other(bob, "load_chat", "Baghdad Bob says: " +
        "They will be burnt. We are going to tackle them.\n");
        call_other(bob, "load_chat", "Baghdad Bob says: " +
        "We blocked them inside the city. Their rear is blocked.\n");
        call_other(bob, "load_chat", "Baghdad Bob says: " +
	"the louts of colonialism.\n");
        call_other(bob, "load_chat", "Baghdad Bob says: " +
        "Tonight, we will do something unconventional against them.\n");
	call_other(bob, "load_chat", "Baghdad Bob says: " +
	"They are sick in their minds. They say they brought 65\ntanks"+
        "into center of city. I say to you this talk is not true. This\n"+ 
        "is part of their sick mind.\n");

	call_other(bob, "load_chat", "Baghdad Bob says: " +
	"No I am not scared and neither should you be\n");
	call_other(bob, "load_chat", "Baghdad Bob says: " +
        "We have them surrounded in their tanks\n");
	call_other(bob, "load_chat", "Baghdad Bob says: " +
	"We will welcome them with bullets and shoes.\n");
	call_other(bob, "load_chat", "Baghdad Bob says: " +
	"They do not even have control over themselves! Do not \n"+
	"believe them!\n");
	call_other(bob, "load_chat", "Baghdad Bob says: " +
	"Britain is not worth an old shoe.\n");
	call_other(bob, "load_chat", "Baghdad Bob says: " +
	"The authority of the civil defense ... issued a \n"+
        "warning to the civilian population not to pick up any of\n"+
        "those pencils because they are booby traps\n");
	call_other(bob, "load_chat", "Baghdad Bob says: " +
        "They have started throwing those pencils, but they are\n"+
        "not pencils, they are booby traps to kill the children.\n");
	call_other(bob, "load_chat", 
		   "Baghdad Bob smiles.\n");
	call_other(bob, "load_a_chat", "Baghdad Bob says: " +
	"There are no American infidels in Baghdad. Never!\n");
	call_other(bob, "load_a_chat", "Baghdad Bob says: " +
		   "That hurt!\n");
	call_other(bob, "load_a_chat", "Baghdad Bob says: " +
		   "Help, someone!\n");
	call_other(bob, "load_a_chat", "Baghdad Bob says: " +
		   "Why can't you go bullying elsewhere?\n");
	call_other(bob, "load_a_chat", "Baghdad Bob says: " +
		   "Aooooo\n");
	call_other(bob, "load_a_chat", "Baghdad Bob says: " +
        "I blame Al-Jazeera - they are marketing for the Americans!\n");
	call_other(bob, "load_a_chat", "Baghdad Bob says: " +
		   "Infidel!\n");
	call_other(bob, "load_a_chat", "Baghdad Bob says: " +
	         "Desperate Americans!\n");
	call_other(bob, "set_random_pick", 20);
	call_other(bob, "set_move_at_reset", 0);
    }
}

why_did(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
    if(who == "bob" || who == "Baghdad Bob")
	return;
    if (sscanf(str, "%s sells %s.", who, what) == 2) {
	notify("Baghdad Bob says: "+
	"When we were making the law, when we were writing the\n"+
        "literature and the mathematics the grandfarthers of blair\n"+ 
        "and little bush were scratching around in caves\n");
    }
    if (sscanf(str, "%s attacks %s.", who, what) == 2) {
	notify("Baghdad Bob says: "+
	"Those only deserve to be hit with shoes.\n");
    }
    if (sscanf(str, "%s left the game.", who) == 1) {
	notify("Baghdad Bob says: "+
         "May they be accursed.\n");
    }
    if (sscanf(str, "%s takes %s.\n", who, what) == 2) {
	notify("Baghdad Bob says: "+
	"Now, the game has been exposed. Awe will backfire on them.\n");
    }
    if (sscanf(str, "%s drops %s.\n", who, what) == 2) {
	notify("Baghdad Bob says: "+
	"We do not have any scud missiles.\n");
    }
}

notify(str) {
    say(str);
    write(str);
}
	
how_does_it_feel(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
    if(who == "bob" || who == "Baghdad Bob")
	return;
    if (sscanf(str, "%s is now level %s.\n", who, what) == 2) {
	notify("Baghdad Bob says: "+
	"Their casualties and bodies are many.\n");
    }
}
    
smiles(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
    if(who == "bob" || who == "Baghdad Bob")
	return;
    if (sscanf(str, "%s smiles happily", who) == 1 &&
	who != "Baghdad Bob") {
	notify("Baghdad Bob smiles happily.\n");
    }
}
    
say_hello(str) {
    string who;
    if (sscanf(str, "%s arrives.", who) == 1) {
        notify( "Baghdad Bob says: Hi\n");
    }
}
    
test_say(str) {
    string a, b, message;

    sscanf(str, "%s %s", a, b);
    if(a == "bob" || a == "Baghdad Bob")
	return;
    if (!sscanf(str, "%s says: %s\n", a, b) == 2) {
	return;
    }
    str = b;

    if (sscanf(str, "%sBaghdad Bob%s", a, b) == 2)
	message = "Baghdad Bob nods enthusiastically.\n";
    if (str == "shut up") {
	message = "Baghdad Bob says: Why do you want me to shut up ?\n";
    }
    if (sscanf(str, "%stay here%s", a, b) == 2 ||
	sscanf(str, "%son't follow%s", a, b) == 2 ||
	sscanf(str, "%set lost%s", a, b) == 2) {
	message = "Baghdad Bob says: Ok then.\n";
    }
    if(message)
	notify(message);
}

follow(str) {
    string who, where;
    /*
    if(sscanf(str, "%s leaves %s.\n", who, where) == 2)
	call_other(bob, "init_command", where);
    */
    return 1;
}

gives(str) {
    string who, what, whom;
    int rand;
    object obj, next_obj;
    if(sscanf(str, "%s gives %s to %s.\n", who, what, whom) != 3)
	return;
    if(whom != "Baghdad Bob")
	return;
    if(what == "firebreather" || what == "special" ||
       what == "beer" || what == "bottle") {
	rand = random(4);
	if(rand == 0) {
	    if(random(10) > 6) {
		notify("Baghdad Bob sighs and says: I guess you're gonna kill me now.\n");
		obj = first_inventory(bob);
		while(obj) {
		    next_obj = next_inventory(bob);
		    transfer(obj, environment(bob));
		    notify("Baghdad Bob drops " + call_other(obj, "short") + ".\n");
		    obj = next_obj;
		}
		call_other(bob, "init_command", "west");
	    }
	}
	if(rand == 1) {
	    call_other(bob, "init_command", "drink " + what);
	}
	if(rand == 2) {
	    obj = first_inventory(bob);
	    while(!call_other(obj, "id", what))
		obj = next_inventory(obj);
	    transfer(obj, environment(bob));
	    notify("Baghdad Bob drops the " + what + ".\n");
	}
	if(rand == 3) {
	    obj = first_inventory(bob);
	    while(!call_other(obj, "id", what))
		obj = next_inventory(obj);
	    transfer(obj, find_living(lower_case(who)));
	    notify("Baghdad Bob returned the " + what + " to " + who + ".\n");
	}
    } else if(what == "corpse") {
	notify("Baghdad Bob says: HEY, burry your corpses yourself, ashole.\n");
	obj = first_inventory(bob);
	while(!call_other(obj, "id", what))
	    obj = next_inventory(obj);
	transfer(obj, find_living(lower_case(who)));
	notify("Baghdad Bob returned the " + what + " to " + who + ".\n");
    } else {
	notify("Baghdad Bob says: Thank you very much, sir.\n");
    }
}

monster_died() {
    object obj, b;
    int num;
    obj = first_inventory(bob);
    while(obj) {
	b = next_inventory(bob);
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
