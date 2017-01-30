#include "/players/maledicta/ansi.h"

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = ""+HIG+"Derellia IV"+NORM+"";
long_desc =
"  This is a small path that leads up to the huge structure that stands\n"+
"in the center of town.  Lining the path are numerous statues made of\n"+
"white polished stone, several trees stand between them, giving a sense\n"+
"nature and order to this area. Ahead to the north the path continues\n"+
"to the doorstep of the giant structure. To the south can be seen the\n"+
"cities main gate, as well as the road that encircles the town.\n";

items = ({
  "path",
  "Made of carefully laid stone, it is clean and carefully kept",
  "structure",
  "Standing this close to it, you feel dwarfed by its magnificence and\n"+
  "beauty. Its surface is made of white stone, reinforced by steel beams\n"+
  "and a glimmering field of energy. A crystalline dome can be seen on\n"+
  "its roof, tall battlements circling it. Several glass windows glimmer\n"+
  "in the light from its sides",
  "statues",
  "Each statue is almost lifelike in its workmanship, lending the area a\n"+
  "feeling of warmth and protection. Plaques can be found at the base of\n"+
  "each statue",
  "plaques",
  "Made of a dark steel, each reads the name of the person, birth and\n"+
  "death date, as well as strange words like: Jedi, Jedi Master, and\n"+
  "the such",
  "trees",
  "Standing like vigilant guards, these trees are healthy and trimmed\n"+
  "neatly.",
  "doorstep",
  "Several long steps lead up to it, a huge oak door barring entrance",
  "gate",
  "Made of solid steel, it is part of the towns defense from intruders",
  "road",
  "Well-kept and expertly made, the road is made of stone and is well used", 
});

dest_dir = ({
  "/players/maledicta/town/rooms/t5.c","north",
  "/players/maledicta/town/rooms/t1.c","south"
});

}
init(){
  ::init();
  this_player()->set_fight_area();
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }
	