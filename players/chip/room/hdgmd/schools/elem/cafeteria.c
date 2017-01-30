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
short_desc = ""+HIW+"Cafeteria"+NORM+"";
long_desc =
"You have entered the cafeteria of the school. The smells in the air here are pretty\n"+
"good. You see many lunch tables, each surrounded by many, many chairs. Along the east\n"+
"side of the room there are several service bars, and a door. The west wall is lined\n"+
"completely with windows, and the rest of the available wall space is taken up by many\n"+
"posters with funny sayings, and bulletin boards with drawing on them, created by students.\n";
add_smell("air", "The smell of food is in the air");
items =
({
"tables",
"Each of the tables is surrounded completely by small chairs, and still has\n"+
"some stains and remnants of food and spilled milk on them",
"door",
"There is a sign on the door. It is unlocked and open",
"sign",
"The sign reads "+HIY+"Employees ONLY!"+NORM+"",
"windows",
"As you look out the windows you can see the full view of the school's playground",
"posters",
"Many of them have funny sayings on them, or quips made up by the teachers and staff",
"boards",
"These bulletin boards contain drawings that were made by the students",
"bars",
"These service bars are your basic buffet lines, operated by the beloved lunch ladies",
"drawings",
"Several sketches and paintings created by some of the students here",
});
dest_dir =
({
"/players/chip/room/hdgmd/schools/elem/westhall1.c",     "exit",
"/players/chip/room/hdgmd/schools/elem/cafkitchen.c",     "door",
});
}
