#include "living.h"
int current_problem, starts_thinking;
object solved_by, wrong_by;
int problem_value;

short() { return "The old man from sceen 24, the Bridge Keeper";}

long(str) {
    if (str == "bridge keeper" || str == "player") {
        write("The Old man from sceen 24. He guards the bridge over the "+
      "gorge of enternal peril.\n");
	return;
    }
}

id(str) {
    return str == "bridge keeper" || str == "keeper" || str == "man" ||
	str == "old man" || str == "keeper";
}

reset(arg) {
    if (arg)
	return;
    name = "bridge keeper";
    level = 19;
    experience = 50000;
    max_hp = 400;
    hit_point = 400;
    weapon_class = 12;
    is_npc = 1;
    cap_name = "Bridge Keeper";
    alignment = 0;
    enable_commands();
}

show_problem() {
    if (current_problem < 3) {
	write("The board looks like this:\n\n");
	say(call_other(this_player(), "query_name", 0) +
	    " examines the bridge problem.\n");
    } else {
	write("The bridge keeper doesn't want to be bothered anymore.\n");
	return;
    }
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
	      "  abcdefghij\n" +
	      "\nIt is white ('O') to play.\n");
	return;
    }
}

catch_tell(str) {
    string who, what;
    if (sscanf(str, "%s tells you: play %s\n", who , what) == 2 ||
	sscanf(str, "%s says: %s\n", who , what) == 2) {
	set_heart_beat(1);
	if (current_problem == 0) {
	    if (what == "b1" || what == "b 1" || what == "1b" || what == "1 b")
		solved_by = this_player();
	    else
		wrong_by = this_player();
	    problem_value = 50;
	}
	if (current_problem == 1) {
	    if (what == "b2" || what == "b 2" || what == "2b" || what == "2 b")
		solved_by = this_player();
	    else
		wrong_by = this_player();
	    problem_value = 100;
	}
	if (current_problem == 2) {
	    if (what == "d3" || what == "d 3" || what == "3d" || what == "3 d")
		solved_by = this_player();
	    else
		wrong_by = this_player();
	    problem_value = 200;
	}
	starts_thinking = 1;
    } else if (sscanf(str, "%s tells you: %s", who, what) == 2) {
	say("The bridge keeper says: what ?\n");
    }
}

heart_beat() {
    age += 1;
    already_fight = 0;
    attack();
    if (starts_thinking) {
	say("The bridge keeper contemplates a proposed play.\n");
	starts_thinking = 0;
	return;
    }
    if (solved_by) {
	int i;
	i = current_problem + 1;
	say("The bridge keeper says: Right ! That works !\n" +
	    "He immediately plays out a new problem.\n");
	tell_object(solved_by,
		    "You feel that you have gained some experience.\n");
	call_other(solved_by, "add_exp", problem_value);
	solved_by = 0;
	current_problem += 1;
	set_heart_beat(0);
    }
    if (wrong_by) {
	say("The bridge keeper says: No, that doesn't work.\n");
	say("He sinks back into his deep thought.\n");
	wrong_by = 0;
	set_heart_beat(0);
    }
}

query_name() { return "bridge keeper"; }
