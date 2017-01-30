inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
reset(arg){


if(arg) return;
    set_light(1);
    add_listen("You hear nothing of interest.\n");
    add_smell("You smell nothing of interest.");
    short_desc=HIK+"Lance Road"+NORM;
    long_desc=
/*
 1234567891123456789212345678931234567894123456789512345678961234567897*/
"You stand on the east edge of the freshly paved Lance Road.  It has \n"+
"been a main thuroufair for merchants since it's installation.  There \n"+
"are not many shops on this stretch of the road.  There is a dirt path \n"+
"to the east.\n";

items=({
"item1","Showing item 1",
"item2","This would be item 2"
});

dest_dir=({
"/players/stark/hel/farmroad1", "east",
"/players/stark/hel/southroad3", "west"
});
}
