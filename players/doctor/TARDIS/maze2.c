int exit_num;

short() {
    return "Brightly lit corridor";
}

long() {
    write("You find yourself moving down a brightly lit corridor.\n");
write("It seems to go on forever....\n");
    write("There are four obvious exits: back, forward, right and left.\n");
}

reset() {
    exit_num = random(4);	/* "grin" */
}

init() {
    add_action("e0","back");
    add_action("e1","forward");
    add_action("e2","left");
    add_action("e3","right");
}

e0() {
    if (exit_num == 0)
	call_other(this_player(), "move_player", "back#/players/doctor/TARDIS/maze3");
    else
	call_other(this_player(), "move_player", "back#/players/doctor/TARDIS/maze1");
    return 1;
}

e1() {
    if (exit_num == 1)
	call_other(this_player(), "move_player", "forward#/players/doctor/TARDIS/maze3");
    else
	call_other(this_player(), "move_player", "forward#/players/doctor/TARDIS/maze1");
    return 1;
}

e2() {
    if (exit_num == 2)
	call_other(this_player(), "move_player", "left#/players/doctor/TARDIS/maze3");
    else
	call_other(this_player(), "move_player", "left#/players/doctor/TARDIS/corridor5");
    return 1;
}

e3() {
    if (exit_num == 3)
	call_other(this_player(), "move_player", "right#/players/doctor/TARDIS/maze3");
    else
	call_other(this_player(), "move_player", "right#/players/doctor/TARDIS/corridor6");
    return 1;
}
