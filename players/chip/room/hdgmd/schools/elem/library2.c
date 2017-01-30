/*
*      Function:
*      Change History:
*/
#include <ansi.h>
inherit "/room/room";
reset(arg)
{
::reset(arg);
if(arg) return;
set_light(1);
short_desc = ""+HIY+"The Library"+NORM+"";
long_desc =
"The library here is where all the students come to check out books and read during\n"+
"certain classes. There are many bookshelves, each containing hundreds of books of\n"+
"all kinds. Some tables are randomly placed around, each with 4 chairs placed at\n"+
"them. It is pretty silent here. Afterall, it is a library.\n";
add_listen("silence", "You hear absolutely nothing.");
items =
({
"bookshelves",
"They contain hundreds of books for the students to read and enjoy",
"books",
"Books of all sizes, shapes, and topics line the many bookshelves",
"tables",
"The tables each have a small stack of popular books in the center of them",
"chairs",
"There are four at each table, for students to sit on while they read quietly",
});
dest_dir =
({
"/players/chip/room/hdgmd/schools/elem/library1.c",     "east",
"/players/chip/room/hdgmd/schools/elem/library3.c",     "south",
});
}
