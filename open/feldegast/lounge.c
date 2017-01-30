#include "/players/feldegast/defines.h"
inherit ROOM;
reset(arg) {
    if(!present("list"))
      move_object(clone_object("obj/level_list"),this_object());
    if(!present("board")) {
      object board;
      board=clone_object("/players/feldegast/std/board");
      board->set_file("players/feldegast/arena/rooms/board");
      move_object(board,this_object());
    }
    if(arg) return;
    short_desc="The Coliseum Lounge";
    long_desc=
"  This is a tiny closet of a bar, serving as a place to relax for\n"+
"the coliseum's gladiators.  Small circular tables are spread at\n"+
"even intervals throughout the room while ubiquitous serving girls\n"+
"glide around the room with their trays held high above their heads.\n"+
"A chalkboard sign over the bar lists the drinks and their prices.\n"+
"On the west wall is a bulletin board for announcements, comments,\n"+
"and general bragging.  A rounded archway leads south.\n";
    set_light( 1);
  items=({
    "sign","It is a chalkboard sign with a list of drinks",
  });
  dest_dir=({
    "/players/feldegast/arena/rooms/crtyard","south"
  });
}

init() {
     ::init();
  add_action("order","order");
  add_action("order","buy");
    add_action("read","read");
}

move() {
    this_player()->move_player("south#/players/feldegast/arena/rooms/crtyard");
    return 1;
}

read(str) {
  notify_fail("Read what?\n");
  if(!str) return 0;
  if(str!="sign") return 0;
    write("A large sign here says:\n");
    write("     Cappuccino          :  60 coins\n"+
          "     Gin and tonic       :  50 coins\n"+
          "     Peach Schnappes     : 140 coins\n"+
          "     Screwdriver         : 240 coins\n"+
          "     Bloody Mary         : 300 coins\n"+
          "     Champagne Punch     : 460 coins\n"+
          "     Vodka Martini       : 480 coins\n"+
          "     Mai-tai             : 500 coins\n");
  return 1;
}

order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (str == "cappuccino") {
	mess = "Your senses feel heightened.  You are now ready to face the world";
	heal = 0;
        value = 60;
	strength = -3;
    }
    else if (str == "gin" || str == "tonic") {
	mess = "A tingling feeling goes through your body";
	heal = 5;
        value = 50;
        strength = 14;
    } else if (str == "schnappes" || str == "peach") {
	mess = "You poor the smooth liquid sugar down your throat";
	heal = 10;
        value = 140;
        strength = 10;
    } else if (str == "screwdriver") {
	mess = "Your poor the acidic mixture down your throat";
	heal = 20;
	value = 240;
	strength = 12;
    } else if (str == "mary"||str=="bloody") {
	mess = "You raise your glass in a toast and then poor it down the hatch";
	heal = 15;
	value = 300;
	strength = 6;
    } else if (str == "champagne"|| str=="punch") {
	mess = "You drink your punch and feel all bubbly inside";
	heal = 30;
	value = 450;
	strength = 9;
    } else if (str == "vodka"||str=="martini") {
	mess = "You think to yourself: Shaken, not stirred";
	heal = 40;
	value = 480;
	strength = 12;
    } else if (str == "mai-tai"||str=="tai"||str=="mai") {
	mess = "You feel like you've been taken to a warm tropical paradise.\nThen you look around and finish your drink";
	heal = 25;
	value = 500;
	strength = 6;


    } else {
       write("The pretty waitress asks: What can I get you?\n");
       return 1;
    }
    if (call_other(this_player(), "query_money", 0) < value) {
        write("That costs " + value + " gold coins, which you don't have.\n");
	return 1;
    }
    cost = value;
    if (!call_other(this_player(), "drink_alcohol", strength)) {
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
query_no_fight() {
  return 1;
}
