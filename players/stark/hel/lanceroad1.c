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
"You stand on the west edge of the freshly paved Lance Road.  It has \n"+
"been a main thuroufair for merchants since it's installation.  Parts \n"+
"of the road have been dug up and never repaired.  To the northwest is \n"+
"a dark alleyway.\n";

items=({
"item1","Showing item 1",
"item2","This would be item 2"
});

dest_dir=({
"/players/stark/hel/lanceroad2", "west",
"/players/stark/hel/southroad3", "east",
"/players/stark/hel/new_alley", "northwest"
});
}
