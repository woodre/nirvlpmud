object newspaper, top_list;
object band,ob;
object stone;
reset(arg) {
    if (!present("go player"))
	move_object(clone_object("obj/go_player"), this_object());
    if (!top_list || !present(top_list)) {
	top_list = clone_object("obj/level_list");
	move_object(top_list, this_object());
    }
    if (!newspaper || !present(newspaper)) {
	newspaper = clone_object("obj/newspaper");
	move_object(newspaper, this_object());
    }
/*  added jukebox for fun 4/2/97  Eurale  */
  if(!present("jukebox")) {
  move_object(clone_object("players/cosmo/jb/jukebox2.c"),
    this_object()); }
    if (arg) return;
    set_light( 1);
}

short() {
    return "Rose's Bar";
}

init() {
   add_action("move","south");
    add_action("order","order");
    add_action("order","buy");
   add_action("bribe","bribe");
     add_action("ask","ask");
}

move() {
    object ob;

    call_other(this_player(), "move_player",  "south" + "#" +"players/hawkeye/room/rd4.c");
    return 1;
}

long() {
    write("You are in Rose's Bar in Korea.\n");
    write("A large sign here says:\n");
    write("WE RESERVE THE RIGHT TO CHANGE PRICES WITHOUT NOTICE\n\n");
    write("You can order drinks here.\n\n");
    write("     Grape Neihi:           10 coins\n");
    write("     A Good Potion:         500 coins\n");
    write("     Double Bourbon:        150 coins\n");
    write("     A very dry Martini:    230 coins\n\n");
    write("The only obvious exit is south.\n");
}

bribe(str) {
int money;
if(!str) {
write("Bribe Who?\n");
return 1;}
if(str == "rose") {
if(this_player()->query_money() < 10000) {
write("How can you bribe Rose with out enough money?\n");
return 1;}
write("Rose leads you to a back room. Looking out, you see a dirt road and a jeep." +
"\n\n\nRose points to the jeep and says 'Get in Joe'\n" +
"\n");
write("You jump into the jeep and the driver takes off. You nearly\n"+
"fall out of the jeep as you round the corners. Pulling up to a \n" +
"large green building, the driver beckons you to get out.\n");
write("\n\n\n");
this_player()->add_money(-10000);
move_object(this_player(),"players/hawkeye/room/hq.c");
command("look",this_player());
  return 1;
}
}
ask(str) {
if(!str){return 1;}
if(str == "rose") {
write("My memory is failing i think i need a little $SOMETHING$ to\n" +
"jog my memory.\n");
return 1;
}
}
order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (str == "neihi") {
	mess = "You feel better but cant get the purple moustache off!";
	heal = 1;
        value = 10;
	strength = 3;
    }
    else if (str == "bourbon" || str == "double bourbon") {
	mess = "A tingling feeling goes through your body";
	heal = 10;
        value = 150;
        strength = 7;
    } else if (str == "martini" || str == "dry") {
   mess = "The back of your throat burns as the unrefined booze hits it!";
	heal = 25;
        value = 230;
        strength = 14;
    } else if (str == "potion" || str == "good potion") {
  value = 500;
  heal = 0;
  strength  = 0;
if (call_other(this_player(), "query_money", 0) > value) {
ob= clone_object("players/hawkeye/items/good.c");
 move_object(ob, this_player());
}
mess = "You now have a potion";
    } else {
       write("  Rose says: What you want Joe??\n");
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
	write("  Rose says: I think you've had enough.\n");
	say(call_other(this_player(), "query_name", 0) + " asks for a " +
		str + " but Rose refuses.\n");

	return 1;
    }
    write("You pay " + cost + " coins for a " + str + ".\n");
    say(call_other(this_player(), "query_name", 0) + " orders a " + str + ".\n");
    call_other(this_player(), "add_money", - cost);
    call_other(this_player(), "heal_self", heal);
    write(mess + ".\n");
    return 1;
}
