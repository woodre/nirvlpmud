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
"  You stand before a beautifully crafted crypt. Its stone walls polished\n"+
"to a high sheen and reflecting the light. Wonderous carvings show scenes\n"+
"of deeds done, and evil conquered. Surrounding the crypt are numerous\n"+
"plants and bright flowers, each growing tall and healthy. A steel gate\n"+
"blocks entry into the crypt, its surface shining and polished. The trail\n"+
"leads back to the main path.\n";

items = ({
  "crypt",
  "You look closely at this wonderous creation and see that its design is\n"+
  "that of an expert craftsman, with hours of love and hard toil worked\n"+
  "into its being",
  "walls",
  "Polished to a smooth and clean surface, you can almost see yourself in\n"+
  "the stone",
  "carvings",
  "You look closely and see several representations depicted. The ones that\n"+
  "most grab your attention are that of the battles won. And yet, after\n"+
  "careful examination you see other deeds, even more glorious, those of\n"+
  "wisdom and self sacrifice, patience and excellence. You get a strange\n"+
  "feeling of pride just looking at the depictions, and yet, you cannot\n"+
  "tell why",
  "plants",
  "Growing healthy and strong, you are impressed by their size",
  "flowers",
  "Bright and beautiful, they have grown tall and healthy",
  "gate",
  "Made of steel, its surface is polished with care and shines brightly. Perhaps\n"+
  "you could enter it, if you felt you had a reason",
  "trail",
  "A small dirt path leading away from the crypt",
  "path",
  "The brick path that encircles the park",
  
});

dest_dir = ({
  "/players/maledicta/town/rooms/t23.c","trail",
});

}

init(){
  ::init();
  add_action("enter_it", "enter");
  this_player()->set_fight_area();
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }
	

enter_it(string str){
	if(!str){ write("Enter what?\n"); return 1; }
	if(str = "gate"){
		write(
"You begin to reach for the gate and suddenly feel a wave of unexplainable\n"+
"emotion sweep over you. You shake your head and step away from the gate,\n"+
"your hands shaking slightly.\n");
return 1; }
	return 0;
	}