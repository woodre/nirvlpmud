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
short_desc = ""+HIK+"A Dark Closet"+NORM+"";
long_desc =
"You have found yourself inside the dark closet in Principal Descheq's office. There\n"+
"are a few boxes stacked on the floor on the left, a stack of books on the right, and\n"+
"hung up across the hanger bar there are many cheap, tacky looking jackets, all large\n"+
"in size and smell like moth balls. In the back of the closet it is too dark to see \n"+
"anything, but you can hear the faint sound of labored breathing.\n";
items =
({
"books",
"Phone books, 'For Dummies' manuals of different kinds, and a few educational guides",
"boxes",
"All the boxes are empty",
"jackets",
"Tacky, smelly, old fogey coats. Something like Earwax might wear",
"back",
"It is too dark to see. Perhaps if you reach back and feel around in the\n"+
"darkness, you might find something",
});
dest_dir =
({
"/players/chip/room/hdgmd/schools/elem/proffice.c",     "out",
});
}
void init(){::init();add_action("cmd_search", "search");}
status cmd_search(string str){
if(!str){
write("Search what?\n");
return 1;
}
if(str == "darkness"){
write("You find a young boy hidden in the back of the closet.\n");
move_object(clone_object("/players/chip/mobs/hdgmd/schools/elem/closetchild.c"), this_object());
return 1;
}
}
