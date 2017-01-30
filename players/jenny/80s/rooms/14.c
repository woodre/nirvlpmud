inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
    if(arg) return;
    set_light(1);
     set_listen(BOLD+"You hear music coming from the east."+NORM);
     set_search(BOLD+"You notice a few potholes."+NORM);
long_desc=
"Welcome to the 80's zone, a hodgepodge of people and things from\n"+
"the 1980's.  This is a quiet 4 way intersection.  A blinking red\n"+
"light hangs overhead, while the concrete street beneath your feet\n"+
"has a few potholes.   People of power are rumored to be to the\n"+
"north, while people from entertainment and popular culture are\n"+
"said to be in all other directions.  There is a "+MAG+"sign"+NORM+" on the\n"+
"side of the road.\n";
short_desc=(RED+BOLD+"The 80's Zone"+NORM);
items = ({
"sign","This is a black metal pole which is sticking out of the ground.  It has\n"+
"a square shaped head made of polished stone.  Readable letters are\n"+
"engraved on it",
"potholes","There are a few potholes in this intersection.  They formed\n"+
"after years use, and few repairs",
"intersection","A quiet intersection of 4 roads.  There is a blinking red light\n"+
"above it",
"light","A blinking "+RED+"red "+NORM+"light which signals for cars in each direction to\n"+
             "stop",
"street","A grey concrete street which needs to be paved.  It has a few\n"+
              "potholes in the intersection",
});
dest_dir = ({
 "/players/jenny/80s/rooms/7","north",
 "/players/jenny/80s/rooms/19","south",
 "/players/jenny/80s/rooms/13","west",
 "/players/jenny/80s/rooms/15","east",
 "/players/jenny/areaentrance","leave",
});
}
init() {        
    ::init();  
add_action("sign","read");
}

sign(arg) { 
if(!arg) { return 0; }
if(arg == "sign" | arg == "the sign" | arg == "letters" | arg == "stone" | arg == "head") {

write(GRN+"**************************************************"+NORM+"\n"+
""+GRN+"*                                                *"+NORM+"\n"+
""+GRN+"* "+NORM+""+YEL+"       This area is dedicated to Usagi,"+NORM+""+GRN+"        *    "+NORM+"\n"+
""+GRN+"* "+NORM+""+YEL+"    who doesn't think the 80's were cool."+NORM+""+GRN+"      *"+NORM+"\n"+
""+GRN+"*                                                *"+NORM+"\n"+
""+GRN+"*              "+NORM+""+YEL+"    JENNY       "+NORM+""+GRN+"                  *"+NORM+"\n"+
""+GRN+"*                                                *"+NORM+"\n"+
""+GRN+"**************************************************"+NORM+"\n");

return 1; }
}
