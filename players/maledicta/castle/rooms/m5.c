#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "the gates of "+HIG+"Derellia IV"+NORM+"";
long_desc =
"  Here lies the small town of Derellia IV. It's buildings are surrounded by\n"+
"a protective wall of steel, which shimmers with the power of a great energy\n"+
"barrier. Small turrets line the walls, mounted on small towers. A tall white\n"+
"building stands in the center of the town, easily visible from anywhere in\n"+
"the valley. A huge gate stands before you. A path leads from the gate and\n"+
"back towards the mountains to the south.\n";

items = ({
"buildings",
"From what little you can tell from here, you see that the buildings are of\n"+
"modern look, white washed, and partially made from steel and fine stone",
"wall",
"Made from steel, it is about 20 feet tall, and shimmers with the power of a\n"+
"protective field of energy. It would seem the town is ready to take on any\n"+
"assault",
"barrier",
"It seems to be extremely powerful, and capable of taking a great deal of damage",
"turrets",
"Looking carefully you see several small and large laser turrets. Each of\n"+
"them powerful enough to stop nearly any assault",
"towers",
"The towers are made of steel and protected by the same field that surrounds\n"+
"the walls",
"building",
"You look to the center of town and see a huge building which towers over\n"+
"the rest of the town like a giant among men. It almost seems out of place\n"+
"and yet, it fits this place perfectly. Its walls are white washed and\n"+
"reinforced with huge steel beams. At the top of it are numerous battlements\n"+
"and several flags. Numerous windows dot the structure along its entire\n"+
"length, each covered with multi-colored panes of glass. This building\n"+
"radiates a feeling of pride",
"gate",
"A huge gate of steel, perhaps you could enter it?",
"path",
"A well worn path that leads into the mountains",
"mountains",
"The mountains, even from this distance, are huge and awe-inspiring" 
  });

dest_dir = ({
  "/players/maledicta/castle/rooms/m3.c","south",
  });
}

init(){
   ::init();
   
   add_action("gate_enter", "enter");
}

gate_enter(string str){
	if(!str){ write("enter what?\n"); return 1; }
	if(str == "gate"){

		write("The gates swing wide, allowing you entrance.\n");
		move_object(this_player(), "/players/maledicta/town/rooms/t1.c");
		tell_room(environment(tp), tpn+" arrives.\n", ({tp}));
		command("look", this_player());
		write("\n\n\n"+HIR+"      BEWARE, YOU HAVE ENTERED A PLAYER-KILLING AREA."+NORM+"\n\n\n");
		return 1;
	      }
	write("enter what?\n");
	return 1;
   }	
