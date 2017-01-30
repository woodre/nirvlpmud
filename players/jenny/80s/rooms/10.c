inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
if(!present("a boy with spiked hair"))  {
MOCO("/players/jenny/80s/mobs/sboy.c"),this_object()); 
MOCO("/players/jenny/80s/mobs/sboy.c"),this_object()); }
if(!present("a boy with spiked hair 2") && present("a boy with spiked hair"))  {
MOCO("/players/jenny/80s/mobs/sboy.c"),this_object()); }
if(!present("girl"))  {
MOCO("/players/jenny/80s/mobs/bgirl.c"),this_object()); }
    if(arg) return;
    set_light(0);
set_search(BOLD+"You notice a narrow alley."+NORM);
long_desc=
"S&L Road stretches out towards the far end of town.  The street lights have\n"+
"been broken for a few days, which is a good indication that this is not one\n"+
"of the nicer parts of the city.  This street is a mix of residential and\n"+
"business.  There are modest homes, and seedy businesses on each side of\n"+
"the street.  The pavement of the street itself is full of cracks and potholes.\n"+
"Maintaining this road does not seem to be a priority.\n";
short_desc=(CYN+"S&L Road"+NORM);
items = ({
"lights","The street lights are broken.  It looks as if some kids have thrown rocks\n"+
              "at them.",
"road","The pavement has lots of cracks and potholes",
"alley","A dark narrow alley.  You could enter it and check it out",
"potholes","Holes in the street that have been formed through erosion and lack of repairs",
"cracks","Cracks which have formed in the pavement due to erosion",
"pavement","The pavement has lots of cracks and potholes",
"street","The pavement has lots of cracks and potholes",
"homes","Some modest one story homes are on this street.  Many of them could\n"+
               "use a new coat of paint",
"businesses","This road has many seedy businesses.  You notice a T.V. repair shop,\n"+
                      "liquor store, and a Kentucky Fried Chicken restaurant",
});
dest_dir = ({
 "/players/jenny/80s/rooms/11","east",
});
}
init() { 
    ::init(); 
add_action("alley","enter");
}
alley(arg) { 
if(!arg) { return 0; }
if(arg == "alley" | arg == "the alley")  {
TP->move_player("into the alley#players/jenny/80s/rooms/alley.c");
return 1; }
}
