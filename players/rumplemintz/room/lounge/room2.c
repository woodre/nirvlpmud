reset(arg) {
    if (!present("go player"))
        move_object(clone_object("obj/go_player"), this_object());
    if (!present("list"))
	move_object(clone_object("obj/level_list"), this_object());
    if (!present("dartboard"))
        move_object(clone_object("players/rumplemintz/obj/dartboard"), this_object());
     if (!present("bandit"))
	move_object(clone_object("obj/bandit"), this_object());

     if (!present("newspaper"))
	move_object(clone_object("obj/newspaper"), this_object());
    if (arg) return;
    set_light( 1);
}

short() {
    return "The Landing Lounge";
}

init() {
    add_action("move");
    add_verb( "northeast");
    add_action("look", "look");
    add_action("move1");
    add_verb("crack");
    add_action("move2");
    add_verb("southwest");
    add_action("move3");
    add_verb("stairs");
    add_action("move4");
    add_verb("window");
    add_action("order");
    add_verb("order");
    add_action("order");
    add_verb("buy");
}

move() {
    object ob;

    call_other(this_player(), "move_player", "northeast" + "#" +"players/rumplemintz/room/lounge/room1");
        return 1;
}
look(str){
	if(!str) return 0;
	if(str="at crack"){
	   write("An elongated crack in the floor. Type 'crack' to enter.\n");
	   say(this_player()->query_name()+" examines the crack in the floor.\n");
	}
	else return 0;
	return 1;
}

move1() {
        object ob;

        call_other(this_player(), "move_player", "crack" + "#" +"players/rumplemintz/room/Guild/Ent");
        return 1;
}

move2() {
        object ob;

         call_other(this_player(), "move_player", "southwest" + "#" +"players/rumplemintz/room/lounge/room3");
        return 1;
}

move3() {
        object ob;

        call_other(this_player(), "move_player", "stairs" + "#" +"players/rumplemintz/room/lounge/whore");
        return 1;
}

move4() {
        object ob;

	call_other(this_player(), "move_player", "window" + "#" +"players/rumplemintz/room/lounge/window");
        return 1;
}
long() {
     write("You have entered the Landing Lounge.\n");
    write("A rusted old sign here says:\n");
    write("Whore house upstairs, get mean, you get thrown out, ARGH!\n");
    write("WE RESERVE THE RIGHT TO CHANGE PRICES WITHOUT NOTICE\n\n");
    write("You can order drinks here.\n\n");
    write("     Corona Extra        :  10 coins\n");
    write("     Jaun Valdez special :  20 coins\n");
    write("     Shot of Rumplemintz : 150 coins\n");
    write("     Jungle Juice        : 230 coins\n\n");
    write("There are four obvious exits.\n");
    write("northeast, southwest, stairs, window.\n");
    write("There is a crack in the floor.\n");
}

order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (str == "corona") {
        mess = "Ya gotta love imported beer!";
        heal = 1;
        value = 10;
        strength = 3;
    }
    else if (str == "shot" || str == "shot of rumplemintz" ) {
        mess = "You slam it down with amazing speed, that was smooth!";
        heal = 8;
        value = 150;
        strength = 7;
    } else if (str == "jungle juice" || str == "juice") {
        mess = "Your body goes into convultions for a second";
        heal = 19;
        value = 230;
        strength = 12;
    } else if (str == "special" || str == "juan valdez special") {
        mess = "That woke you up a little...";
        heal = 0;
        value = 20;
        strength = -2;
    } else {
       write("The bartender says: Excuse me?\n");
       return 1;
    }
    if (call_other(this_player(), "query_money", 0) < value) {
        write("Why don't you go get " + value + " coins, then i'll give one to ya.\n");
        return 1;
    }
    cost = value;
    if (strength > (call_other(this_player(), "query_level") + 2)) {
        if (strength > (call_other(this_player(), "query_level") + 5)) {
            /* This drink is *much* too strong for the player */
            say(call_other(this_player(), "query_name", 0) + " orders a " +
                str + ", and throws up.\n");
            write("You try to drink a " + str + ", and spit it all over.\n");
        } else {
            say(call_other(this_player(), "query_name", 0) + " orders a " +
                str + ", and spews it all over you!\n");
            write("You order a " + str + ", try to drink it, and sputter it all over the room!\n");
        }
        call_other(this_player(), "add_money", - cost);
        return 1;
    }
    if (!call_other(this_player(), "drink_alcohol", strength)) {
        write("The bartender says: No more for you, ya drunkard!\n");
        say(call_other(this_player(), "query_name", 0) + " asks for a " +
                str + " but the bartender refuses.\n");

        return 1;
    }
    write("You pay " + cost + " coins for a " + str + ".\n");
    say(call_other(this_player(), "query_name", 0) + " orders a " + str + ".\n");
    call_other(this_player(), "add_money", - cost);
    call_other(this_player(), "heal_self", heal);
    write(mess + ".\n");
    return 1;
}
