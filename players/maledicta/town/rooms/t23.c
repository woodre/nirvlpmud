#include "/players/maledicta/ansi.h"

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define guard8 "/players/maledicta/town/mobs/guard8.c"
inherit "room/room";

reset(arg) {
if(!find_object(guard8)){
move_object(guard8, this_object());
}		
  if(arg) return;
set_light(1);

short_desc = ""+HIG+"Derellia IV"+NORM+"";
long_desc =
"  You stand in the northeast corner of the park. Here the path leads\n"+
"to the south and west, circling the woodland area. You see another\n"+
"small trail that leads down to a large stone crypt, seemingly out of\n"+
"place in this small peaceful forest. And yet, after first spotting it\n"+
"you realize it is more at home here than even the trees themselves,\n"+
"something driving your mind to that conclusion. The trees here grow\n"+
"strong and tall, the breeze carrying through their leaves like a\n"+
"light whisper.\n";

items = ({
  "gate",
  "Made of steel, its surface is polished with care and shines brightly. Perhaps\n"+
  "you could enter it, if you felt you had a reason",	
  "carvings",
  "You look closely and see several representations depicted. The ones that\n"+
  "most grab your attention are that of the battles won. And yet, after\n"+
  "careful examination you see other deeds, even more glorious, those of\n"+
  "wisdom and self sacrifice, patience and excellence. You get a strange\n"+
  "feeling of pride just looking at the depictions, and yet, you cannot\n"+
  "tell why",	
  
  "path",
  "A small brick path that leads in a circle around the park",
  "trail",
  "Well worn, it is made only of dirt",
  "crypt",
  "Looking closer, you see that the crypt is made of beautiful white\n"+
  "stone, polished to a high sheen. Carvings can be seen even from\n"+
  "here, covering most of its visible side, and above its iron barred\n"+
  "doorway. You feel a sense of peace when you look at this place.\n",
  "trees",
  "Standing tall, they are very healthy and larger than the rest of\n"+
  "the trees in the area",
  
  
});

dest_dir = ({
  "/players/maledicta/town/rooms/t24.c","trail",
  "/players/maledicta/town/rooms/t21.c","south",
  "/players/maledicta/town/rooms/t22.c","west",
});

}
init(){
  ::init();
  this_player()->set_fight_area();
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }
	