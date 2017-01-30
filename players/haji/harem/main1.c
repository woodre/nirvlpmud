/*
object newspaper, top_list;

*/
reset(arg) {
/*
    if (!top_list || !present(top_list)) {
	top_list = clone_object("obj/level_list");
	move_object(top_list, this_object());
    }
    if (!newspaper || !present(newspaper)) {
	newspaper = clone_object("obj/newspaper");
	move_object(newspaper, this_object());
    }
*/
    if (arg) return;
    set_light( 1);
}

short() {
    return "Entrance to Haji's harem";
}

init() {
    add_action("move", "west");
    add_action("order","order");
    add_action("order","buy");
}

move() {
    object ob;

    call_other(this_player(), "move_player",  "west" + "#" +"players/haji/harem/ent.c");
    return 1;
}

long() {
    write("You are in the Haji's harem.\n");
    write("You can order sex here.\n\n");
    write("     Handjob             : 100 coins\n");
    write("     Blowjob             : 300  coins\n");
    write("     69 (dude!!!!)       : 500 coins\n");
    write("     Screw               : 700 coins\n");
    write("     Doggie style        : 900 coins\n");
    write("\n");
    write("The only obvious exit is to " +  "west" + ".\n");
}

order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal,money;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (str == "handjob") {
/*
mess = "You feel the ale burn as it goes down your throat!!!";
	heal = 1;
	value = 15;
	strength = 2;
*/
    money=call_other(this_player(),"query_money");
      if(money<100) {
         write("You don't have enough coins for a handjob.\n");         return 1;
        }
      call_other(this_player(),"add_money",0-100);
    call_other(this_player(),"move_player","through the curtain to have a great time!" + "#" + "players/haji/harem/hand");
      return 1;
    }
    else if(str=="blowjob"||str=="blow") {
/*
	mess = "A tingling feeling goes through your body";
	heal = 5;
	value = 100;
	strength = 8;
*/
        money=call_other(this_player(),"query_money",0);
         if(money<300) {
            write("You don't have enough money for a blowjob.\n");
            return 1;
           }
         call_other(this_player(),"add_money",0-300);
         call_other(this_player(),"move_player","leaves through the curtain to have a GREAT time!" + "#" + "players/haji/harem/blow");
    return 1;
   }
    else if (str=="69") {
         money=call_other(this_player(),"query_money");
         if(money<500) {
           write("You don't have enough money for a 69.\n");
           return 1;
           }
          call_other(this_player(),"add_money",0-500);
          call_other(this_player(),"move_player","leaves through the curtain to have a GREAT time!" + "#" + "players/haji/harem/sixnine");
          return 1;
   /*
	mess = "A shock wave runs through your body";
	heal = 10;
	value = 300;
	strength = 12;
  */
 }
   else if(str=="screw"||str=="fuck") {
/*
	mess = "You feel somewhat invigorated";
	heal = 0;
	value = 20;
	strength = -2;   
*/
         money=call_other(this_player(),"query_money",0);

         if(money<700) {
           write("You don't have enough coins for a screw.\n");
           return 1;
           }
          call_other(this_player(),"add_money",0-700);
          call_other(this_player(),"move_player","leaves through the curtain to have a GREAT time!" + "#" + "players/haji/harem/screw");
          return 1;
}
    else if(str=="doggie style"||str=="doggie") {
              money=call_other(this_player(),"query_money",0);
               if(money<=800) {
                write("You can't do doggie style unless you have enough money,you don't!\n");
                return 1;
              }

            call_other(this_player(),"add_money",0-800);
            call_other(this_player(),"move_player","leaves through the curtain to have a GREAT time!" + "#" + "players/haji/harem/doggie");
            return 1;
    } else {
       write("The pimp says: What do you want?\n");
       return 1;
    }
    if (call_other(this_player(), "query_money", 0) < value) {
        write("That costs " + value + " gold coins, which you don't have.\n");
	return 1;
    }
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
	call_other(this_player(), "add_money", - value);
	return 1;
    }
    if (!call_other(this_player(), "drink_alcohol", strength)) {
	write("The pimp says: I think you've had enough.\n");
	say(call_other(this_player(), "query_name", 0) + " asks for a " +
		str + " but the pimp refuses.\n");

	return 1;
    }
    write("You pay " + value + " coins for a " + str + ".\n");
    say(call_other(this_player(), "query_name", 0) + " orders a " + str + ".\n");
    call_other(this_player(), "add_money", - value);
    call_other(this_player(), "heal_self", heal);
    write(mess + ".\n");
    return 1;
}
