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
short_desc = "Main Office of HdG Elementary";
long_desc =
"Here is the main office of Havre de Grace Elementary. There is a receptionist desk\n"+
"here, occupied by an old woman with glasses. There are also two couch-like benches\n"+
"here facing one another, with a table in between with magazines on it. There is a \n"+
"doorway to the south, a small hallway to the north, and of course the door through\n"+
"which you entered to the east.\n";
items =
({
"magazines",
"Scattered about on the table are some National Geographic, People,\n"+
"and Time magazines",
"desk",
"The receptionist's desk has but a few random post-its and a computer",
"benches",
"The benches are padded but still somewhat uncomfortable. Between\n"+
"them is a table with magazines scattered about on it",
"doorway",
"The door has a plaque on it",
"plaque",
"The office of\n"+
""+HIR+"Principal Descheq"+NORM+"",
});
dest_dir =
({
"/players/chip/room/hdgmd/schools/elem/lobby.c",     "out",
"/players/chip/room/hdgmd/schools/elem/officehall.c",     "north",
});
}
init(){
::init();
add_action("enter","enter");
}
enter(str){
if(!str){ write("Enter what?\n"); return 1; }
if(str != "door"){ write("You may only enter the door.\n"); return 1; }
this_player()->move_player("into the principal's office#/players/chip/room/hdgmd/schools/elem/proffice.c");
return 1;
}
