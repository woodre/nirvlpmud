inherit "room/room";

object harry;
int count;
string chat_str;	/* This variable is only initialized once. */
string a_chat_str;
string function, type, match;

reset(arg) {
    start_harry();
    if (arg)
	return;
    dest_dir = ({ "room/vill_road1","west",
		  "room/vill_shore","east",
		  "room/adv_guild","south",
		  "room/station", "down",
		  "room/shop","north" });
    short_desc = "Village road";
    no_castle_flag = 1;
    long_desc = "A long road going through the village. There are stairs going down.\n" +
	"The road continues to the west. To the north is the shop, and to the\n" +
        "south is the adventurers guild. The road runs towards the shore to\n"+
        "the east.\n";
    set_light(1);
}

start_harry() {
    if(!harry) {
	if (!chat_str) {
	    chat_str = allocate(10);
	    a_chat_str = allocate(8);
    chat_str[0] ="Harry says: What are you waiting for?\nHarry says: Why don't you bend over so we can have fun?\n";
	    chat_str[1] = "Harry says: Go fuck yourself!\n";
	    chat_str[2] = "Harry says: I don't like muds.\n";
	    chat_str[3] = "Harry says: I don't like random.\n";
	    chat_str[4] = "Harry says: I don't like beer.\n";
	    chat_str[5] = "Harry says: Who the fuck are you?\n";
	    chat_str[6] = "Harry says: Is that your real face or is it a mask?\n";
	    chat_str[7] = "Harry says: Quit playing with yourself!!\n";
	    chat_str[8] = "Harry says: If you show me yours I'll show you mine.\n";
	    chat_str[9] = "Harry checks out your bod.\n";
	    a_chat_str[0] = "Harry says: Please do me!\n";
	    a_chat_str[1] = "Harry says: That hurt please do it again!\n";
	    a_chat_str[2] = "Harry says: Help, someone I need sex NOW!!!!\n";
	    a_chat_str[3] = "Harry says: Why can't you go masterbate elsewhere?\n";
	    a_chat_str[4] = "Harry says: Aooooo\n";
	    a_chat_str[5] = "Harry says: I hate fisters!\n";
	    a_chat_str[6] = "Harry says: Bastard\n";
	    a_chat_str[7] = "Harry says: ooooooo! You big brute!\n";

	    function = allocate(12);
	    type = allocate(12);
	    match = allocate(12);

	    function[0] = "why_did";
	    type[0] = "sells";
	    type[1] = "attack";
	    type[2] = "left";
	    match[2] = "the game";
	    type[3] = "takes";
	    type[4] = "drops";
	    function[5] = "how_does_it_feel";
	    type[5] = "is now level";
	    function[6] = "smiles";
	    type[6] = "smiles";
	    match[6] = " happily.";
	    function[7] = "say_hello";
	    type[7] = "arrives";
	    function[8] = "test_say";
	    type[8] = "says:";
	    type[9] = "tells you:";
	    function[10] = "follow";
	    type[10] = "leaves";
	    function[11] = "gives";
	    type[11] = "gives";
	}
	harry = clone_object("obj/monster");
	/* Reuse the same arrays. */
	call_other(harry, "load_chat", 2, chat_str);
	call_other(harry, "load_a_chat", 20, a_chat_str);
	call_other(harry, "set_match", this_object(), function, type, match);
	call_other(harry, "set_name", "harry");
	call_other(harry, "set_alias", "fjant");
	call_other(harry, "set_short", "Harry the horny pervert");
	call_other(harry, "set_long", "Harry really wants to have sex with you.\n");
	call_other(harry, "set_ac", 0);
	call_other(harry, "set_level",3);
	call_other(harry, "set_al",50);
	call_other(harry, "set_ep",2283);
	call_other(harry, "set_wc",5);
	call_other(harry, "set_aggressive", 0);
	move_object(harry, this_object());
	
	call_other(harry, "set_random_pick", 50);
	call_other(harry, "set_move_at_reset", 0);
    }
}

why_did(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
    if(who == "harry" || who == "Harry")
	return;
    if (sscanf(str, "%s sells %s.", who, what) == 2) {
	notify("Harry says: Why did you sell " + what + "?  Can't you see its valuable, you dumbass.\n");
    }
    if (sscanf(str, "%s attacks %s.", who, what) == 2) {
	notify("Harry says: Why does " + who + " attack " + what + "?They'll get their ass kicked!!\n");
    }
    if (sscanf(str, "%s left the game.", who) == 1) {
	notify("Harry says: Why did " + who + " quit the game ? What an asshole!!\n");
    }
    if (sscanf(str, "%s takes %s.\n", who, what) == 2) {
	notify("Harry says: Why did " + who + " take " + what + " ? That is stealing!!\n");
    }
    if (sscanf(str, "%s drops %s.\n", who, what) == 2) {
	notify("Harry says: Why did " + who + " drop " + what + " ? Sell it dickhead!!\n");
    }
}

notify(str) {
    say(str);
    write(str);
}
	
how_does_it_feel(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
    if(who == "harry" || who == "Harry")
	return;
    if (sscanf(str, "%s is now level %s.\n", who, what) == 2) {
	notify("Harry says: How does it feel, being of level " + what +
       "?\nHarry says: Are you a real man now?\n");
    }
}
    
smiles(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
    if(who == "harry" || who == "Harry")
	return;
    if (sscanf(str, "%s checks out your bod", who) == 1 &&
	who != "Harry") {
	notify("Harry checks out your bod eagerly.\n");
    }
}
    
say_hello(str) {
    string who;
    if (sscanf(str, "%s arrives.", who) == 1) {
	notify( "Harry says: Hi " + who + ", why don't you go fuck yourself !!\n");
    }
}
    
test_say(str) {
    string a, b, message;

    sscanf(str, "%s %s", a, b);
    if(a == "harry" || a == "Harry")
	return;
    if (!sscanf(str, "%s says: %s\n", a, b) == 2) {
	return;
    }
    str = b;

    if (str == "hello" || str == "hi" || str == "hello everybody") {
	message = "Harry says: Do you want to have sex?\n";
    }
    if (str == "shut up") {
	message = "Harry says: Why do you want me to shut up ? Do you want your ass kicked?\n";
    }
    if (sscanf(str, "%sstay here%s", a, b) == 2 ||
	sscanf(str, "%snot follow%s", a, b) == 2 ||
	sscanf(str, "%sget lost%s", a, b) == 2) {
	message = "Harry says: Ok then,asshole.\n";
    }
    if(!message)
	message = "Harry says: Why do you say '" + str + "'???\n";
    notify(message);
}

follow(str) {
    string who, where;
    if(sscanf(str, "%s leaves %s.\n", who, where) == 2)
	call_other(harry, "init_command", where);
}

gives(str) {
    string who, what, whom;
    int rand;
    object obj, next_obj;
    if(sscanf(str, "%s gives %s to %s.\n", who, what, whom) != 3)
	return;
    if(whom != "Harry")
	return;
    if(what == "firebreather" || what == "special" ||
       what == "beer" || what == "bottle") {
	rand = random(4);
	if(rand == 0) {
	    if(random(10) > 6) {
		notify("Harry sighs and says: I guess you're gonna kill me now.\n");
		obj = first_inventory(harry);
		while(obj) {
		    next_obj = next_inventory(harry);
		    transfer(obj, environment(harry));
		    notify("Harry drops " + call_other(obj, "short") + ".\n");
		    obj = next_obj;
		}
		call_other(harry, "init_command", "west");
	    }
	}
	if(rand == 1) {
	    call_other(harry, "init_command", "drink " + what);
	}
	if(rand == 2) {
	    obj = first_inventory(harry);
	    while(!call_other(obj, "id", what))
		obj = next_inventory(obj);
	    transfer(obj, environment(harry));
	    notify("Harry drops the " + what + ".\n");
	}
	if(rand == 3) {
	    obj = first_inventory(harry);
	    while(!call_other(obj, "id", what))
		obj = next_inventory(obj);
	    transfer(obj, find_living(lower_case(who)));
	    notify("Harry returned the " + what + " to " + who + ".\n");
	}
    } else if(what == "corpse") {
	notify("Harry says: HEY, bury your corpses yourself, asshole.\n");
	obj = first_inventory(harry);
	while(!call_other(obj, "id", what))
	    obj = next_inventory(obj);
	transfer(obj, find_living(lower_case(who)));
	notify("Harry returned the " + what + " to " + who + ".\n");
    } else {
	notify("Harry says: Thank you very much, sir.\n");
    }
}

monster_died() {
    object obj, b;
    int num;
    obj = first_inventory(harry);
    while(obj) {
	b = next_inventory(harry);
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
