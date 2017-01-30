inherit"/room/room";
#include <ansi.h>
 
reset(arg)
{
::reset(arg);
if(!present("fifi", this_object()))move_object(clone_object("/players/wicket/tv/looney/mobs/fifi.c"), this_object());
if(!present("babs", this_object()))move_object(clone_object("/players/wicket/tv/looney/mobs/babs.c"), this_object());
if(arg)return;
  set_light(1);
  short_desc = "A Small "+GRN+"Field "+NORM+"of "+HIM+"Fl"+HIR+"ow"+HIY+"er"+HIC+"s"+NORM;
  long_desc = " A enormous field of radiant flowers and soft green grass. The wind\n\
  blows ever so slightly as the warm sun glows. Wild flowers of all kinds\n\
  can be seen all over the place, the grass softly sways as the wind gently\n\
  kisses it. The sweet fragrance of the flowers just rides the wind filling\n\
  the field with a fresh aroma. Butterflies and bees fly all around, the birds\n\
  chirp filling the air with their songs as they flutter about with grace.\n";
  items = 
  ({
    "birds",
    "Several types of birds that seem to soar around",
    "flowers",
    "Flowers of all types, sizes, colors and smells",
    "grass",
    "Tall soft grass that seems to tug in the gentle wind",
    "butterflies",
    "Small butterflies that flutter around the area glistening in the sun",
    "field",
    "A massive green field of soft grass that has flowers that grow wild on the ground",
    "bees",
    "Small bumble bees flying around the flowers buzzing away",
    "butterflies",
    "Small butterflies of all shapes and colors fluttering around in the wind",
  });
   dest_dir=({
  "/players/wicket/tv/looney/rooms/busterden.c","down",
  "/players/wicket/tv/looney/rooms/toonroad1.c","west",
  });
  }