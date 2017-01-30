
object top_list;
 
reset(arg) {
	if (!top_list || !present(top_list)) {
	  top_list = clone_object("obj/level_list");
	  move_object(top_list, this_object());
	}
	if (arg) return;
	set_light( 1);
}
 
short() {
	return "Sickbay";
}
 
init() {
        add_action("north","north");
        add_action("order","order");
        add_action("order","buy");
}
 
north() {
	object ob;
        call_other(this_player(), "move_player",  "north#players/rich/quest/main1.c");
	return 1;
}
long() {
    write("You are in sickbay.\n");
    write("Resuscitation services include:\n\n");
    write("     band aid           :    20 coins\n");
    write("     splint              :   280 coins\n");
    write("     mouth to mouth      :   400 coins\n");
    write("     full body CPR       :   800 coins\n");
    write("     bones mccoy`s healing elixir   :  1200 coins\n");
    write("\n");
    write("The only obvious exit is north.\n");
}
 
order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;
 
    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    else if (str == "bandaid" || str == "band aid") {
	mess = "Ahhh.. that feels good on your burned skin";
	heal = 1;
strength = 2;
	value = 20;
    }
    else if (str == "splint" || str == "splint" || str == "splint") {
mess = "Ohhh!! your leg now feels much better than before";
	heal = 7;
	value = 280;
strength = 4;
    }
    else if (str == "mouth" || str == "mouth to mouth") {
	mess = "A doctor of your sexual preference breathes life into you";
	heal = 10;
	value = 400;
strength = 15;
    }
    else if (str == "CPR" || str == "full body CPR" || str == "cpr") {
	mess = "Two doctors of your sexual preference do it to you";
	heal = 20;
	value = 800;
strength = 15;
    }
    else if (str == "elixir" || str == "elixir" || str == "elixir") {
	mess = "You shout 'Cowabunga dude!' as a shock wave runs through your body";
	heal = 30;
	value = 1200;
	strength = 16;
    } else {
       write("The doctor says: What do you want?\n");
       return 1;
    }
    if (call_other(this_player(), "query_money", 0) < value) {
        write("That costs " + value + " gold coins, which you don't have.\n");
	return 1;
    }
    if (strength > (call_other(this_player(), "query_level") + 2)) {
	if (strength > (call_other(this_player(), "query_level") + 5)) {
	    /* This drink is *much* too strong for the player */
	    say(call_other(this_player(), "query_name", 0) + " orders " +
		str + ", and immediately throws it up.\n");
	    write("You order " + str + ", try to drink it, and throw up.\n");
	} else {
	    say(call_other(this_player(), "query_name", 0) + " orders " +
		str + ", and spews it all over you!\n");
	    write("You order " + str + ", try to drink it, and sputter it all over the room!\n");
	}
	call_other(this_player(), "add_money", - value);
	return 1;
    }
    if (!call_other(this_player(), "drink_alcohol", strength)) {
	write("The doctor says: I think you've had enough.\n");
	say(call_other(this_player(), "query_name", 0) + " asks for " +
		str + " but the doctor refuses.\n");
 
	return 1;
    }
    write("You pay " + value + " coins for " + str + ".\n");
    say(call_other(this_player(), "query_name", 0) + " orders " + str + ".\n");
    call_other(this_player(), "add_money", - value);
    call_other(this_player(), "heal_self", heal);
    write(mess + ".\n");
    return 1;
}
realm(){return "enterprise";}
