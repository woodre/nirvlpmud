#include "std.h"

object vivian;
int count;

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
   extra_init() {
      add_action("fuck","fuck");
     }
#undef EXTRA_RESET
#define EXTRA_RESET\
    if (!find_living("vivian"))\
        starta_vivian();

ONE_EXIT("room/yard","east",
	 "Dirty alley",
	 "A dirty, trash-strewn alley.\n", 1)

starta_vivian() {
    if(!vivian || !living(vivian)) {
	vivian = clone_object("obj/monster");
	call_other(vivian, "set_name", "vivian");
	call_other(vivian, "set_alias", "hooker");
	call_other(vivian, "set_short", "Vivian the hooker");
	call_other(vivian, "set_long",
   "She is young with HUGE tits has red hair and green eyes.\n");
	call_other(vivian, "set_ac", 0);
	call_other(vivian, "set_level",1);
	call_other(vivian, "set_al",125);
	call_other(vivian, "set_ep",30);
	call_other(vivian, "set_hp",20);
	call_other(vivian, "set_wc",5);
	call_other(vivian, "set_aggressive", 0);
	move_object(vivian, "room/alley");
	call_other(vivian, "set_object", this_object());
	call_other(vivian, "set_function", "fucks");
	call_other(vivian, "set_type", "fucks");
	call_other(vivian, "set_match", " your brains out.");
	call_other(vivian, "set_type", "arrives");
	call_other(vivian, "set_match", "");
	call_other(vivian, "set_function", "say_hello");
	call_other(vivian, "set_type", "arrives");
	call_other(vivian, "set_match", "");
	call_other(vivian, "set_function", "test_say");
	call_other(vivian, "set_type", "says:");
	call_other(vivian, "set_match", " ");
	call_other(vivian, "set_type", "tells you:");
	call_other(vivian, "set_match", " ");
	call_other(vivian, "set_function", "gives");
	call_other(vivian, "set_type", "gives");
	call_other(vivian, "set_match", " ");
	
	call_other(vivian, "set_chat_chance", 10);
	call_other(vivian, "set_a_chat_chance", 33);
	call_other(vivian, "load_chat", "Vivian says: Hi there, stranger!\n");
	call_other(vivian, "load_chat", "Vivian says: " +
		   "Hello there!\n");
	call_other(vivian, "load_chat", "Vivian says: " +
		   "Are you looking for some fun?\n");
	call_other(vivian, "load_chat", "Vivian says: " +
		   "Can I do anything for you or more to the point to you?\n");
	call_other(vivian, "load_chat", "Vivian says: " +
		   "Nice weather for a lay, isn't it?\n");
	call_other(vivian, "load_chat", 
		   "Vivian checks out your bod.\n");
	call_other(vivian, "load_a_chat", "Vivian says: " +
		   "Don't hit me!\n");
	call_other(vivian, "load_a_chat", "Vivian says: " +
		   "That hurt!\n");
	call_other(vivian, "load_a_chat", "Vivian says: " +
		   "Help, someone!\n");
	call_other(vivian, "load_a_chat", "Vivian says: " +
   "OOOOOO yes!!!!! More!!!! More!!!!!\n");
	call_other(vivian, "load_a_chat", "Vivian says: " +
		   "What did I do to you?\n");
	call_other(vivian, "load_a_chat", "Vivian says: " +
		   "OOOOOOOOO You big brute!\n");
    }
}

notify(str) {
    say(str);
    write(str);
}
	
fucks(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
    if(who == "vivian" || who == "Vivian")
	return;
    if (sscanf(str, "%s fucks your brains out", who) == 1 &&
	who != "Vivian") {
	notify("Vivian moans with pleasure.\n");
    }
}
    
say_hello(str) {
    string who;
    if (sscanf(str, "%s arrives.", who) == 1) {
	notify( "Vivian says: Hi " + who + "!  Were you looking for me?\n");
    }
}
    
test_say(str) {
    string a, b, message;

    sscanf(str, "%s %s", a, b);
    if(a == "vivian" || a == "Vivian")
	return;
    if (!sscanf(str, "%s says: %s\n", a, b) == 2) {
	return;
    }
    str = b;

    if (sscanf(str, "%sVivian%s", a, b) == 2)
	message = "Vivian nods enthusiastically.\n";
    if(message)
	notify(message);
}

gives(str) {
    string who, what, whom;
    int rand;
    object obj, next_obj;
    if(sscanf(str, "%s gives %s to %s.\n", who, what, whom) != 3)
	return;
    if(whom != "Vivian")
	return;
    else if(what == "corpse") {
notify("Vivian says: Hey, you're the only thing that is stiff around here!!\n");
	obj = first_inventory(vivian);
	while(!call_other(obj, "id", what))
	    obj = next_inventory(obj);
	transfer(obj, find_living(lower_case(who)));
	notify("Vivian returned the " + what + " to " + who + ".\n");
    } else if (what == "1 coin") {
        notify("Vivian says: 1 coin? What sort of cheap tramp do you think I am?\n");
	notify("Vivian pouts.\n");
    } else {
	notify("Vivian says: Oh, for me?\n");
	notify("Vivian blushes.\n");
	notify("Vivian gives " + who + " the greatest lay of your life. (OOOOO yes!!!!)\n");
	/* De-frog the person if necessary */
	if (call_other(find_living(lower_case(who)), "query_frog"))
		call_other(find_living(lower_case(who)), "frog_curse", 0);
    }
}
fuck(str) {
     if(str==0) {
        write("You ought to Fuck someone you asshole quit playing with yourself!\n");
        return 1;
      }
     say(this_player()->query_name());
     say(" fucks your brains out\n");
     write("You fuck " + str + "'s brains out.\n");
     return 1;
   }
