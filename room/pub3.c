/* #define MUST_STAY_WITH_DRINKS */
object top_list;
object player;
int current_problem, starts_thinking;
object solved_by, wrong_by;
int problem_value;

object rules;

reset(arg) {
    start_player();
    if (!present("bartender"))
     move_object(clone_object("obj/bartender"), this_object());
    if (!top_list || !present(top_list, this_object())) {
	top_list = clone_object("obj/level_list");
	move_object(top_list, this_object());
    }
    if (!rules || !present(rules, this_object())) {
	rules = clone_object("obj/Go/rules");
	move_object(rules, this_object());
    }
    if (arg) return;
    set_light( 1);
}

short() {
    return "The local pub";
}

init() {
#ifndef __LDMUD__ /* Rumplemintz */
    add_action("move");
    add_verb( "north");
    add_action("up","up");
    add_action("order");
    add_verb("order");
    add_action("order");
    add_verb("buy");
#else
  add_action("move", "north");
  add_action("up", "up");
  add_action("order", "order");
  add_action("order", "buy");
#endif
    add_action("look","look",1);
     add_action("look", "examine");
    add_action("look", "read");
}

move() {
#ifdef MUST_STAY_WITH_DRINKS
     if (has_drink(this_player())) {
        tell_object(this_player(),
                    "You are not allowed to leave with drinks!\n");
        return 1;
     }
#endif
     call_other(this_player(), "move_player",  "north" + "#" +"room/alley");
     return 1;
}
up() {
      call_other(this_player(), "move_player",  "up" + "#" +"players/boltar/sprooms/boltar_office");
      return 1;
}

long() {
    write("You are in the local pub.\n");
     write("This old pub has been restored to a like-new conditon. It\n"+ 
     "features plastered walls with paitntings and wood tables with\n"+
     "chairs scattered about the place. There is a large wooden bar\n"+
     "where the barkeep usually is, serving drinks to all who order.\n"+
     "There are stools in front of the bar and a large mirror with\n"+
     "shelves full of booze behind it. There is a large sign behind\n"+
     "the bar with the drinks and prices written on it.\n");

  /*write("The only obvious exit is to " +  "north" + ".\n");
  */
    write("There are stairs going up and the only exit to the outside is\n"+
          "to the north.\n");
}

order(str)
{
    object drink;
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
        if (!present("bartender")) {
       write("The bartender is gone and all the bottles appear to be \n"+
         "broken. Their contents spilled on the floor behind the bar.\n");
      return 1;
    }
    if (str == "beer") {
	name = str;
	short_desc = "A bottle of beer";
	mess = "That feels good";
	heal = 0;
	value = 24;
	strength = 2;
    }
    else if (str == "special" || str == "special of the house") {
	name = "special";
	short_desc = "A special of the house";
	mess = "A tingling feeling goes through your body";
	heal = 10;
	value = 162;
	strength = 8;
    } else if (str == "firebreather" || str == "fire") {
	name = "firebreather";
	short_desc = "A firebreather";
	mess = "A shock wave runs through your body";
	heal = 25;
	value = 242;
	strength = 12;
#if 0
    } else if (str == "potion" || str == "potion of healing") {
	name = "potion";
	short_desc = "A potion of healing";
	mess = "You are totally healed";
	heal = 1000;
	value = 10000;
	strength = 0;
#endif
    } else {
       write("What ?\n");
       return 1;
    }
    if (call_other(this_player(), "query_money", 0) < value) {
        write("That costs " + value + " gold coins, which you don't have.\n");
	return 1;
    }
    drink = clone_object("obj/drink");
    if (!call_other(this_player(), "add_weight",
	call_other(drink, "query_weight"))) {
	write("You can't carry more.\n");
	destruct(drink);
	return 1;
    }
    if (!call_other(drink, "set_value", name + "#" + short_desc + "#" + mess +
	"#" + heal + "#" + value + "#" + strength)) {
	write("Error in creating drink.\n");
	destruct(drink);
	return 1;
    }
    call_other(drink, "set_pub");
    move_object(drink, this_player());
    call_other(this_player(), "add_money", - value);
    write("The bartender serves you your drink.\n");
    write("You pay " + value + " for a " + name + ".\n");
    say(call_other(this_player(), "query_name", 0) + " orders a " +
	name + ".\n");
    say("The bartender serves up the drink.\n");
    return 1;
}

/*
 * Make this global, and only initialized once.
 */
#ifndef __LDMUD__ /* Rumplemintz */
string chat_str, function, type, match;
#else
string chat_str, type, match;
string Func;
#endif

start_player() {
    if(!player) {
	player = clone_object("obj/monster_lars");
	call_other(player, "set_name", "player");
	call_other(player, "set_alias", "go player");
	call_other(player, "set_short", "Go player");
	call_other(player, "set_long", 
		   "A man sitting beside a go board, concentrating on a problem.\n" +
		   "He looks as if he wants help. Why not look at his problem,\n" +
		   "and tell him where to play ?\n");
	call_other(player, "set_level",10);
	call_other(player, "set_al",200);
	call_other(player, "set_ep",39000);
	call_other(player, "set_hp",100);
	call_other(player, "set_wc",12);
	move_object(player, "room/pub3");
#ifndef __LDMUD__ /* Rumplemintz */
	if (!function) {
	    function = allocate(2);
#else
        if (!Func) {
            Func = allocate(2);
#endif
	    type = allocate(2);
	    match = allocate(2);
#ifndef __LDMUD__ /* Rumplemintz */
	    function[0] = "got_play";
#else
            Func[0] = "got_play";
#endif
	    type[0] = "says:";
	    match[0] = " play";
#ifndef __LDMUD__ /* Rumplemintz */
	    function[1] = "make_move";
#else
            Func[1] = "make_move";
#endif
	    type[1] = "PISS";
	    match[1] = " OFF";
	}
#ifndef __LDMUD__ /* Rumplemintz */
	call_other(player, "set_match", this_object(), function, type, match);
#else
        call_other(player, "set_match", this_object(), Func, type, match);
#endif
	if (!chat_str) {
	    chat_str = allocate(5);
	    chat_str[0] = "Go player says: Hm. This is tricky!\n";
	    chat_str[1] = "Go player says: The moron who wrote this book didn't deal with this problem.\n";
	    chat_str[2] = "Go player says: A throw in here should just be wasted.\n";
	    chat_str[3] = "Go player says: This group is more alive than I am.\n";
	    chat_str[4] = "Go player says: This is simple using oi-otoshi.\n";
	}
	call_other(player, "load_chat", 1, chat_str);
    }
    current_problem = 0;
}

got_play(str) {
    string who, what;
    if (sscanf(str, "%s tells you: play %s\n", who , what) == 2 ||
	sscanf(str, "%s says: play %s\n", who , what) == 2) {
	if (current_problem == 0) {
	    if (what == "b1" || what == "b 1" || what == "1b" || what == "1 b")
		solved_by = find_living(lower_case(who));
	    else
		wrong_by = find_living(lower_case(who));
	    problem_value = 50;
	}
	if (current_problem == 1) {
	    if (what == "b2" || what == "b 2" || what == "2b" || what == "2 b")
		solved_by = find_living(lower_case(who));
	    else
		wrong_by = find_living(lower_case(who));
	    problem_value = 100;
	}
	if (current_problem == 2) {
	    if (what == "d3" || what == "d 3" || what == "3d" || what == "3 d")
		 solved_by = find_living(lower_case(who));
	     else
		 wrong_by = find_living(lower_case(who));
	    problem_value = 200;
	}
	notify("The go player contemplates a proposed play.\n");
	tell_object(player, "Arne PISS OFF\n");
    } else if (sscanf(str, "%s tells you: %s", who, what) == 2) {
	say("The go player says: what ?\n");
    }
}

show_problem() {
    if(current_problem > 2) {
	write("The player looks tired.\n");
	return;
    }
    if(!player || !living(player))
       return;
    write("The board looks like this:\n\n");
    say(call_other(this_player(), "query_name", 0) +
	" examines the go problem.\n");
    if (current_problem == 0) {
	write("5|.......\n" +
	      "4|.......\n" +
	      "3|@@@@@..\n" +
	      "2|OOOO@..\n" +
	      "1|...O@..\n" +
	      " --------\n" +
	      "  abcdefg\n" +
	      "\nIt is black ('@') to play.\n");
	return;
    } else if (current_problem == 1) {
	write("7|.......\n" +
	      "6|.......\n" +
	      "5|@@@....\n" +
	      "4|OOO@@..\n" +
	      "3|O.OO@..\n" +
	      "2|...O@..\n" +
	      "1|..OO@..\n" +
	      " --------\n" +
	      "  abcdefg\n" +
	      "\nIt is black ('@') to play.\n");
	return;
    } else if (current_problem == 2) {
	write("5|..........\n" +
	      "4|...@@@@@..\n" +
	      "3|@@@.O...@.\n" +
	      "2|@OO@OOOO@.\n" +
	      "1|@OO.O...@.\n" +
	      " -----------\n" +
	      "  abcdefg\n" +
	      "\nIt is white ('O') to play.\n");
	return;
    } else {
	write("The go player does not want to be disturbed any more.\n");
    }
}

make_move(str) {
    if (solved_by) {
	int i;
	i = current_problem + 1;
	say("The go player says: Right ! That works !\n" +
	    "He immediately plays out a new problem.\n");
	tell_object(solved_by,
		    "You feel that you have gained some experience.\n");
	call_other(solved_by, "add_exp", problem_value);
	solved_by = 0;
	current_problem += 1;
    }
    if (wrong_by) {
	say("The go player says: No, that doesn't work.\n");
	say("He sinks back into his deep thought.\n");
	wrong_by = 0;
    }
}

notify(str) {
    say(str);
    write(str);
}

look(str) {
    string what, rest;
      if (!str) return 0;
  if (str=="at sign"||str=="at large sign"||str=="sign"||str=="large sign") {
      write("A large sign here says:\n");
    write("You can order drinks here.\n\n");
    write("     First class beer    : 24 coins\n");
    write("     Special of the house: 162 coins\n");
    write("     Firebreather        : 242 coins\n\n");
    /* write("     Potion of healing   : 200 coins\n\n"); */

  return 1;
  }
  if (str == "at tables" || str == "at table") {
     write("Nice, well made wood tables are throughout the pub.\n");
     return 1;
  }
  if (str == "at chairs" || str == "at chair") {
     write("Simple factory made wood chairs of quality construction.\n");
     return 1;
  }
  if (str == "at stool" || str == "at stools") {
     write("A nice, solid wood-framed bar stool with a leather covered\n"+
      "cusion.\n");
     return 1;
  }
  if (str == "at bar" || str == "wood bar") {
    write("A restored, ornately carved bar.\n"); return 1;
  }
  if(str=="at paintings" || str=="at painting") {
    write("The paintings are landscape and village sceens of the time\n"+
    "when this pub was first built. Closer examination shows that some\n"+
    "are of photographs of the pub over time, and documents of its \n"+
    "restoration.\n");
   return 1;
  }
  if (str == "at shelf" || str == "at shelves" || str == "mirror") {
   if (present("bartender"))
    write("A series of glass shelves in front of the restored antique\n"+
     "mirror hold the booze that is served here.\n");
   else
    write("The glass shelves are knocked down and broken, the mirror\n"+
     "is cracked. The bottles once on the shelves lay broken on the floor.\n");
    return 1;
  }

    if(str) {
	if(!player || !living(player))
	    return 0;
	if(sscanf(str, "at %s", what) == 1 || sscanf(str, "%s", what) == 1) {
	    if(what == "game" || what == "problem" || what == "board") {
		show_problem();
		return 1;
	    }
	}
    }
    return 0;
}

#ifdef MUST_STAY_WITH_DRINKS
has_drink(obj) {
     status drink;
     object ob;
     ob = first_inventory(obj);
     while(ob) {
        if (call_other(ob, "id", "drk2"))
             drink = 1;
        if (call_other(ob,"can_put_and_get")) {
             if (has_drink(ob))
                  drink = 1;
        }
        ob = next_inventory(ob);
     }
     return drink;
}
#endif

