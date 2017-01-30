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
short_desc = "A Temporary Room of Hateful Examples";
long_desc =
"This is Chip's favorite playroom where he tests random stuff, like new mobs,\n"+
"items, pieces of fun code, and whatever else his twisted brain can come up\n"+
"with. The walls are all plain white, and currently the entire room is just\n"+
"plain empty. Perhaps if you scream and cry, the walls might hear you.\n";
    move_object(clone_object("/players/eurale/Keep/NPC/hylar.c"), this_object());
    move_object(clone_object("/players/eurale/Keep/NPC/hylar.c"), this_object());
    move_object(clone_object("/players/eurale/Keep/NPC/hylar.c"), this_object());
    move_object(clone_object("/players/eurale/Keep/NPC/hylar.c"), this_object());
    move_object(clone_object("/players/eurale/Keep/NPC/hylar.c"), this_object());
    move_object(clone_object("/players/eurale/Keep/NPC/hylar.c"), this_object());
    move_object(clone_object("/players/eurale/Keep/NPC/hylar.c"), this_object());
    move_object(clone_object("/players/eurale/Keep/NPC/hylar.c"), this_object());
    move_object(clone_object("/players/eurale/Keep/NPC/hylar.c"), this_object());
    move_object(clone_object("/players/eurale/Keep/NPC/hylar.c"), this_object());
	items =
({
"walls",
"The walls are plain white, but seem to fluctuate a little bit, as\n"+
"if they are alive",
});
dest_dir =
({
"/players/chip/room/testrooms/testroom3.c",     "west",
"/players/chip/room/testrooms/testroom5.c",     "east",
});
}
