#include "/players/dreamspeakr/closed/ansi.h"
#include "/players/mythos/closed/guild/name.h"
#define PATH "/players/dreamspeakr/CASTLE/"
#define ENV environment()

object top_list;
object player;
int current_problem, starts_thinking;
object solved_by, wrong_by;
int problem_value;

reset(arg) {
    move_object(clone_object("/players/dreamspeakr/CASTLE/OBJ/menu.c"),this_object());
    start_player();
    if (!top_list || !present(top_list, this_object())) {
	top_list = clone_object("obj/level_list");
	move_object(top_list, this_object());
    }
    if (arg) return;
    set_light( 1);
}

short() {
    return HIB+"The Open Air Lounge"+NORM;
}

init() {
    add_action("south");
    add_verb( "south");
    add_action("order");
    add_verb("order");
    add_action("order");
    add_verb("buy");
    add_action("look");
    add_verb("look");
}
south() {
  move_object(this_player(), "/players/dreamspeakr/CASTLE/c112.c");
  command("look",this_player());
  return 1;
} 

long() {
    write("\n");
    write("     The sounds of music and laughter drift with the wind in \n");
    write("this open air lounge. A semi-circle of pillars border the room.  \n");
    write("Dominating the center is a large marble bar.  Spinning slowly \n");
    write("overhead a mysterious menu floats.\n");
    write("\n");
    write("The only obvious exit is:  south.\n");

}

order(str) {
   int cost,heal,strength;
   string type;
    if (!str) {
       write("What would you like to order/buy?\n");
       return 1;
    }
   switch(str) {
      case "ale":
         cost=15;
         heal=0;
         strength=5;
         type="drink_alcohol";
         break;
      case "house":
         cost=150;
         heal=10;
         strength=9;
         type="drink_alcohol";
         break;
      case "fine":
         cost=250;
         heal=25;
         strength=14;
         type="drink_alcohol";
         break;
      case "berries":
         cost=200;
         heal=18;
         strength=12;
         type="eat_food";
         break;
      case "lamb":
         cost=275;
         heal=27;
         strength=14;
         type="eat_food";
         break;
      case "nectur":
         cost=175;
         heal=15;
         strength=12;
         type="drink_soft";
         break;
      case "tea":
         cost=250;
         heal=25;
         strength=15;
         type="drink_soft";
         break;
   }
   if(!cost) {
      write("The servant asks:  What would you like to buy?\n");
      return 1;
   }
   write("You order some "+str+".\n");
   say(this_player()->query_name()+" orders some "+str+".\n");
   if(type=="drink_alcohol" && present(fear,this_player())) {
      write("The servant says:  I'm afraid it has been decreed by the Gods \n"+
            "that we cannot sell you alcohol.\"\n");
      return 1;
   }
   if(this_player()->query_money() < cost) {
      write("The servant says:  You don't appear to have that many coins to purchase that.\"\n");
      return 1;
   }
   if(!call_other(this_player(),type,strength) == 1) {
      write("The servant says:  Whoa, hold it there, buddy.  You've had too much.\"\n");
      return 1;
   }
   write("The servant takes your "+cost+" coins happily, giving you the "+str+".\n");
   this_player()->add_money(-cost);
   this_player()->heal_self(heal);
   give_stats();
   return 1;
}

give_stats() {
   write(HIG+"\tHP: "+NORM);
   write(HIW+this_player()->query_hp()+HIG+"["+HIW+this_player()->query_mhp()+HIG+"]  "+NORM);
   write(HIY+"SP: "+NORM);
   write(HIW+this_player()->query_spell_point()+HIY+"["+HIW+this_player()->query_msp()+HIY+"]\n"+NORM);
}

/*
 * Make this global, and only initialized once.
 */
string chat_str, function, type, match;

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
	move_object(player, "players/dreamspeakr/CASTLE/c129.c");
	if (!function) {
	    function = allocate(2);
	    type = allocate(2);
	    match = allocate(2);
	    function[0] = "got_play";
	    type[0] = "says:";
	    match[0] = " play";
	    function[1] = "make_move";
	    type[1] = "PISS";
	    match[1] = " OFF";
	}
	call_other(player, "set_match", this_object(), function, type, match);
	if (!chat_str) {
	    chat_str = allocate(5);
	    chat_str[0] = "A soft wind blows your hair lightly.\n";
	    chat_str[1] = "A song bird sings merrily sitting upon a pillar.\n";
	    chat_str[2] = "The harp plays softly in the background.\n";
	    chat_str[3] = "A group of men off to the side click their mugs together in a toast.\n";
	    chat_str[4] = "A servant tells you:  Would you would like to see the menu?\n";
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

query_drop_castle() {
    return 1;
}

