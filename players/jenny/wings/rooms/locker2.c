inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
int cash, randomchance, money;
reset(arg) {
randomchance = random(9);
money = 1;
if(!present("yzerman"))  {
MOCO("/players/jenny/wings/mobs/players/yzerman.c"),TO); }
    if(arg) return;
    set_light(1);
     set_smell(BOLD+"A musty odor hangs in the air."+NORM);
long_desc=
"This is the locker room of the Detroit Red Wings.  It is a large room,\n"+      
"used by the players to change before and after games.  There are\n"+
"about thirty stalls along the outside edges of the room, with wooden\n"+
"benches in front of them.  A water cooler is in the northwest corner.\n"+
"The center of the room is open space, with only a large rug and a\n"+
"movable chalkboard\n";
items = ({
"stalls","Each stall is like a big, open locker.  There are hangers and shelves\n"+
              "for street clothes and personal belongings, as well as a large storage\n"+
              "bin at the bottom for equipment",
"hangers","Each stall has thick wooden hangers for a players street clothes",
"shelves","Each stall has 2 shelves, which players use to store personal belongings",
"bin","Each stall has a large, white storage bin for players to keep their\n"+
           "hockey equipment",
"benches","These are plain wooden benches with a light finish.  They run along\n"+
                 "the outside edges of the room, in front of the stalls",
"cooler","A refrigerated water cooler, with a large 5 gallon jug on top",
"jug","A clear plastic 5 gallon water jug",
"rug","This rug covers a large area in the center of the room.  It is red, with a\n"+
           "Detroit Red Wings logo in the center",
"logo","It is a red and white winged wheel.  The logo of the Detroit Red Wings",
"chalkboard","A two-sided black chalkboard, which sits on a wooden frame.\n"+
                       "It has small wheels, making it easy to move",
});
dest_dir = ({
 "/players/jenny/wings/rooms/locker4","south",
 "/players/jenny/wings/rooms/locker1","east",
});
}
short() {
return BOLD+RED+"Red Wings Locker Room"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("coins","search");
}
coins(arg)  {
int cash;
cash = 90+random(50);
if(money == 1 && randomchance == 1 && LUCSTAT > random(30)) {
write(BOLD+"You find "+cash+" coins on the floor."+NORM+"\n");
TP->add_money(cash);
money = 2;
return 1;  }}
