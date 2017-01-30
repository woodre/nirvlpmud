/* Campsite, not a bad place to put Cormorant my trader */

#if 0 /* Rumplemintz */
#include "/sys/lib.h"
#include "/sys/ansi.h"
#endif

inherit "/room/room";
reset(arg)  {   
  if(arg) return; 
  if(!present("cormorant")){
    move_object(clone_object("/players/wren/Area/forest1/specials/cormorant"), this_object()); 
  }
  set_light(1);
  short_desc = "Campsite ";
  long_desc = 
    "A clearing has been taken over for a campsite by some woodsman.\n"+
    "A small tent is pitched between two maples with firewood stacked\n"+
    "neatly against the one. A fire crackles in a carefully tended\n"+
    "stone pit with a pot of water boiling on it. The storm can barely\n"+
    "be discerned through the canopy but for the occasional drops and\n"+
    "the gentle rumble of the distant thunder. It's likely the tenant\n"+
    "is near. Hopefully he doesn't mind a guest at his fire.\n";
  items=({		/*Remember two deep on noun descriptions*/
    "clearing","Large enough to accomodate the campsite yet small enough to keep weather off",
	"campsite","Neatly arranged provisions of a woodsman",
    "tent","Simple canvas held up with a stout rope and a couple smaller guide ropes",
	"maples","The peak of the tent is tied between these two trees",
	"firewood","Pile of brush and sticks gathered from the valley floor",
	"fire","Crackling nicely in the pit, feels amazing after being soaked",
	"pit","Depression in the ground dug to prevent the fire spreading",
	"stone","Some large rocks arranged on the rim of the pit",
    "pot","Iron kettle for food preperation",
    "water","Bubbling swiftly with the steady heat",
    "drops","A few rain drops manange to trickle through the canopy",
    "crates","Closed and sealed boxes belonging to Cormorant",
    "undergrowth","Bushes and small trees",
    "provisions","His supplies",
    "rope","Stout nylon blend for superior knots with light weight",
    "canvas","Treated to be weatherproof the space below is dry",
    "boxes","Stamped 'Cormorant's, Hands Off' you take the advice"
  });

  dest_dir = ({
    "/players/wren/Area/coastline/vale","back",
  }); 
 
  /* Commented out by Sparrow 9/13/2006
  set_chance(5);       
  add_msg("A few drips trickle from the leaves above to land in the leaves below \n");
  add_msg("Soft grumble of thunder echos into the valley and fades away \n");
  add_msg("The fire crackles and pops \n");
  add_msg("Whisps of smoke drift up and dissipate \n");
  */
  add_listen("main","The fire crackles, the kettle boils, and rain drips gently from above ");
  add_listen("fire","The fire crackles and burns quietly in its mesmerizing way ");
  add_listen("rain","Drops quietly work their way down from leaf to leaf ");
  add_smell("main","Wood smoke, rain, damp fur, and  ");
  add_smell("smoke","Smells like pine and hickory");
  add_smell("fur","The smell is near but of uncertain type");
  add_touch("fire","You warm your hands over the flames");
  /*Commented out by Sparrow 9/13/06
    add_exit_msg("back","Carefully parting the plants you leave the camp.\n",
    "disappears into the undergrowth\n");
  */
}

init() {
  ::init();
  add_action("search_room","search");
}

search_room()  {
  write("Searching the area you find some crates concealed in the brush.\n");
  say (this_player()->query_name() +" searches the area. \n");
  return 1; 
}
