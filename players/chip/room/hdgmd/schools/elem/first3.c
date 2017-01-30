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
short_desc = ""+HIC+"A first grade classrom"+NORM+"";
long_desc =
"You've entered one of the six first grade classrooms. There are small bookshelves lined\n"+
"up against the east wall. Twenty small desks, each with its own chair, fill the space in\n"+
"the center of the room. Toward the west wall there is the teacher's desk and a very large\n"+
"pair of portable closets, and behind the desk on the wall is a large chalkboard, but only\n"+
"a couple posters are on the remainder of the wall space in the room.\n";
add_listen("mumbles", "You hear what seems to be mumbling of children coming from the classrooms");
add_listen("voices", "The sounds of teachers enlightening their students with knowledge can be heard");
items =
({
"bookshelves",
"They are lined with textbooks of all kinds for first grade teaching",
"textbooks",
"Some are science, some mathematics, some history, amongst others..",
"closets",
"They are closed and locked but it is known the teacher's jacket and teaching\n"+
"materials are stored in them",
"desks",
"There are 20 of these around the room, used for students to do their classwork on",
"chairs",
"There's one at each desk, obviously for students to utilize while they learn",
"chalkboard",
"There are only a few simple daily tasks written upon it. The rest is blank",
"posters",
"They're simple posters of animals and vehicles, most are photographic",
});
dest_dir =
({
"/players/chip/room/hdgmd/schools/elem/westhall3.c",     "leave",
});
}
