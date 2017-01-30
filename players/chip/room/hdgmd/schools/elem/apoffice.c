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

short_desc = "Assistant Principal's Office";

long_desc =
"Here is where the assistant principal sits bored all day with nothing to do. There\n"+
"is only a desk with a few magazines and a computer on it, and a coat rack in the \n"+
"corner with a single coat hung on it. The walls are plain except for a lonely poster\n"+
"on the far wall, and a very small bulletin board next to the desk.\n";

items =
({
"desk",
"The desk is empty except for a couple National Geographic magazines and an old computer",
"magazines",
"Several old copies of National Geographic magazine",
"computer",
"An old desktop computer which probably contains students' confidential files",
"poster",
"The poster is fairly plain except for the large red letters which say '"+HIR+"Lonely Much?"+NORM+"'",
"board",
"The bulletin board is completely empty",
"rack",
"The coat rack has but a single coat hung upon it, a fancy canvas duster",
"coat",
"A fancy canvas duster hangs on the coat rack",
"walls",
"They are bare with the exception of the bulletin board and poster",
});


dest_dir =
({
"/players/chip/room/hdgmd/schools/elem/officehall.c",     "out",
});

}
