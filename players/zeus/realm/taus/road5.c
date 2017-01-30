inherit "room/room";
#include "/players/zeus/closed/all.h"    /* road5 */
#include "/players/zeus/closed/fl_demon.h"

int teleport;

reset(arg){

	teleport = 0;  if(random(TFL_TLP)) teleport = 1;

  if(arg) return;
  short_desc="The Fallen Lands";
  long_desc=
"The path is clearly defined here as it winds through the thick forest.\n"+
"Up above the branches of the trees cross over the path, making only\n"+
"small patches of the sky visible.  A few leaves are scatted across the\n"+
"path here and there.  The path leads to the north and to the west.\n";
  set_light(1);
  items=({
	"path",
"The path is rather wide and very clearly defined.  It is also very\n"+
"uneven, as there are many small holes and bumps in it",
	"holes",
"The holes and bumps in the path make it extremely uneven",
    "bumps",
"Small mounds of dirt in the path make it very uneven",
	"forest",
"The forest is very thick here, making it hard to see very far into it",
	"trees",
"The forest consists primarily of evergreen and maple trees which\n"+
"tower high above your head.  Their branches cross over the path,\n"+
"blocking out a good portion of the sky",
	"branches",
"The branches criss-cross over the path, blocking out much of the sky",
    "sky",
"The blue sky is for the most part hidden through the trees",
    "leaves",
"Some brown leaves are scatted across the path, hiding the numerous\n"+
"irregularities and making it even more difficult to walk on",
  });
  dest_dir=({
"/players/zeus/realm/taus/road6.c", "north",
"/players/zeus/realm/taus/road2.c", "west",
 });
}

init(){
  ::init();
  add_action("n_dir", "north");
  add_action("w_dir", "west");
}

exit(){    if(this_player()) this_player()->clear_fight_area();   }
okay_follow(){ return 1; }
realm(){   if(teleport) return "NT";    }
