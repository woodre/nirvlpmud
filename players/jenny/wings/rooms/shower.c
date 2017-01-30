inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("larry murphy"))  {
if(random(10) > 3) {
MOCO("/players/jenny/wings/mobs/players/murphy.c"),TO); }}
    if(arg) return;
    set_light(1);
     set_smell(BOLD+"You take in a breath of the hot steamy air."+NORM);
     set_listen(BOLD+"Several of the showers are running."+NORM);
long_desc=
"This is the showering area of the Detroit Red Wings locker room.\n"+      
"The sauna and whirlpool are off the east, and the toilets are west\n"+
"of here.  Deeper in to the south are the showers.  The walls are made\n"+
"up of a cream colored tile.  There are 15 shower nozzles spaced\n"+
"around the outer edges of the room.  Knobs and soap dishes are\n"+
"positioned under each shower.  The floor is made up of tiny\n"+
"rectangular white tiles, with a drain in the middle of the room.\n";
items = ({
"drain","A small circular grate in the middle of the floor which allows excess\n"+
              "water to drain away",
"walls","The walls are made of large cream colored tiles.  They are wet",
"soap dishes","Small cream colored ceramic soap dishes are attached\n"+
           "to the wall under each shower",
"tile","The walls are made of large cream colored tile, while the floor is\n"+
           "made up of smaller white tiles",
"floor","The wet floor is made up of small white tiles",
"nozzles","Shiny metal shower nozzles sticking out of the wall about seven feet\n"+
                 "above the floor",
"showers","Shiny metal shower nozzles sticking out of the wall about seven feet\n"+
                 "above the floor",
"knobs","A small glass knob is placed under each shower for turning it on and\n"+
               "controlling water temperature.  You could turn the knob and take\n"+
               "a shower",
"dishes","Small cream colored ceramic soap dishes are attached\n"+
"to the wall under each shower",
});
dest_dir = ({
 "/players/jenny/wings/rooms/locker3","north",
 "/players/jenny/wings/rooms/toilets","west",
 "/players/jenny/wings/rooms/whp","east",
});
}
short() {
return BOLD+RED+"Red Wings Locker Room"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("knob","turn");
}
knob(arg) { 
if(!arg) { return 0; }
if(arg == "knob" | arg == "the knob")  {
write("You turn on the water and take a nice hot shower.\n"+
           "The whole room fills up with steam.\n");
return 1; }}
