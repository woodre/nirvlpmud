/*  prices for beer, pizza, and coke at about 94 percent of heal cost, since they are not portable */
inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int br, pz, ck;
realm() { return "NT"; }
reset(arg) {
br = 150, pz = 150, ck = 150;
if(!present("fan"))  {
if(!random(4)) {
MOCO("/players/jenny/wings/mobs/other/mfan.c"),TO); 
MOCO("/players/jenny/wings/mobs/other/ffan.c"),TO);}}
    if(arg) return;
    set_light(1);
     set_listen(BOLD+"You can hear some activity down on the ice surface."+NORM+"\n");
     set_smell(BOLD+"You can smell food from the concession stand."+NORM+"\n");
long_desc=
"You are standing in a concourse which wraps around the Joe\n"+      
"Louis Arena ice surface.  Before games, and between periods\n"+
"it is absolutely packed with fans, but it is relatively empty\n"+
"now.  Looking around the concourse, you notice an almost\n"+
"endless amount of concession stands.  The one directly in\n"+
"front of you is open.  The doors to the east lead into the\n"+
"stands.\n";

items = ({
"concession stand","You see many concession stands, which sell pizza, beer, coke, etc.\n"+
                                 "The one directly in front of you is open.  Type "+MAG+"list"+NORM+" to see what\n"+
"you can buy",
"concourse","This is a walkway which winds around Joe Louis Arena.  It exits\n"+
                    "into the stands.  Many concession stands, as well as souvenir shops\n"+
                    "are located within the concourse",
"ice surface","You can get a more clear view of this from the stands",
"concession stands","You see many concession stands, which sell pizza, beer, coke, etc.\n"+
                                 "The one directly in front of you is open.  Type "+MAG+"list"+NORM+" to see what\n"+
"you can buy",
"stands","You see many concession stands, which sell pizza, beer, coke, etc.\n"+
                                 "The one directly in front of you is open.  Type "+MAG+"list"+NORM+" to see what\n"+
"you can buy",
"doors","These doors lead into the stands.  They are wide open",
});

dest_dir = ({
"/players/jenny/wings/rooms/stands1c7","east",
 "/players/jenny/wings/rooms/c8","north",
"/players/jenny/wings/rooms/c6","south",
});
}
short() {
return BOLD+RED+"Joe Louis Arena concourse"+NORM; }
init() { 
    ::init(); 
     add_action("menu","list");
     add_action("heal","order");
     add_action("heal","buy");
   this_player()->set_fight_area();
}
menu() {
write(RED+
"            *********************************************\n"+
"            *       					*\n"+
"            *               "+WHT+"You can order:"+RED+"		*\n"+
"            *                       			*\n"+
"            *    "+WHT+"Beer           "+br+" coins"+RED+"		*\n"+
"            *                    			*\n"+
"            *    "+WHT+"Pizza	        "+pz+" coins"+RED+"		*\n"+
"            *                   			*\n"+
"            *    "+WHT+"Coke		"+ck+" coins"+RED+"		*\n"+
"            *              				*\n"+
"            *********************************************"+NORM+"\n");
return 1; }


heal(arg) {
if(!arg) { write("What do you want?\n"); return 1; }
if(arg != "beer" && arg != "coke" && arg != "pizza") {
write("That is not on the menu.\n"); return 1; }
if(arg == "beer") {
if(!TP->drink_alcohol(8)) { write("You're too drunk to serve.\n");
return 1;}
write("You drink a tall paper cup full of "+RED+"Budweiser."+NORM+"\n");
TP->heal_self(20);
TP->add_money(-br);
return 1; }
if(arg == "pizza") {
if(!TP->eat_food(8)) { write("You can't eat another bite.\n");
return 1; }
write("You munch on a slice of "+RED+"Little Caesars"+NORM+" pizza.\n");
TP->heal_self(20);
TP->add_money(-pz);
return 1;}
if(arg == "coke") {
if(!TP->drink_soft(8)) { write("You can't drink another drop.\n");
return 1; }
write("You drink a tall paper cup full of "+RED+"Coca-cola."+NORM+"\n");
TP->heal_self(20);
TP->add_money(-ck);
return 1; }}
