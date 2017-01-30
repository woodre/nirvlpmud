#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);


short_desc = "An old pub";
long_desc =	
           "  A sandstone fireplace lights up the dim room and, across from  \n"+
           "it is a large sturdy oak bar.  A large man stands behind it calmly \n"+
           "cleaning a dirty tankard.  A wooden sign hangs on the bar naming \n"+
           "the services available and, a few sturdy table and chairs dot the  \n"+
           "rest of the room.  The only exit is back to the east. \n" ;

items = ({
  "fireplace","A large sandstone fireplace lights up the room with a soft light",
  "bar","A sturdy oak bar that seems to have seen its' fair share of bar fights",
  "man","A grisly old veteran barkeep he seems ready to handle anything",
  "sign","The sign reads \n"+
  "                 Dark brew ale       :  10 coins\n"+
  "                 Hair of the dog     :  20 coins\n"+
  "                 Swamp gas           : 150 coins\n"+
  "                 Vraaak blood        : 230 coins",
  "table","Sturdy wooden tables",
  "chairs","Stout oak chairs",
  "light","A warm light comes from the fireplace",
});

dest_dir = ({
  "/players/dusan/town/rooms/twn4.c","west",
});
}

init() {
    add_action("move","west");
    add_action("order","order");
    add_action("order","buy");
}


order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (str == "ale") {
	mess = "Aaahhhh refreshing";
	heal = 1;
        value = 10;
	strength = 3;
    }
    else if (str == "gas" || str == "swamp gas") {
	mess = "You feel lightheaded";
	heal = 10;
        value = 150;
        strength = 7;
    } else if (str == "blood" || str == "vraaak blood") {
	mess = "You feel a burning sensation run through you";
	heal = 25;
        value = 230;
        strength = 14;
    } else if (str == "hair" || str == "hair of the dog") {
	mess = "Hair of the dog that bit you";
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





