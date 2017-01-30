#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
#include "/players/maledicta/ansi.h"
object dragon;
object dragon2;
object mother;

reset(arg) {
if(!present("cont_dragon", this_object())){
dragon = clone_object("/players/maledicta/cont/dragon/mobs/bdragon2.c");
	move_object(dragon, this_object());
dragon2 = clone_object("/players/maledicta/cont/dragon/mobs/bdragon2.c");
	move_object(dragon2, this_object()); }
if(!present("cont_mother", this_object())){
mother = clone_object("/players/maledicta/cont/dragon/mobs/gmother.c");
	move_object(mother, this_object());
}
		
  if(arg) return;
set_light(1);

short_desc = ""+BOLD+"The "+HIB+"Dragons"+NORM+BOLD+" Cave"+NORM+"";
long_desc =
"  You have entered the Hatchery. This huge room is filled from\n"+
"wall to wall with small bluish speckled eggs, all carefully\n"+
"arranged. The heat here is bearable, and yet leaves you feeling\n"+
"uncomfortable. A huge archway to the west leads out to the sub-\n"+
"chamber.\n";

items = ({
  "walls",
  "The walls here are very smooth to the touch, but also\n"+
  "very warm",
  "archway",
  "A large round archway which leads to the west",
  "eggs",
  "Large eggs that have blue specks on their surface. This is\n"+
  "the future of the Blue Dragons. You might be able to 'Smash'\n"+
  "them if you were cruel enough",
});

dest_dir = ({
  "/players/maledicta/cont/dragon/rooms/cave7.c","west",
});

}

init(){
::init();
add_action("smash_them","smash");

}


smash_them(str){
if(!str){
write("Smash what?\n");
return 1;
}
if(str == "eggs" || str == "egg"){
write("You smash the blue speckled eggs and seal the fate of the Blue Dragons!\n");
say(this_player()->query_name()+" smashes the eggs!\n");
long_desc = 
"  You have entered the Hatchery. This huge room is filled from\n"+
"wall to wall with crushed eggs, all of which have been visciously\n"+
"destroyed. The heat here is bearable, and yet leaves you feeling\n"+
"uncomfortable. A huge archway to the west leads out to the sub-\n"+
"chamber.\n";
items = ({
  "walls",
  "The walls here are very smooth to the touch, but also\n"+
  "very warm",
  "archway",
  "A large round archway which leads to the west",
  "eggs",
  "The scattered shells of the once beautiful eggs of the Blue\n"+
  "Dragons. A thick yolk oozes out onto the ground surrounding\n"+
  "each. The Blue Dragons future is now gone forever",
});
this_player()->add_exp(2500);
return 1;
}
write("Smash what?\n");
return 1;
}