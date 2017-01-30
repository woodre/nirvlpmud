/*Vale hidden mountain area near NPC's, safe campsite for explorers */

#if 0 /* Rumplemintz */
#include "/sys/lib.h"
#include "/sys/ansi.h"
#endif

inherit "/room/room";
reset(arg)  {   
  if(arg) return; 
  set_light(1);
  short_desc = "Vale";
  long_desc = 
"The Vale of Sorrows. A hidden place that once housed elves fleeing \n\
orcish warbands. Few remember those darker days but it is a safe    \n\
campsite with its ancient trees blocking much of the rain. Fallen   \n\
branches are gathered near the edge in a pile and are mostly dry.   \n\
The valley is not very deep and rests just below rocky outcroppings \n\
of Hisbenth, Arwenaow, and Crechilosy the Sister peaks of old days. \n\
Plenty of vegetation grows with the plentiful rains and it is said  \n\
on some spring days the vale fills with apple blossoms. Wild lilac  \n\
bushes are also in abundance mixed through the heavey undergrowth.  \n";
  items=({		/*Remember two deep on noun descriptions*/
    "vale","A long narrow valley sheltered between several mountains",
	"trees","Trees of indeterminable age and of various species",
    "branches","Dead limbs that seem to have been gathered purposely",
	"pile","It would almost appear these branches were gathered for firewood",
	"outcroppings","Large juts of rock from the sides of the Sisters",
	"hisbenth","Largest of the sisters, it is to the northwest",
	"arwenaow","Middle sister, favored in tales, it is to the east",
	"crechilosy","Youngest, wild sister, its to the western edge",
    "sisters","Name of the three mountains that surround the vale",
    "vegetation","Lots of trees, ferns, flowers and vines",
    "apple trees","Buds are evident on the trees but none have opened yet",
    "undergrowth","Lots of dense ferns, bushes, and small trees",
    "bushes","Dense thorn bushes grown unkempt around some of the trees",
    "prints","Shallow and carefully brushed away, they are about man sized",
    "lilac","Pretty white and purple flowers that grown on large bushes"
  });

  dest_dir = ({
    "/players/wren/Area/coastline/mountain","south", 
  }); 
  /* Commented out by Sparrow 9/14/06
  set_chance(5);       
  add_msg("Song birds chitter from their hidden nests as the rain drips down \n");
  add_msg("The scent of lilac drifts across the vale on the breeze \n");
  add_msg("Thunder rumbles up in the mountain peaks \n");
  add_msg("A twig cracks and a deer leaps away further into the valley \n");
  */
  add_listen("main","Birds chirping and rain dripping through the canopy ");
  add_listen("birds","Singing birds sitting in their nests waiting the rains end ");
  add_listen("rain","A few large drops make it through and splash onto the ground cover");
  add_smell("main","Lilac covers any other scents in the area");
  add_smell("lilac","A pleasant scent that is calming on the nerves ");
  /* Commented out by Sparrow 9/14/06
  add_exit_msg("south","With some luck you locate the hidden door and exit the vale.\n",
    "disappears into the undergrowth\n");
  */
}

init() {
  ::init();
  add_action("search_room","search");
  add_action("enter","enter");
}

search_room()  {
  write("You discover some concealed prints 'enter'ing the undergrowth. \n");
  say(this_player()->query_name() +" searches the area. \n");
  return 1;
}

enter(str) {
  if (!str) {
    write ("Enter what?\n"); 
    return 1;
  } 
  if (str != "undergrowth") return 0;
  write("Parting the bushes reveals a carefully made campsite. \n"+
     "Carefully stepping through you move to investigate.\n");
  this_player()->move_player("disappears into the undergrowth#players/wren/Area/coastline/campsite.c");
  tell_object(this_player(),"The undergrowth springs up concealing the rest of the vale.\n");
  return 1;
}
