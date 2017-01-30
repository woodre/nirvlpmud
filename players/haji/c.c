#include "living.h"
int current_problem, starts_thinking;
object solved_by, wrong_by;
int problem_value;

short() { return "Go player"; }

long(str) {
    if (str == "go player" || str == "player") {
	write("A man sitting beside a go board, concentrating on a problem.\n");
	write("He looks as if he wants help. Why not look at his problem,\n");
	write("and tell him where to play ?\n");
	return;
    }
    if (str == "problem" || str == "board" || str == "go board")
	show_problem();
}

id(str) {
    return str == "go player" || str == "problem" || str == "board" ||
	str == "go board" || str == "player";
}

reset(arg) {
    if (random(5) == 0)
	current_problem = 0;
    if (arg)
	return;
    cap_name = "Go player";
    name = "go player";
    level = 10;
    experience = 39000;
    max_hp = 100;
    hit_point = 100;
    weapon_class = 12;
    is_npc = 1;
    alignment = 200;
    enable_commands();
/*    enable_commands("laugh");   */
}
