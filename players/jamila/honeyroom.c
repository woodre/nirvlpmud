#include "/players/jamila/ansi.h"
#define tp this_player()
inherit "/players/vertebraker/closed/std/room.c";


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "The Honeyroom";
long_desc =
"  A beautifully lavish room that smells of fresh cedar\n"+
"with a faint of flowers.  To one side is a large fire\n"+
"place with a small fire that crackles quietly, flickering\n"+
"light all over the room.  Directly across from the fire is\n"+
"a large bed with oak posts that rise high into the air with\n"+
"a beautiful canopy hanging down.  Next to the bed is a\n"+
"small nightstand that holds a candle that glows softly.\n"+
"On the floor before the fireplace is a large fur carpet\n"+
"that looks very soft and inviting.  Next to the carpet is\n"+
"a bottle of wine and a couple of crystal glasses.  Suddenly\n"+
"you understand this room and its purpose.\n";

add_listen("main", "You the faint sounds of the fire crackling.");
add_smell("main", "It smells of cedar in a garden of wildflowers.");

items = ({
  "bed",
  "The canopy covers most of the bed to hide the ones inside.",
  "canopy", 
  "Looking past the canopy you notice the sheets turned down.",
  "fire",
  "A couple logs with bits of orange flickering over them.",
  "carpet",
  "Warm and cozy looking, it invites you to lay down.",
  "wine",
  "A dusty bottle of red wine, someone has been saving this.",
  "glasses",
  "Two beautiful crystal glasses shimmering in the light.",
    });

dest_dir = ({
  "/players/jamila/workroom.c","air",
  });
{

}

}

