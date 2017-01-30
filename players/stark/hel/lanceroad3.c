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
"You stand in the middle of the freshly paved Lance Road.  It has been \n"+
"a main thuroufair for merchants since it's installation.  There is a \n"+
"path to north up a small hill.  Southward there is an old boarded-off \n"+
"church.\n";

items=({
"item1","Showing item 1",
"item2","This would be item 2"
});

dest_dir=({
"/players/stark/hel/path1", "north",
"/players/stark/hel/lanceroad2", "east"
});
}
