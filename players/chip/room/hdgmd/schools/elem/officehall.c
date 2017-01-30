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
short_desc = "A Hallway in the Main Office Area";
long_desc =
"You've wandered into a simple hallway, where the main office area is to your south,\n"+
"and there are three doors, two to your west, and one to your east. All three doors \n"+
"are wide open and seem to lead to small offices, each looking to be set up similar \n"+
"to the other two. There are mild sounds of computers working coming from each one, \n"+
"and all three seem to be occupied.\n";
  
dest_dir =
({
"/players/chip/room/hdgmd/schools/elem/office.c",     "south",
"/players/chip/room/hdgmd/schools/elem/goffice1.c",     "door1",
"/players/chip/room/hdgmd/schools/elem/goffice2.c",     "door2",
"/players/chip/room/hdgmd/schools/elem/apoffice.c",     "door3",
});
}
