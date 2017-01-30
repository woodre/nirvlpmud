inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
    if(arg) return;
    set_light(1);
set_listen(BOLD+"You hear lots of different music all blurred together."+NORM);
set_smell(BOLD+"The smell of grilled ribs is making your mouth water."+NORM);
set_search(BOLD+"You notice a staircase leading down.  You could descend the stairs"+NORM);
long_desc=
"This is a lively city street.  The pavement looks pretty old.  There are\n"+
"a few potholes which could stand to be fixed.  The sidewalks on each\n"+
"side of the street are bustling with pedestrian activity.  This part of\n"+
"town is clearly the place to be.  An outdoor restaurant is on one side\n"+
"of the street, while a liquor store is on the other.\n";
short_desc=(WHT+"Hair-spray drive"+NORM);
items = ({
"staircase","This is a narrow staircase leading down to a bar",
"street","A lively city street.  The pavement looks pretty worn",
"potholes","Holes worn into the pavement after years of errosion",
"pavement","Grey concrete pavement.  It has a few potholes",
"sidewalks","There are cement sidewalks on each side of the street.  They\n"+
            "are bustling with pedestrian activity",
"sidewalk","There are cement sidewalks on each side of the street.  They\n"+
            "are bustling with pedestrian activity",
"pedestrians","There are lots of pedestrians.  Some are just standing around,\n"+
                     "others are coming and going.  Everyone seems to be having a\n"+
                     "good time though",
"restaurant","This is a nice looking outdoor restaurant.  There are about 15 round\n"+
                    "tables.  A huge outdoor grill is used to cook the food",
"store","A brick liquor store.  It seems to be doing very good business",
"grill","This huge stone grill is beautiful.  It takes a lot of charcoal to\n"+
           "keep this thing burning all day",
});
dest_dir = ({
 "/players/jenny/80s/rooms/14","west",
 "/players/jenny/80s/rooms/16","east",
});
}
init() { 
    ::init(); 
add_action("stairs","descend");
}
stairs(arg) { 
if(!arg) { return 0; }
if(arg == "stairs" | arg == "the stairs")  {
TP->move_player("down the stairs#players/jenny/80s/rooms/bar.c");
return 1; }
}
