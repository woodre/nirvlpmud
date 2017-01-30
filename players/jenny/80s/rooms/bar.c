inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int br;
int ck;
int co;
reset(arg) {
br = 8+random(4);
ck = 94+random(14);
co = 94+random(14);
    if(arg) return;
    set_light(1);
set_smell(BOLD+"The smell of beer is in the air."+NORM);
set_listen(BOLD+"The Detroit Tigers game is on TV."+NORM);
set_search(BOLD+"You notice pictures on the wall."+NORM);
long_desc=
"This is a small, dimly lit, sports bar.  The black tile floor is littered\n"+
"with peanut shells, and the walls are decorated with autographed pictures\n"+
"of local sports heros.  There are a few tables and chairs, along with\n"+
"about ten bar stools, which are pulled up to a long wooden bar.  Nineteen\n"+
"inch televisions are set up on shelves in each corner, and a menu\n"+
"is posted on the wall.\n";
short_desc=(RED+"A bar"+NORM);
items = ({
"menu","This menu is actually a small blackboard.  You could read it",
"walls","These walls are painted white and decorated with autographed pictures\n"+
              "of the local sports heros",
"floor","The floor is made up of black tiles.  It is littered with peanut shells",
"pictures","There are autographed pictures of Alan Trammell, Lou Whitaker. Jack\n"+
               "Morris, Lance Parrish, Kirk Gibson, Willy Hernandez, Darrell Evans,\n"+
                "Aurelio Lopez, Dan Petry, Sparky Anderson, Steve Yzerman, Petr\n"+
                "Klima, Bob Probert, Gerald Gallant, Jacques Demers, Billy Simms,\n"+
                "Eddie Murray, Isiah Thomas, Joe Dumars, Bill Laimbeer, Rick\n"+
                "Mahorn, Dennis Rodman, John Salley, Vinnie Johnson, Chuck\n"+
                 "Daly, George Perles, Bo Schembechler, Jud Heathcoat, Steve\n"+
                 "Fisher, and Tommy Hearns",
"bar","This is a long wooden bar.  It is well stocked with liquor",
"shells","Peanut shells that patrons have thrown on the floor",
"televisions","There is a 19 inch RCA television on a shelf in each corner of the room",
"shelves","There is a shelf, with a television sitting on it, in each corner of the room",
"tables","There are a few plain wooden tables for patrons to sit at",
"chairs","Plain wooden chairs pulled up to the tables",
"stools","There are ten padded stools next to the bar",
});
dest_dir = ({
 "/players/jenny/80s/rooms/15","exit",
});
}
init() {
  ::init();
add_action("heal","order");
add_action("menu","read");
}

heal(arg) {
if(!arg) { write("What do you want?\n"); return 1; }
if(arg != "beer" && arg != "peanuts" && arg != "dr pepper" && arg != "dr. pepper") {
write("That is not on the menu.\n"); return 1; }
if(arg == "beer") {
if(!TP->drink_alcohol(3)) { write("You're too drunk to serve.  Don't want you killing youself on the way home.\n");
return 1;}
write(HIY+"You guzzle down a tall frosty glass of beer."+NORM+"\n");
TP->heal_self(1);
TP->add_money(-br);
return 1; }
if(arg == "peanuts") {
if(!TP->eat_food(4)) { write("You can't eat another bite.\n");
return 1; }
write(BOLD+"You happily munch on a bowl of peanuts."+NORM+"\n");
TP->heal_self(11);
TP->add_money(-ck);

return 1;}
if(arg == "dr. pepper" || arg == "dr pepper") {
if(!TP->drink_soft(4)) { write("You can't drink another drop.\n");
return 1; }
write(BOLD+MAG+"I'm a pepper.  You're a pepper.  He's a pepper.  She's a pepper.\n"+
"Wouldn't you like to be a pepper too?"+NORM+"\n");
TP->heal_self(11);
TP->add_money(-co);
return 1; }}
menu() {
write(RED+
"            *********************************************\n"+
"            *                                           *\n"+
"            *               "+WHT+"You can order:"+RED+"              *\n"+
"            *                                           *\n"+
"            *    "+WHT+"Beer		"+br+" coins"+RED+"     		*\n"+
"            *                                           *\n"+
"            *    "+WHT+"Peanuts    	"+ck+" coins"+RED+"         	*\n"+
"            *                                           *\n"+
"            *    "+WHT+"Dr. Pepper 	"+co+" coins"+RED+"		*\n"+
"            *                                           *\n"+
"            *********************************************"+NORM+"\n");

return 1; }
