inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
#include "/players/jenny/dukes/general.h"
    if(arg) return;
    set_light(1);
short_desc=(BOLD+"Old Ridge Road"+NORM);
long_desc=
"You are on a small dirt road, which winds through northern\n"+
"Hazzard County.  There are lots of oak, cottonwood, and\n"+
"willow trees to the west.  The Duke farm is to the east.\n"+
"Members of the Old Time Ridgerunner Association used\n"+
 "to use back roads like this to run moonshine.\n";
items = ({
"trees","These here trees have been in Hazzard County for 100 years",
"road","An old dirt road",
"farm","Bo, Luke, Daisy, and Jesse Duke live on this farm",
});
dest_dir = ({
 "/players/jenny/dukes/rooms/farm1","east",
 "/players/jenny/dukes/rooms/dr1","southwest",
});
}
