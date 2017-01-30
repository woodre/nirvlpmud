inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int whirl;
realm() { return "NT"; }
reset(arg) {
whirl = 1;
    if(arg) return;
    set_light(1);
     set_search(BOLD+"You notice a button above the bench."+NORM);
     set_listen(BOLD+"You can hear the showers running close by."+NORM);
     set_smell(BOLD+"There is a slight chlorine smell in the air"+NORM);
long_desc=
"The first thing you notice is a large whirlpool, which is built right\n"+      
"into the floor.  The walls are made of red and white tile, and a towel\n"+
"rack is on the east wall.  A wooden bench, with a large button over it,\n"+
"sits along the south wall.  About ten feet to the north is a wooden\n"+
"door with a small sign on it.\n";
items = ({
"whirlpool","A large stainless steel whirlpool, which is built into the floor.\n"+
                    "It has a metal railing and steps leading down into it.  It might\n"+ 
                    "be very relaxing to step into",
"railing","A metal hand railing, which leads down into the whirlpool",
"steps","Two steps allow you to ease your way into the whirlpool",
"floor","The wet floor is made up of small white tiles",
"walls","The walls are made up of large red and white tiles, which are\n"+
               "alternating to form a checkered pattern",
"rack","A shiny metal bar on the wall that is used for hanging towels",
"bench","A plain wooden bench with a dark finish",
"tile","The walls are made of large red and white tile, while the floor is\n"+
           "made up of smaller white tiles",
"door","A thick wooden door for you to enter.  There is a sign on it",
"sign","A wooden sign with the word SAUNA burned into it",
"button","A shiny metal button that starts the whirlpool when pressed",
});
dest_dir = ({
 "/players/jenny/wings/rooms/shower","west",
});
}
short() {
return BOLD+RED+"Red Wings Locker Room"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("pool","press");
add_action("pool","push");
add_action("door","enter");
add_action("whirlpool","step");
add_action("whirlpool","ease");
}
pool(arg) { 
if(!arg) { return 0; }
if(arg == "button" | arg == "the button")  {
if(whirl > 1) {write("The whirlpool is already turned on.\n");  return 1;}
write("You press the button and the whirlpool jets turn on.\n");
say(TPN+" presses the button.  The whirlpool jets turn on.\n");
call_other("/players/jenny/wings/rooms/whirlpool.c","buttonpushed");
whirl = 2;
return 1;}}
door(arg) {
if(!arg) { return 0; }
if(arg == "door" | arg == "the door" | arg == "sauna" | arg == "the sauna") {
write("You walk into the sauna\n");
TP->move_player("into the sauna#players/jenny/wings/rooms/sauna.c");
return 1;}}
whirlpool(arg) {
if(!arg) { return 0; }
if(arg == "whirlpool" | arg == "the whirlpool" | arg == "into whirlpool" | arg == "into the whirlpool" | arg == "pool" | arg == "into the pool" | arg == "into pool") {
if(whirl < 2) {write("You should turn the whirlpool on first.\n"); return 1;}
write("You step into the whirlpool.\n");
TP->move_player("into the whirlpool#players/jenny/wings/rooms/whirlpool.c");
return 1;}}
resetit() {
whirl = 1;
return 1;}
