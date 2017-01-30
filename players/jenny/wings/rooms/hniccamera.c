inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int money;
int num;
realm() { return "NT"; }
reset(arg) {
num = random(11);
if(!present("cameraman")) {
if(num > 2) {MOCO("/players/jenny/wings/mobs/other/cameraman.c"),this_object()); }}
money = random(3);
    if(arg) return;
    set_light(1);
     set_listen(BOLD+"You can hear some activity way down on the ice surface."+NORM);
long_desc=
"This is a very small booth, which is big enough to fit only a\n"+      
"few people.  It is used for a television camera.  The walls are\n"+
"a plain white color, and the thin red carpet has lots of stains\n"+
"on it.  A television camera, and some other electronic\n"+
"equipment, sits in the middle of the booth.  A window\n"+
"provides a good view of the ice surface.\n";
items = ({
"carpet","This is cheap thin red carpet which is very worn.  It has many dark\n"+
               "stains from spilled food",
"stains","Many dark stains which are splattered on the carpet",
"window","This window provides a good view of the ice surface.  It has\n"+
                  "no glass",
"camera","This is a television camera, which is used for broadcasting the\n"+
               "hockey games.  It is a big black piece of equipment that looks\n"+
               "very complicated to operate",
"equipment","A headset, which is used for communicating with the broadcast truck",
"walls","The white walls are a little bit dirty",
"ice surface","The ice surface is set up for hockey.  There are nets at each end of\n"+
                 "the rink, and a few players out there practicing",
});

dest_dir = ({
"/players/jenny/wings/rooms/2h6","west",
});
}
short() {
return BOLD+WHT+"A camera booth"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("coins","search");
}
coins(arg)  {
int cash;
cash = 15+random(40);
if(money == 1) {
write(BOLD+"You find "+cash+" coins."+NORM+"\n");
TP->add_money(cash);
money = 2;
return 1;  }
}
