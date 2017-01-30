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
short_desc = ""+HIW+"The Kitchen"+NORM+"";
long_desc =
"Here is where the massive quantity of food that is served in the cafeteria is cooked.\n"+
"There are several industrial sized ovens, quite a few fryers, and a row of industrial\n"+
"powered microwaves. Along the north wall there are many racks holding all the basic\n"+
"neccessities for cooking the foods the children love so much to eat. The air here has\n"+
"a very strong scent of nutritious food being cooked fresh. There seems to also be a\n"+
"faint smell of dishwater coming from a sink nearby in the northeast corner of the\n"+
"kitchen. You are feeling hungry just knowing the food being cooked is so good.\n";
add_smell("air", "Mmmm...the hungering smell of the food is intense here in the kitchen");
add_smell("sink", "The scent of dishsoap and slightly stagnant water almost makes you ill");
items =
({
"ovens",
"These are used for the majority of the cooking. They are all\n"+
"very warm to stand near and emanate the scents of what they cook",
"fryers",
"The smell of hot vegetable oil and fried foods come from these\n"+
"fryers which are use, obviously, to cook the fries and other such\n"+
"fried foods",
"microwaves",
"These are what the frozen foods are defrosted in before cooking them",
"racks",
"Many pots, pans, cooking trays and other random utensils are stored here",
"neccessities",
"Just your basic pots, pans, cooking trays, and other cooking utensils",
"sink",
"Dishes are washed in this triple-compartment sink after they are used.\n"+
"There is something shiny in the bottom of it",
"water",
"It is mixed with dishsoap and is currently very stagnant",
});
dest_dir =
({
"/players/chip/room/hdgmd/schools/elem/cafeteria.c",     "exit",
});
}
void init(){::init();add_action("cmd_search", "search");}
status cmd_search(string str){
if(!str){
write("Search what?\n");
return 1;
}
if(str == "water"){
write("You find a kitchen knife in the sink.\n");
move_object(clone_object("/players/chip/weps/kitchen_knife.c"), this_object());
return 1;
}
}
