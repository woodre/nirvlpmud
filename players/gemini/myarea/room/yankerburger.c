/*
 *      File:                   yankerburger.c
 *      Function:               
 *      Author(s):              Gemini@Nirvana
 *      Copyright:              Copyright (c) 2004 Gemini
 *                                      All Rights Reserved.
 *      Source:                 05/24/2004
 *      Notes:                  
 *      Change History:
 */

inherit "/players/vertebraker/closed/std/room";

reset(arg) {
   if(arg) return;
   set_short("Yanker Burger");
   set_long(
"     Welcome to Yanker Burger... May I take your order A counter?\n"+
"is in front of you with a unattended cash register. Over to your\n"+
"right is the seating area, but there are no free seats. Above you\n"+
"is a menu with prices. It is rumoured that this place is about to\n"+
"close, there might be some left overs in the backroom.\n"
           );
   set_light(1);
   add_item("counter","The counter is long and smooth, with cash registers, straw\n"+
            "and napkin dispensers");
   add_item("dispensers","They are full with straws and napkins");
   add_item("straws","The straws are for people who buy drinks.\n"+
                     "They are white with red stripes");
   add_item("stripes","A simple red stripe on the straws, they all look the same");
   add_item("napkins","The napkins are bleached white, and neatly placed\n"+
                      "in the napkin dispenser");
   add_item("cash register","The register is unattended, and full of money\n"+
            "Do not even think about becoming a thief!");
   add_item("register","The only register you see is a cash register");
   add_item("seating area","There are no open seats, You will have to wait");
   add_item("seats","You see a seating area");
   add_item("menu","This is a menu, you might be able to read it");
   add_exit("/players/gemini/myarea/room/main","east");
   add_smell("main","You smell fast food");
   
if(!present("ed")) move_object(clone_object
("/players/gemini/myarea/mon/specialed"), this_object());
}
init() { 
    ::init();
    add_action("order","order");
    add_action("read","read");
       }
read(str) {
      if (!str) { 
         write("Read what?\n");
          return 1; }
      if (str == "menu") {
         write("You can 'order' from the selections below.\n"+
            "===========================================\n"+
            "|     Budweiser beer      :  10 coins     |\n"+
            "|     Can of Pepsi        :  20 coins     |\n"+
            "|     Hotdog              : 150 coins     |\n"+
            "|     Cheeseburger        : 230 coins     |\n"+
            "===========================================\n");
       say(this_player()->query_name()+" reads the menu.\n");
       return 1;
}
}
order(str){
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (str == "beer" || str == "budweiser") {
	mess = "That really hit the spot";
	heal = 1;
        value = 10;
	strength = 3;
    }
    else if (str == "dog" || str == "hotdog") {
     mess = "Sorry, the grill is not on right now";
/*
	mess = "You gobble up the hotdog with delight";
	heal = 10;
        value = 150;
        strength = 7;
*/
    } else if (str == "burger" || str == "cheeseburger") {
	/* mess = "You shove the yummy cheeseburger into your piehole"; */
      mess = "Sorry, the grill is not on right now";
/*
	heal = 25;
      value = 230;
      strength = 14;
*/
    } else if (str == "pepsi" || str == "can of pepsi") {
	mess = "A caffeine shockwave runs through your body!";
	heal = 0;
	value = 20;
	strength = -2;
    } else {
       write("What do you want to order?\n");
       return 1;
    }
    if (call_other(this_player(), "query_money", 0) < value) {
        write("That costs " + value + " gold coins, which you can't afford.\n");
	return 1;
    }
    cost = value;
    if (strength > (call_other(this_player(), "query_level") + 2)) {
	if (strength > (call_other(this_player(), "query_level") + 5)) {
	    say(call_other(this_player(), "query_name", 0) + " orders a " +
		str + ", and immediately throws it up.\n");
	    write("You consience tells you ordering a " + str + ", is a bad idea right now.\n");
	} else {
	    say(call_other(this_player(), "query_name", 0) + " orders a " +
		str + ", and spews it all over you!\n");
	    write("Your consience tells you that ordering a " + str + ", is a bad idea right now!\n");
	}
	call_other(this_player(), "add_money", - cost);
	return 1;
    }
    if (!call_other(this_player(), "drink_alcohol", strength)) {
	write("Slow down, If you drink too much you're gona get sick.\n");
      write("                      Come back in a little while.\n");
	say(call_other(this_player(), "query_name", 0) + " asks for a " +
		str + " but the countergirl refuses.\n");
	return 1;
    }
    write("You pay " + cost + " coins for a " + str + ".\n");
    say(call_other(this_player(), "query_name", 0) + " orders a " + str + ".\n");
    call_other(this_player(), "add_money", - cost);
    call_other(this_player(), "heal_self", heal);
    write(mess + ".\n");
    return 1;
}
