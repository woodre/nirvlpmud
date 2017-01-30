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
short_desc = ""+HIW+"Principal Descheq's Office"+NORM+"";
long_desc =
"You stand in the office of the infamous, mean Principal Descheq. There is a simple\n"+
"desk, a bookshelf loaded with books of all kinds, and the floor is fully carpeted \n"+
"with plush blue shag carpet. In the far corner there's a closet which is slightly \n"+
"ajar, and something is laying on the ground inside, slightly sticking out through \n"+
"the crack in the door.\n";
items =
({
"closet",
"The closet door is slightly ajar. Perhaps you could 'enter' it",
"desk",
"This is just a simple desk, with a few papers scattered about on it",
"bookshelf",
"There are books and large binders of all kinds set in the shelves",
"carpet",
"Blue shag carpet. It makes the floor very soft under your feet",
"books",
"Books of all kinds are neatly places in the bookshelf",
});
dest_dir =
({
"/players/chip/room/hdgmd/schools/elem/office.c",     "leave",
});
}
init(){
::init();
add_action("enter","enter");
}
enter(str){
if(!str){ write("Enter what?\n"); return 1; }
if(str != "closet"){ write("You may only enter the closet.\n"); return 1; }
this_player()->move_player("ducks into the closet#/players/chip/room/hdgmd/schools/elem/princloset.c");
return 1;
}
