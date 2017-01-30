inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
    if(arg) return;
    set_light(1);
     set_listen(""+RED+"You hear upbeat music."+NORM+"\n");
short_desc=(""+MAG+"The Jiggly Room"+NORM+"");
long_desc=
     "Welcome to the Jiggly Room.  This is the nudie bar where Al\n"+
    "and his NO'MAM friends hang out.  There are beautiful naked\n"+
    "women all around you.  There is a surly looking bartender\n"+
   "whom you can order drinks from.  Type "+YEL+"list"+NORM+" for a menu.\n";

items = ({
"bartender","You wonder how he could be this unhappy on D-cup night",
"women","Dancers who work at the nudie bar.  Wow!  Nice hooters",
});

dest_dir = ({
"/players/jenny/bundy/rooms/3h","south",
"/players/jenny/bundy/rooms/3f","out",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();

  add_action("order","order");
  add_action("order","buy");
 add_action("list","list");
}
list() {
write(
""+BOLD+"\n"+
"()()()()()()()()()()()()()()()()()()()()\n"+
""+CYN+"              D R I N K S"+NORM+"\n"+                  
""+BOLD+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
"beer           10\n"+
"zima           150\n"+
"scotch         150\n"+
"()()()()()()()()()()()()()()()()()()()()"+NORM+"\n");

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
    if (str == "beer") {
        mess = "A few of these will help you forget your troubles";
        heal = 1;
        value = 10;
        strength = 3;
    }
    else if (str == "zima") {
        mess = "You are relieved as noone makes fun of you for drinking zima";
        heal = 10;
        value = 150;
        strength = 8;
    }
    else if (str == "scotch") {
        mess = "Ah!  That warms the stomach";
        heal = 20;
        value = 150;
        strength = 15;
    } else {
       write("The bartender growls: We don't serve that!\n");
       return 1;
    }
    if (call_other(this_player(), "query_money", 0) < value) {
        write("That costs " + value + " coins.  Come back when you have money.\n");
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
        write("The bartender says: I think you've had enough buddy\n");
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
