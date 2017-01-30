#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
        if(!present("templar_mess", this_object())){
move_object(clone_object("players/jaraxle/templar/mobs/templar_mess"), this_object());
        }
  if(arg) return;
set_light(1);
short_desc = HIW+"A small room ["+NORM+GRN+"Fortress Stone"+HIW+"]"+NORM+"";
long_desc =
"  The small room adjacent to the Feast Hall holds a large, round oak\n"+
"table with seven chairs. Mugs of ale and a few plates of food are set\n"+
"out on the table currently, and a stone fireplace has a fire burning\n"+
"quietly within the back wall. A chart is tacked up on the wall near\n"+
"the door back to the main hall.\n";
items = ({
"table","A massive oak table, carved well and recently used for a meal",
"chart",""+HIB+"   -*"+HIW+" Squire Advancement"+HIB+" *-\n"+
""+HIW+"Level             Exp Requirement"+NORM+"\n"+
"  1                      0\n"+
"  2                      1500\n"+
"  3                      2000\n"+
"  4                      3000\n"+
"  5                      6000\n"+
"  6                      15000\n"+
"  7                      30000\n"+
"  8                      40000\n"+
"  9                      60000\n"+
"  10                     90000\n",
});

dest_dir = ({
"/players/jaraxle/closed/templar/squires/feast_hall.c","south",
});

}

 init(){
        ::init();
/*
this_player()->set_fight_area();
*/
}
exit(){    if(this_player()) this_player()->clear_fight_area();     }

