inherit "room/room";

#include <ansi.h>

void init(){
    ::init();
    add_action("enter", "enter");
}

int enter(string str){
    if(!str) return 0;
    if(str=="castle" || str=="mouth"){
	write("The castle is almost open, try back tommorrow.\n");
	return 1;
    }
}

void reset(int arg){
    if(arg) return;
    short_desc = "Entrance hall to Lord Bane's castle";
    long_desc = ""+
    "A large skull shaped castle looms in the forefront. An eerie "+RED+"red"+NORM+" glow shines\n"+
    "out through two openings on the upper level of the castle. The sky appears\n"+
    "dark and gloomy, and fungus appears to be growing on everything.\n";
    set_light(1);
    dest_dir = ({
      "players/rumplemintz/room/bane/room11", "northwest",
    });
    items = ({
      ({"castle","skull"}),"It is skull shaped, and has cavities where eyes and a mouth should be",
      ({"eyes","openings"}), "They emminate an eerie "+RED+"red"+NORM+" glow",
      "fungus", "It grows on everything, the air is very humid here",
      "sky", "It is dark and gloomy.",
      "mouth", "The mouth cavity appears to be the entrance to the castle."
    });
}
