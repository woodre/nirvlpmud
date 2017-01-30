inherit "/room/room";
#include <ansi.h>
#include "../../defs.h"
object ob;

reset(arg)
{
::reset(arg);

if(!present("shinshi_rogue_talker")) {
        move_object(clone_object(HALLNPC+"talker.c"),this_object());
}

if(arg) return;
	set_light(1);
	short_desc = HIR+"The Pub"+NORM;
	long_desc =
	"This is an older pub that has multiple sets of wooden\n"+
	"chairs and tables. A large counter is attached to the\n"+
	"wall on the far side of the bar with all different types\n"+
	"of liquor. There is a large sign behind the bar.\n";

items =

({
	"chairs",
	"Very worn wooden chairs",
	"tables",
	"Somewhat worn wooden tables",
	"counter",
	"It looks as if the counter has just been replaced",
	"sign",
	"A large sign. Perhaps you should read it?",
	"bar",
	"A simple bar used for serving alcohol",
	"granite",
	"A thick piece of granite forms the counter",
	"wall",
	"The walls have been made of granite",
	});

dest_dir =
({
	HALLRMS+"entrance.c",	"east",
	});
}

realm(){ return "NT"; }
query_no_fight(){ return 1; }

init(){
	::init();
	
	add_action("read", "read");
	add_action("order", "order");
}

read(str)
{
	if(!str)
	{
		write("What would you like to read?\n");
		return 1;
	}
	
	if(str != "sign")
	{
		write("That isn't here to read!\n");
		return 1;
	}
	
	if(str == "sign")
	{
		write("\n");
		write(HIR);
		write("(XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX)\n");
		write("(X			(X)ROGUE(X)\n");
		write("(X\n");
		write("(X	You may 'order' one of the following:\n");
		write("(X\n");
		write("(X	1. Devil's Spring Vodka\n");
		write("(X		Cost: 50\n");
		write("(X\n");
		write("(X	2. Absinthe\n");
		write("(X		Cost: 100\n");
		write("(X\n");
		write("(X	3. Bacardi 151\n");
		write("(X		Cost: 150\n");
		write("(X\n");
		write("(X	4. Sierra Silver Tequila\n");
		write("(X		Cost: 200\n");
		write("(X\n");
		write("(X	5. Everclear\n");
		write("(X		Cost: 250\n");
		write("(X\n");
		write("(X\n");
		write("(XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX)\n");
		write(NORM);
		write("\n");
		return 1;
	}
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
    if (str == "1") {
        mess = "You take your shot of Devil's Spring Vodka";
        heal = 15;
        value = 50;
        strength = 3;
    }
    else if (str == "2"){
        mess = "You take your shot of Absinthe";
        heal = 20;
        value = 100;
        strength = 7;
    } else if (str == "3") {
        mess = "You take your shot of Bacardi 151";
        heal = 25;
        value = 150;
        strength = 14;
    } else if (str == "4") {
        mess = "You take your shot of Sierra Silver Tequila";
        heal = 30;
      	value = 200;
        strength = 17;
    } else if (str == "5") {
	    mess = "You take your shot of Everclear";
	    heal = 35;
	    value = 250;
	    strength = 20;
   	} else {
       write("What do you want?\n");
       return 1;
    }
    if (call_other(this_player(), "query_money", 0) < value) {
        write("That costs " + value + " gold coins, which you don't have.\n");
        return 1;
    }
    cost = value;
    if (strength > (call_other(this_player(), "query_level") + 10)) {
        if (strength > (call_other(this_player(), "query_level") + 15)) {
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
        write("There's no way you're drinking that much.\n");
        say(call_other(this_player(), "query_name", 0) + " asks for a " +
                str + " but is turned down.\n");

        return 1;
    }
    write("You pay " + cost + " coins for a " + str + ".\n");
    say(call_other(this_player(), "query_name", 0) + " orders a " + str + ".\n");
    call_other(this_player(), "add_money", - cost);
    call_other(this_player(), "heal_self", heal);
    write("You are served your drink.\n");
    write(mess + ".\n");
    return 1;
}