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
    if (!present("bandit")) {
   band = clone_object("obj/bandit");
   move_object(band, this_object());
   }

*/
    if (!newspaper || !present(newspaper)) {
	newspaper = clone_object("obj/newspaper");
	move_object(newspaper, this_object());
    }
    if (arg) return;
    set_light( 1);
}

short() {
 return "Callahan's Galaxy Saloon";
}

init() {
    add_action("move","leave");
    add_action("order","order");
    add_action("order","buy");
    add_action("portal","portal");
}

move() {
    object ob;

 call_other(this_player(),"move_player","leave"+"#"+
     WORLD3+"world3_1");
    return 1;
}
portal() {
write("the portal looks burnt out for the time being\n");
say("the portal looks burnt out for the time being\n");
return 1;
          }

long() {
  write("This is Callahan's Galaxy Saloon.\n");
    write("A large sign here says:\n");
 write("THIS BAR SERVES EVERYONE! IF A FIGHT STARTS\n" +
       "THE BOUNCERS ARE SURE TO FINISH IT! SO BE NICE\n");
write("   Hot Lava Java ****> 20 coins\n");
write("   Lady Chaser   ****> 10 coins\n");
write("   Red Rocket    ****> 150 coins\n");
write("   Stalker       ****> 500 coins\n");
write("\n\n");
write("This pub is very inter-galactical so don't push any\n" +
    "anti-species policies in here. There is a roaring fire\n" +
      "place in the center of the room and everything seems old\n" +
    "english. 'Leave' when you are ready. A small grey portal stands\n"+
   "in an unlit and unnoticed corner of the saloon. (portal) to try\n");
}

order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (str == "chaser") {
mess = "WHOA BOY! she isn't that good looking!\n";
	heal = 1;
        value = 10;
	strength = 3;
    }
else if (str == "rocket" || str == "red rocket") {
mess = "That baby just rocked your world!\n"+
       "You aren't feeling shit now baby!\n";
	heal = 10;
        value = 150;
        strength = 7;
} else if(str == "stalker") {
mess = "You slam your drink and wake up on the floor\n"+
       "Your story is that someone knocked you down (yeah right)\n";
heal = 40;
     value = 500;
strength =  17;
} else if (str == "java" || str == "hot lava java") {
mess = "Callahan looks at you funny but gives you the drink\n";
	heal = 0;
	value = 20;
strength = -3;
    } else {
write("Callahan smirks\n" +
      "Callahan says: now what did you want?\n");
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
       str +", and Callahan laughs saying: you can't handle that!\n");
write("You Yell for a "+str+"\n"+
", but Callahan laughs saying: you can't handle that!\n");
	} else {
	    say(call_other(this_player(), "query_name", 0) + " orders a " +
str +", but Callahan laughs and starts wiping the bar\n");
write("You yell for a "+str+", but Callahan ignores you\n");
	}
	call_other(this_player(), "add_money", - cost);
	return 1;
    }
    if (!call_other(this_player(), "drink_alcohol", strength)) {
	write("The Callahan says: I think you've had enough.\n");
	say(call_other(this_player(), "query_name", 0) + " asks for a " +
		str + " but the Callahan refuses.\n");

	return 1;
    }
    write("You pay " + cost + " coins for a " + str + ".\n");
    say(call_other(this_player(), "query_name", 0) + " orders a " + str + ".\n");
    call_other(this_player(), "add_money", - cost);
    call_other(this_player(), "heal_self", heal);
    write(mess + ".\n");
    return 1;
}
