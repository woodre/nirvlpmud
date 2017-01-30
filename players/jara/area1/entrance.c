/* Entrance Room, Created <5/16/00> by Jara */

#include "/players/jara/misc/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="The Throne Room- Ruins";
  long_desc=
    "  The once grand throne room stands in ruins. The thickly woven carpet\n"+
    "has faded to a pale white, and the adornments have been removed from\n"+
    "the thrones. The paintings that graced the walls are now slashed, and\n"+
    "a "+HIW+"mirror"+NORM+" has fallen from the wall. The stained glass window behind the\n"+
    "thrones has been shattered, and a few small shards of glass remain in\n"+ 
    "the frame.\n";
  items=({
    "fabric",
    "The fabric of the thrones has retained a velvet texture, but the\n"+
    "color has faded to a pale red",
    "seat",
    "The seats of the thrones are well padded by the thick fabric",
    "fields",
    "The fields beyond the ruins are overgrown with thickets of weeds and\n"+
    "wild flowers",
    "flowers",
    "The delicate wild flowers are a deep violet in color",
    "weeds",
    "The dark green, leafy weeds are thick within the underbrush of the\n"+
    "fields beyond the ruins",
    "thickets",
    "Thick patches of weeds and wild flowers are visible through the window",
    "adornments",
    "The adornments of the thrones are missing, leaving behind small, gaping\n"+
    "holes",
    "holes",
    "The small holes on the arms of the thrones have been crudely damaged\n"+
    "from the removal of the adornments",
    "walls",
    "The stone walls are well worn, and several of the bricks are chipped\n"+
    "or damaged",
    "bricks",
    "The bricks are grey in color, chipped, and well worn",
    "frame",
    "The frame of the window is approximately six feet wide by six feet\n"+
    "high and is directly behind the thrones in the wall of the ruins",
    "carpet",
    "The pale white carpet has faded and the edges are worn",
    "thrones",
    "The thrones stand side by side, thick fabric padding the seat and\n"+
    "backs. The adornments of gold have been removed, leaving gaping\n"+
    "holes behind",
    "paintings",
    "The oil paintings are slashed and damaged",
    "mirror",
    "An oval mirror with an elaborate oak frame. The glass has remained\n"+
    "intact, and an"+HIW+" image "+NORM+"is visible within",
    "image",
    "The mirror seems to fade around the border, but the reflection within\n"+
    "shows a small, seaside boardwalk. You could"+HIW+" touch"+NORM+" the"+HIW+" reflection"+NORM,
    "window",
    "A large window, broken now. The fields outside the castle ruins are\n"+
    "visible",
    "shards",
    "The window has been shattered into small shards of colored glass",
    "glass",
    "The glass from the window is a deep red and white in color" });
  dest_dir=({ 
    "/room/south/sforst11.c","leave" });
}

init() {
  ::init();

  add_action("mirror_touch","touch");
}

mirror_touch(str) {
  if(!str) {
    notify_fail("What do you want to touch?\n");
  return 0;
  }
    if(str == "reflection") {
    write("You place your hand on the reflection in the mirror...\n"+
    "You have been pulled into the mirror!\n");
    say(this_player()->query_name()+" touches the mirror and vanishes!\n");
    this_player()->move_player("into the mirror#players/jara/area1/docks/room/wrhs3");
  return 1;
  }
  else {
    notify_fail("What do you want to touch?\n");
  return 0;
  }
}
