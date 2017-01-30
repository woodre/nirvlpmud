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
"This is the west wing on the first floor of the school. Looking down the hall you see\n"+
"several doors down each side of it. It is fairly quiet, other than a faint mumble of\n"+
"children's voices to the west and north. The walls here are bare other than a sign above\n"+
"the door on the north wall. Here you catch the faint smell of food and it makes you hungry.\n"+
"Back to the south is the main lobby, from which you came.\n";
add_listen("voices", "You hear what seems to be mumbling of children coming from the west and north");
add_smell("air", "There is a faint smell of food in the air. It makes you hungry");
items =
({
"doors",
"From here it looks as though the doors to the west most likely lead to classrooms",
"walls",
"They are bare other than a sign above the door on the north wall",
"sign",
"The sign reads "+HIG+"Cafeteria"+NORM+"",
"door",
"The door is open. There is a sign above it",
});
dest_dir =
({
"/players/chip/room/hdgmd/schools/elem/westhall2.c",     "west",
"/players/chip/room/hdgmd/schools/elem/lobby.c",     "south",
"/players/chip/room/hdgmd/schools/elem/cafeteria.c",     "door",
});
}
