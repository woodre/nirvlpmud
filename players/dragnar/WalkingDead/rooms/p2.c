inherit "/players/earwax/housing/land.c";
inherit "players/dragnar/WalkingDead/rooms/WalkingDeadRM";
#include <ansi.h>
#include "../defs.h"

status rope_cut;

reset(arg) {
	string trees;
  if(arg) return;
  
  short_desc = "Path in King County "+HIG+"Forest"+NORM;
  trees = 
"Around the clearing the trees are mostly evergreen pines that grow\n\
densely together. Scattered in with the pines are some leafy trees\n\
like walnut and maple";
  rope_cut = 0;
 
  set_light(1);
  items=({
    "path",
"Barely large enough for a man to pass through, it is dark and\n\
restricted with the forest so close.",
    "trees", trees,
    "canopy", trees,
    "forest",
"The trees grow more and more dense further to the south. The forest\n\
continues all along the edge of the clearing as far as you can see.\n\
No traversable path in any direction can be seen except the path west",
    "clearing", 
"Mostly grass grows in the clearing, except for a medium sized pine\n\
tree. The forest looms around the clearing and blocks any exit other\n\
than the path back to the west",
    "tent", 
"A green and white Coleman Montana tent. It looks like it was\n\
designed to sleep 6 people, however it would be just big enough\n\
for 2 people with all of the gear required to live in it. It is\n\
still secured to the ground but the rainfly has been ripped off.\n\
Even the WeatherTec weather system couldn't keep the inside dry in\n\
this state. Whoever stayed in here didn't have anything worth taking",
    "pines",GRN+"Darker "+NORM+"varieties of pine grow in this part of the forest",
    "rocks","Oblong "+GRY+"rocks"+NORM+" of various sizes used for the fire pit",
    "grass","Long prickly blades of grass that stick to your clothing",
    "fire pit", 
"Hastily made with a few rocks thrown into a circle, it looks like it\n\
has been at least a week since a fire burned in it",
    "camp", "A basic setup with a tent and a firepit",
  });
  dest_dir=({
    "/players/dragnar/WalkingDead/rooms/p1","west",
  });
  long_desc=
"The path widens into a clearing here that allows some additional\n\
light in. Someone has setup the clearing into a camp site. There is a\n\
fire pit in the middle of the clearing and a tent is erected on the\n\
edge of the clearing near the forest edge. The camp seems complete;\n\
however there doesn't seem to be anyone present.\n";
  
  set_realm_name("Walking Dead");
  set_cost(150000);
  set_lot_size(999);
  setup_land();
}

init() {
	::init();
  add_action("Look","l");
  add_action("Look","look");
  add_action("Look","examine");
  add_action("Look","exa");
  add_action("Cut","cut");
}

Look( string str ) {
  
  if( !str )
    return 0;

  if( str == "tree" || str == "at tree" ) {
    write(
"A medium sized pine tree with the lower branches cut off. There\n\
are blood stains all over the lower trunk of the tree and the\n\
ground. A rope hangs down from a thick branch around 10 feet high.\n");
    if( rope_cut ) 
      write( 
"The rope has been cut around 2 feet from the branch and sways\n\
gently in the breeze.\n");
    else {
      write(
"Shockingly, a man dangles from the rope in the tree, at least he\n\
used to be a man. It looks like the camper decided to kill himself\n\
by hanging from the rope. Unfortunately for him, he turned into a\n\
Walker after he died. However, in the time before he turned Walkers\n\
must have found him because the meat from his feet and legs that the\n\
Walkers could reach are stripped down to the bone.\n\n");
      write(
"You can either cut him down and put him out of his misery, or leave\n\
him be to continue to suffer for his stupidity.\n");
    }
    call_out("sound_effect", 10 + random(5) );
    return 1;
  }
  if( str == "rope" || str == "at rope" ) {
    if( rope_cut )
      write("A thick braided fibre rope a half inch thick dangles from a branch\n\
of the pine tree. It has been cut around 2 feet from where it is\n\
attached to the branch.\n");
    else
      write("A thick braided fibre rope a half inch thick dangles from a branch\n\
of the pine tree. The man that was camping in this clearing swings\n\
from the rope with a noose around his neck. Apparently he did not\n\
handle the end of the world very well and decided to end it all.\n");
    return 1;
  }
  if( str == "man" || str == "camper" ) {
    if( !rope_cut )
      write("What a disgusting mess this guy is. The Walkers could only reach\n\
as high as they get could their mouths and all of the flesh they\n\
could get to has been torn away. It must have been a single walker\n\
or only a small mob because they did not pull him down. Still "+RED+"blood\n\
and gore"+NORM+" is spilled all over the ground and the smell is enough\n\
to make it hurt to breathe.\n");
  }
  
  return 0;
}

Cut( string str ) {
  object walker;
  if( !str )
    return 0;
  if( str == "rope" || str == "down man" ) {
    if( !rope_cut++ ) {
      walker = clone_object("/players/dragnar/WalkingDead/mons/walker");
      walker->set_walker_level( WALKER_START );
      walker->set_short( "A Walking Dead Camper" );
      walker->add_walker_id( "camper" );
      walker->add_walker_id( "man" );
      move_object( walker, this_object() );
      
      write("You cut the rope and the man tumbles to the ground.\n");
      say( this_player()->query_name()+" cuts the rope and the man tumbles to the ground.\n");

      walker->attacked_by( this_player() );
      remove_call_out("sound_effect");
      return 1;
    }
    else {
      write("The rope has already been cut.\n");
      return 1;
    }
  }
  return 0;
}

sound_effect() {
  if( rope_cut ) 
    return;
  
  switch( random(5) ) {
    case 0:
      tell_room(this_object(), "A blood curdling snarl is emitted across the clearing from the tree.\n");
      break;
    case 1:
      tell_room(this_object(), "The rope creaks as it twists around.\n");
      break;
    case 2:
      tell_room(this_object(), "The camper snaps his jaws together trying to reach you.\n");
      break;
    case 3:
      tell_room(this_object(), "The camper groans and it makes gooseflesh break out on your neck.\n");
      break;
    default:
      tell_room(this_object(), "A feeling of being watched overwhelms you.\n");
      break;
  }
  
  call_out("sound_effect", 10 + random(5) );
}
