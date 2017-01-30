inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int ran;
int rann;
reset(arg) {
ran = random(3);
rann = random(3);
if(!present("molly ringwald"))  {
MOCO("/players/jenny/80s/mobs/molly.c"),this_object()); }
if(!present("hall") &&! present("sheedy") && !present("andrew"))  {
if(ran == 0) { MOCO("/players/jenny/80s/mobs/ahall.c"),this_object()); }
if(ran == 1) { MOCO("/players/jenny/80s/mobs/ally.c"),this_object()); }
if(ran == 2) { MOCO("/players/jenny/80s/mobs/andrew.c"),this_object()); }}
if(!present("emilio") &&! present("demi") && !present("judd"))  {
if(rann == 0) {MOCO("/players/jenny/80s/mobs/emilio.c"),this_object()); }
if(rann == 1) {MOCO("/players/jenny/80s/mobs/demi.c"),this_object()); }
if(rann == 2) {MOCO("/players/jenny/80s/mobs/judd.c"),this_object()); }}
    if(arg) return;
    set_light(1);
set_search(BOLD+"You notice a box next to the wall."+NORM);
set_smell(BOLD+"It smells like potpourri."+NORM);
long_desc=
"This is the living room of a home belonging to Molly Ringwald.\n"+
"The plush pink carpet feels soft as a cloud, and contrasts nicely\n"+
"with the white walls, which are decorated with modern art.  A big\n"+
"screen television sits along the far wall, right next to the stereo\n"+
"equipment.  The casual furniture consists of an overstuffed couch\n"+
"and a few bean bag chairs.\n";
short_desc=(HIC+"Molly Ringwald's House"+NORM);
items = ({
"carpet","The plush pink carpet is very soft.  It looks new as well",
"walls","The walls are painted white, and decorated with pictures\n"+
             "of modern art",
"art","Pictures of modern art, with many interesting shapes and bright colors",
"television","A big screen projection television.  It does not get a very\n"+
               "crisp picture",
"stereo","This stereo plays vinyl records, cassettes, and even those new fangled\n"+
               "CD's",
"couch","This overstuffed white couch looks very comfortable",
"chairs","These pink beanbag chairs look fun to sit in",
"box","This is a box for the board game 'twister'",
});
dest_dir = ({
 "/players/jenny/80s/rooms/23","leave",
});
}
