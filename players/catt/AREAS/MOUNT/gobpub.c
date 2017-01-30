#include "/players/catt/AREAS/base_defines.c"
object newspaper, top_list;
object band;

reset(arg) {
    if (!present("go player"))
	move_object(clone_object("obj/go_player"), this_object());
    if (!top_list || !present(top_list)) {
	top_list = clone_object("obj/level_list");
	move_object(top_list, this_object());
    }
/*

*/
    if (!newspaper || !present(newspaper)) {
	newspaper = clone_object("obj/newspaper");
	move_object(newspaper, this_object());
    }
    if (arg) return;
 set_light( 2);
}

short() {
    return "Goblin pub";
}

init() {
    add_action("move", "up");
    add_action("order","order");
    add_action("order","buy");
    add_action("portal","portal");
}

move() {
    object ob;

   call_other(this_player(), "move_player", "up" + "#" +MOUNT+"level1_stairs_down");
    return 1;
}

portal() {
write("the portal looks burnt out for the time being\n");
say("the portal looks burnt out for the time being\n");
return 1;
     }
long() {
  write("quid idkls skosh djore opw.\n");

 write("you can barely make out some of what is served here.\n");
 write("OSH SDFHOA ILSO GID EIDGO SHOOSHE SIDFNE.\n\n");
    write("You can order drinks here.\n\n");
 write("     nazsa               : 10 goldies\n");
 write("     baelae              : 20 goldies\n");
  write("     contosh             : 150 goldies\n");
  write("     lakash              : 230 goldies\n\n");
  write("Tid soke sofd foas osd up.\n");
write("A small green portal stands at the end of the room\n");
write("(portal) to enter\n");
}

order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
  if(str == "nazsa") {
	mess = "That feels good";
	heal = 1;
        value = 10;
	strength = 3;
    }
  else if (str == "contosh") {
	mess = "A tingling feeling goes through your body";
	heal = 10;
        value = 150;
        strength = 7;
  } else if (str == "lakash") {
	mess = "A shock wave runs through your body";
	heal = 25;
        value = 230;
        strength = 14;
  } else if (str == "baelae") {
	mess = "You feel somewhat invigorated";
	heal = 0;
	value = 20;
	strength = -2;
    } else {
       write("The bartender says: What do you want?\n");
       return 1;
    }
    if (call_other(this_player(), "query_money", 0) < value) {
        write("That costs " + value + " gold coins, which you don't have.\n");
	return 1;
    }
    cost = value;
    if (strength > (call_other(this_player(), "query_level") + 2)) {
	if (strength > (call_other(this_player(), "query_level") + 5)) {
	    /* This drink is *much* too strong for the player */
	    say(call_other(this_player(), "query_name", 0) + " orders a " +
		str + ", and immediately throws it up.\n");
	    write("You order a " + str + ", try to drink it, and throw up.\n");
	} else {
	    say(call_other(this_player(), "query_name", 0) + " orders a " +
		str + ", and spews it all over you!\n");
	    write("You order a " + str + ", try to drink it, and sputter it all over the room!\n");
	}
	call_other(this_player(), "add_money", - cost);
	return 1;
    }
    if (!call_other(this_player(), "drink_alcohol", strength)) {
	write("The bartender says: I think you've had enough.\n");
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
