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
short_desc = "West Wing";
long_desc =
"This is the west wing on the first floor of the school. There are two doors here, one\n"+
"to the north, and one to the south, both leading into classrooms. There is a big banner\n"+
"hanging from the ceiling in the center of the hall. Mumbles can be heard coming from \n"+
"behind both doors, and a pair of teachers' voices can be heard over the mumbles. The \n"+
"hall continues east and west from here, and it looks like there's more classrooms in\n"+
"both directions.\n";
add_listen("mumbles", "You hear what seems to be mumbling of children coming from the classrooms");
add_listen("voices", "The sounds of teachers enlightening their students with knowledge can be heard");
items =
({
"doors",
"The doors are labelled as F3 and F4",
"banner",
"The banner reads "+HIB+"West wing - First Grade"+NORM+"",
"ceiling",
"There is a large banner hanging from it",
});
dest_dir =
({
"/players/chip/room/hdgmd/schools/elem/westhall4.c",     "west",
"/players/chip/room/hdgmd/schools/elem/westhall2.c",     "east",
"/players/chip/room/hdgmd/schools/elem/first3.c",     "north",
"/players/chip/room/hdgmd/schools/elem/first4.c",     "south",
});
}
