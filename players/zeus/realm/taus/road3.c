inherit "room/room";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport, searched;

reset(arg){

	teleport = 0;  if(random(TFL_TLP)) teleport = 1;
	searched = 0;   /*  They haven't searched yet   */

  if(arg) return;
  short_desc="The Fallen Lands";
  long_desc=
"The path slopes down at this point.  There are trees and plants all\n"+
"around the path, making it very hard to see what is in the forest.\n"+
"Large footprints can be seen hardened into the dry path.  Only tiny\n"+
"slivers of blue sky are visible through the canopy of branches above.\n";
  set_light(1);
  items=({
   "path",
"The path is dry here, and quite uneven because there are many old\n"+
"footprints dried into it.  There are relatively few leaves and branches\n"+
"scattered across it",
   "leaves",
"There are only a couple leaves on the path here, most of which are torn\n"+
"and damaged",
   "branches",
"The branches above are creating a canopy which blocks out most of the blue\n"+
"sky.  There are relatively few branches on the path",
   "trees",
"The ancient evergreen trees tower high into the sky, their branches\n"+
"blocking out the sky.  They make deviance from the path almost impossible",
   "plants",
"There are many plants growing around the trees here.  They grow very\n"+
"well considering how little light actually reaches the forest floor",
   "forest",
"The forest is made up mostly of thick evergreen trees and the dense\n"+
"undergrowth which does so well here, despite the lack of light",
   "undergrowth",
"The undergrowth consists mainly of full, leafy bushes, dark green ferns,\n"+
"and thick, snakelike vines",
   "vines",
"Thick, dark green vines are visible all around the path.  Many are\n"+
"wrapped around the branches of the trees and hang down from above",
   "bushes",
"The full bushes which grow around the trees help to make the forest\n"+
"seem like a wall, and the path the only way to go.  Strangely enough\n"+
"however they look somewhat irregular to the southwest",
   "ferns",
"The dark green ferns are actually quite beautiful.  Many of them are\n"+
"in perfect condition, delicatly protecting the secrets of the forest",
   "footprints",
"Many large footprints can be clearly seen hardened into the path.  They\n"+
"make it quite uneven to walk on",
   "sky",
"The soft blue sky is very hard to see through the branches above",
   "canopy",
"The branches of the evergreen trees criss cross, making a thick canopy\n"+
"that blocks out most of the sky",
  });
  dest_dir=({
"/players/zeus/realm/taus/road4.c", "north",
"/players/zeus/realm/taus/road2.c", "southeast",
  });
}

int searched(){  return searched(); }

void init(){
	::init();
  add_action("n_dir", "n");
  add_action("se_dir", "se");
  add_action("sw_dir", "sw");
  add_action("sw_dir2", "sw");
  add_action("search_cmd", "search");
}

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow(){ return 1; }
realm(){   if(teleport) return "NT";    }


status search_cmd(string str)
{
 if(str=="plants" || str=="ferns" || str=="bushes" || str=="undergrowth")
 {
	 if(TP->query_attrib("int") < 19)
	 {
		 write("You feel as though something should be here..."+
			   " but you can't find it.\n");
		 say(TP->QN+" gets a confused look on "+TP->POS+" face.\n");
		 return 1;
	 }
	 if(searched == 1)
	 {
		 write("Someone has already uncovered the path to the southwest.\n");
		 return 1;
	 }
	 else
	 {
	 write("You search the "+str+" and uncover a path to the southwest.\n");
	 say(TP->QN+" uncovers a hidden path to the southwest.\n");
     searched = 1;
	 return 1;
	 }
	 return 1;
 }
 else
 {
	 write("You search the area briefly and find nothing of interest.\n");
	 say(TP->QN+" searches around.\n");
	 return 1;
 }
 return 1;
}

status sw_dir2()
{
	if(searched)
	{
		write("You walk into the forest to the southwest...\n");
		TP->MP("into the forest#/players/zeus/realm/taus/hermit1.c");
		return 1;
	}
	else return 0;
	return 1;
}