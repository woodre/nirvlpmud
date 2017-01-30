inherit"/room/room";
#include <ansi.h>
 
reset(arg)
{
::reset(arg);
if(!present("arnold", this_object()))move_object(clone_object("/players/wicket/tv/looney/mobs/arnold.c"), this_object());
if(arg)return;
  set_light(1);
  set_short(HIC+"Tiny "+HIW+"Toon "+HIC+"Adventures "+NORM+"Entrance");
  set_long(
"A small opening entering into Tiny Toon Adventures. A small cartoon \n"+
"looking town is in view. Laughter and the sound of birds along with other \n"+
"animals echo through the air. Houses with small sidewalks are inhabited with\n"+
/* Changed the above to Houses with small instead of Houses and small */
/* --Rumplemintz */
"all kinds of cartoons and living creatures. The sun beams down warming up the\n"+
"town as the breeze softly blows cooling down the hot place.\n");
  items = 
  ({
    "houses",
    "Small cartoon houses inhabited by living cartoons",
    "sidewalks",
    "Small sidewalks with tracks from animals all over it",
    "grass",
    "Tall soft grass that seems to tug in the gentle wind",
    "fields",
    "Small fields that just seem to never end",
  });
    dest_dir=({
	"/players/wicket/tv/looney/rooms/toonroad1.c",	"north",
	"/players/wicket/tv/looney/rooms/wackyland.c",  "portal",
	"/players/wicket/wicketentrance.c",  "out",
	});

  }
