inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int zz;
int num;
realm() { return "NT"; }
reset(arg) {
num = random(10);
if(!present("al sobotka")) {
if(num < 4) {MOCO("/players/jenny/wings/mobs/staff/sobotka.c"),this_object()); }}
    if(arg) return;
    set_light(1);
     set_search(BOLD+"You notice the ceiling is damaged."+NORM);
     set_smell(BOLD+"This corridor has a musty smell."+NORM);
     set_listen(BOLD+"You hear some activity coming from the ice surface."+NORM);
long_desc=
"This narrow, musty corridor runs from the ice surface to\n"+      
"the player's facilities.  The white tile walls look very clean.\n"+
"The grey cement floor looks clean as well, despite years of\n"+
"use.  The ceiling tiles above you are noticeably damaged.\n"+
"As you get closer to the ice, you can see up into the stands.\n"+
"A red railing is all that separates this corridor from the\n"+
"seats above.  A zambonie machine sits near the gate\n"+
"to the ice surface.\n";
items = ({
"ceiling","The white ceiling tiles have been noticeably damaged.  The\n"+
              "Russian players did this while warming up for a game by\n"+
               "kicking a soccer ball around",
"stands","These are the red and white seats where fans sit during the game",
"seats","These are the red and white seats where fans sit during the game",
"gate","This is a large gate, which opens into the ice surface.  It is\n"+
             "used by the players to get to the locker rooms, and it is also\n"+
             "used to get the zambonie onto the ice.  You could enter the gate",
"railing","This red railing separates the corridor from the stands above",
"zambonie","The zambonie looks like a giant, funny looking tractor.\n"+
                     "It is a big metal machine which is driven around the\n"+
                    "ice to resurface it before games and between periods.\n"+
                    "Advertising is displayed on the sides",
"walls","The walls are made of white tile.  They look like they have been\n"+
              "washed recently.  It gives the corridor a very cold feel",
"floor","The floor is made of cement.  The grey color adds to the cold\n"+
             "feel of the corridor",
});

dest_dir = ({
"/players/jenny/wings/rooms/i2","east",
});
}
short() {
return BOLD+WHT+"A corridor"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("gate","enter");
}
gate(arg) {
if(!arg) {return 0;}
if(arg == "gate" | arg == "the gate") {
zz = random(2);
if(zz == 0) {
TP->move_player("through the gate#players/jenny/wings/rooms/ice1.c");
return 1; }
else {
TP->move_player("through the gate#players/jenny/wings/rooms/ice2.c");
return 1; }
}}
